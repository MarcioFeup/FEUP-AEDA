#include <iostream>
#include <vector>
#include "exception.h"

using namespace std;

template<class N, class A>
class Edge;

/**
 * Represents a vertex of a graph.
 *
 * @tparam N the information it holds
 * @tparam A the weight of the edges
 * @author Márcio Duarte
 */
template<class N, class A>
class Vertex {

  public:

	/**
	 * The information the vertex holds.
	 */
	N info;

	/**
	 * The collection of edges that raise from the vertex.
	 */
	vector<Edge<N, A>> edges;

	/**
	 * Creates a new vertex given its information.
	 * @param info the vertex information
	 */
	Vertex(N info) : info(info) {}

	/**
	 * Verifies if the vertex has an edge.
	 * @param edge the edge
	 * @return true if the vertex has the edge, false otherwise
	 */
	bool hasEdge(Edge<N, A> edge) {
		for (Edge<N, A> e : edges)
			if (e.destination == edge.destination)
				return true;
		return false;
	}

	/**
	 * Adds an edge to the vertex.
	 * @param edge the edge
	 */
	void addEdge(Edge<N, A> edge) {
		if (hasEdge(edge))
			throw RepeatedEdgeException<N>(info, edge.destination->info);

		edges.push_back(edge);
	}

	/**
	 * Gets a pointer to an edge given its destination.
	 * @param dst the destination
	 * @return the pointer to the edge
	 */
	Edge<N, A> *getEdge(N dst) const {
		for (Edge<N, A> &edge : edges)
			if (edge.destination->info == dst)
				return edge;
		throw NonExistentEdgeException<N>(info, dst);
	}

	/**
	 * Gets the index to the vector of edges of a given edge, given its destination.
	 * @param dst the destination
	 * @return the correspondent index
	 */
	int getEdgeIndex(N dst) const {
		for (int i = 0; i < edges.size(); ++i)
			if (edges[i].destination->info == dst)
				return i;

		throw NonExistentEdgeException<N>(info, dst);
	}

	/**
	 * Compares to vertexes.
	 * @param vertex the other vertex
	 * @return true if they are equal, false otherwise
	 */
	bool operator==(Vertex vertex) {
		return this->info == vertex.info;
	}
};

/**
 * An edge represents a connection between two vertexes
 * @tparam N the information the vertex holds
 * @tparam A the weight of the edge
 * @author Márcio Duarte
 */
template<class N, class A>
class Edge {

  public:

	/**
	 * The weight of the edge.
	 */
	A value;

	/**
	 * The destination of the edge.
	 */
	Vertex<N, A> *destination;

	/**
	 * Constructs an edge, given its destinatinon and weight.
	 * @param dest the destination
	 * @param val the weight
	 */
	Edge(Vertex<N, A> *dest, A val) : value(val), destination(dest) {}

	/**
	 * Compares with another edge.
	 * @param edge the another edge
	 * @return true if they are equal, false otherwise
	 */
	bool operator==(Edge<N, A> edge) const {
		return this->value == edge.value && *this->destination == *edge.destination;
	}
};

/**
 * A graph holds information through vertexes connected by edges.
 * @tparam N the type of information of the vertexes
 * @tparam A the type of information of the edges
 * @author Márcio Duarte
 */
template<class N, class A>
class Graph {

  public:

	/**
	 * Constructs a new graph, by default.
	 */
	Graph() = default;

	/**
	 * Destructs the graph, clearing all its memory.
	 */
	~Graph() {
		for (Vertex<N, A> *vertex: vertexes) {
			delete (vertex);
			vertexes.clear();
		}
	}

	/**
	 * Gets a reference of the value of an edge, given its source and destiny.
	 * @param from the info of the source
	 * @param to the info of the destiny
	 * @return the reference of the value
	 */
	A &getEdgeValue(const N &from, const N &to) {
		Vertex<N, A> *src = nullptr, *dst = nullptr;

		for (Vertex<N, A> *vertex : vertexes) {
			if (vertex->info == from) {
				src = vertex;
				break;
			}
		}

		if (src == nullptr)
			throw NonExistentVertexException<N>(from);

		for (Edge<N, A> &edge : src->edges)
			if (edge.destination->info == to)
				return edge.value;

		// if an edge is not found.
		throw NonExistentEdgeException<N>(from, to);
	}

	/**
	 * Adds a vertex to the graph.
	 * @param info the info of the vertex
	 * @return the new graph
	 */
	Graph &addVertex(const N &info) {
		auto *vertex = new Vertex<N, A>(info);

		if (this->hasVertex(*vertex))
			throw RepeatedVertexException<N>(info);

		this->vertexes.push_back(vertex);
		return *this;
	}

	/**
	 * Adds an edge to the graph.
	 * @param from the source of the edge
	 * @param to the destiny of the edge
	 * @param val the weight of the edge
	 * @return the new graph
	 */
	Graph &addEdge(const N &from, const N &to, const A &val) {
		Vertex<N, A> *src = nullptr, *dst = nullptr;

		try {
			src = getVertex(from);
			dst = getVertex(to);
		} catch (NonExistentVertexException<N> &e) {
			throw e;
		}

		Edge<N, A> edge(dst, val);

		try {
			src->addEdge(edge);
		} catch (RepeatedEdgeException<N> &e) {
			throw e;
		}

		return *this;
	}

	/**
	 * Removes an edge from the graph.
	 * @param from the source of the edge
	 * @param to the destiny of the edge
	 * @return the new graph
	 */
	Graph &removeEdge(const N &from, const N &to) {
		Vertex<N, A> *src = nullptr;
		int index;

		try {
			src = getVertex(from);
			index = src->getEdgeIndex(to);
		} catch (NonExistentVertexException<N> &e) {
			throw e;
		} catch (NonExistentEdgeException<N> &e) {
			throw e;
		}

		src->edges.erase(src->edges.begin() + index);
		return *this;
	}

	/**
	 * Verifies if the graph has a vertex.
	 * @param vertex the vertex to veify
	 * @return true if the graph has the vertex, false otherwise
	 */
	bool hasVertex(Vertex<N, A> vertex) {
		for (Vertex<N, A> *v : vertexes)
			if (*v == vertex)
				return true;

		return false;
	}

	/**
	 * Gets the quantity of edges.
	 * @return the quantity of edges
	 */
	int qtdEdges() const {
		int qtd = 0;

		for (Vertex<N, A> *vertex: vertexes)
			qtd += vertex->edges.size();

		return qtd;
	}

	/**
	 * Gets a vertex given its info.
	 * @param info the info
	 * @return the vertex
	 */
	Vertex<N, A> *getVertex(N info) {
		Vertex<N, A> tmp(info);

		for (Vertex<N, A> *vertex :vertexes)
			if (*vertex == tmp)
				return vertex;

		throw NonExistentVertexException<N>(info);
	}

	/**
	 * Gets the quantity of vertexes.
	 * @return the quantity of vertexes
	 */
	int qtdVertexes() const {
		return vertexes.size();
	}

	/**
	 * Modifies an ostream with information on the graph.
	 * @param os the ostream
	 */
	void print(std::ostream &os) const {
		for (Vertex<N, A> *vertex : vertexes) {
			os << "( " << vertex->info;

			for (Edge<N, A> &edge : vertex->edges) {
				os << "[ " << edge.destination->info << " " << edge.value << "] ";
			}

			os << ") ";
		}
	}

  private:

	/**
	 * The vector of vertexes.
	 */
	vector<Vertex<N, A> *> vertexes;
};

/**
 * Adds information of a graph on an ostream.
 * @tparam N the type of information that vertexes hold
 * @tparam A the type of information the edges hold
 * @param out the ostream
 * @param g the graph
 * @return the ostream
 */
template<class N, class A>
std::ostream &operator<<(std::ostream &out, const Graph<N, A> &g) {
	g.print(out);
	return out;
}