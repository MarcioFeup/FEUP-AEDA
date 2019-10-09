#include <iostream>
#include <vector>
#include "exception.h"

using namespace std;

template<class N, class A>
class Edge;

template<class N, class A>
class Vertex {

  public:
	N info;
	vector<Edge<N, A>> edges;

	Vertex(N info) : info(info) {}

	bool hasEdge(Edge<N, A> edge) {
		for (Edge<N, A> e : edges)
			if (e == edge)
				return true;
		return false;
	}

	void addEdge(Edge<N, A> edge) {
		if (hasEdge(edge))
			throw RepeatedEdgeException();

		edges.push_back(edge);
	}

	bool operator==(Vertex vertex) {
		return this->info == vertex.info;
	}
};

template<class N, class A>
class Edge {

  public:
	A value;
	Vertex<N, A> *destination;

	Edge(Vertex<N, A> *dest, A val) : value(val), destination(dest) {}

	bool operator==(Edge<N, A> edge) const {
		return this->value == edge.value && *this->destination == *edge.destination;
	}
};

template<class N, class A>
class Graph {

  public:
	Graph() = default;

	~Graph() {
		for (Vertex<N, A> *vertex: vertexes) {
			delete (vertex);
			vertexes.clear();
		}
	}

	A &getEdgeValue(const N &from, const N &to);

	Graph &addVertex(const N &info) {
		auto *vertex = new Vertex<N, A>(info);

		if (foundVertex(vertexes, *vertex))
			throw RepeatedVertexException<N>(info);

		this->vertexes.push_back(vertex);
		return *this;
	}

	Graph &addEdge(const N &from, const N &to, const A &val) {
		Edge<N, A> edge(to, val);

		Vertex<N, A> *vertex = getVertex(from);
		vertex->
	}

	Graph &removeEdge(const N &from, const N &to);

	int qtdEdges() const {
		int qtd = 0;

		for (Vertex<N, A> *vertex: vertexes)
			qtd += vertex->edges.size();

		return qtd;
	}

	bool hasVertex(Vertex<N, A> vertex) {
		for (Vertex<N, A> *v : vertexes)
			if (*v == vertex)
				return true;

		return false;
	}

	Vertex<N, A> *getVertex(N info) {
		Vertex<N, A> tmp(info);

		for (Vertex<N, A> *vertex :vertexes)
			if (*vertex == tmp)
				return vertex;

		throw NonExistentVertexException<N>(info);
	}

	int qtdVertexes() const {
		return vertexes.size();
	}

	void print(std::ostream &os) const;

  private:
	vector<Vertex<N, A> *> vertexes;
};

template<class N, class A>
std::ostream &operator<<(std::ostream &out, const Graph<N, A> &g);