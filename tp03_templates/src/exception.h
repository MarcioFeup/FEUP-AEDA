#ifndef AEDA1920_FP03_EXCEPTION_H
#define AEDA1920_FP03_EXCEPTION_H


#include <iosfwd>
#include <iostream>

/**
 * Represents an exception with vertexes.
 * @tparam N the type of information the vertex holds
 * @author Márcio Duarte
 */
template<class N>
class VertexException {

  public:
	/**
	 * The information the vertex holds.
	 */
	N info;

	/**
	 * Creates a new exception given its info.
	 * @param info the info
	 */
	explicit VertexException(N info) : info(info) {}
};

/**
 * Represents an exception of a repeated vertex.
 * @tparam N the type of information the vertex holds
 * @author Márcio Duarte
 */
template<class N>
class RepeatedVertexException : public VertexException<N> {

  public:

	/**
	 * Constructs a new exception, given the vertex information.
	 * @param info the information
	 */
	explicit RepeatedVertexException(N info) : VertexException<N>(info) {}
};

/**
 * Adds information on an exception in an ostream.
 * @tparam N the type of information the vertex holds
 * @param out the ostream
 * @param no the exception
 * @return the ostream
 */
template<class N>
std::ostream &operator<<(std::ostream &out, const RepeatedVertexException<N> &no) {
	out << "Repeated vertex: " << no.info;
	return out;
}

/**
 * Represents an exception indicative on a non existent vertex.
 * @tparam N the type of information the vertex holds
 * @author Márcio Duarte
 */
template<class N>
class NonExistentVertexException : public VertexException<N> {

  public:

	/**
	 * Constructs a new exception given the vertex information
	 * @param info the vertex information
	 */
	explicit NonExistentVertexException(N info) : VertexException<N>(info) {}
};

/**
 * Adds information of an exception in an ostream.
 * @tparam N the type of information the vertex holds
 * @param out the ostream
 * @param ni the exception
 * @return the ostream
 */
template<class N>
std::ostream &operator<<(std::ostream &out, const NonExistentVertexException<N> &ni) {
	out << "Non existent vertex: " << ni.info;
	return out;
}

/**
 * Represents an exception related with edges.
 * @tparam N the type of information the vertex holds
 * @author Márcio Duarte
 */
template<class N>
class EdgeException {

  public:

	/**
	 * The information on the source vertex.
	 */
	N from;

	/**
	 * The information on the destination vertex.
	 */
	N to;

	/**
	 * Constructs a new exception given the information on the source and destination vertexes.
	 * @param from the information of the source vertex
	 * @param to the information of the destiny vertex
	 */
	EdgeException(N from, N to) : from(from), to(to) {};
};

/**
 * Represents an exception indicative of a repeated edge.
 * @tparam N the type of information the vertex holds
 * @author Márcio Duarte
 */
template<class N>
class RepeatedEdgeException : public EdgeException<N> {

  public:

	/**
	 * Constructs a new exception given the source and destination vertex information.
	 * @param from the source vertex information
	 * @param to the destination vertex information
	 */
	RepeatedEdgeException(N from, N to) : EdgeException<N>(from, to) {};

	/**
	 * Edits an ostream with the information on an exception.
	 * @param out the ostream
	 * @param exception the exception
	 * @return the ostream
	 */
	friend std::ostringstream &operator<<(std::ostringstream &out, const RepeatedEdgeException<N> &exception) {
		out << "Repeated edge: " << exception.from << ", " << exception.to;
		return out;
	}
};

/**
 * Represents an exception indicative of a non existent edge.
 * @tparam N the type of informatio the vertexes holds
 * @author Márcio Duarte
 */
template<class N>
class NonExistentEdgeException : EdgeException<N> {

  public:

	/**
	 * Constructs a new exception given the source and destination vertex information.
	 * @param from the source vertex information
	 * @param to the destination vertex information
	 */
	NonExistentEdgeException(N from, N to) : EdgeException<N>(from, to) {};

	/**
 	* Edits an ostream with the information on an exception.
 	* @param out the ostream
 	* @param exception the exception
 	* @return the ostream
 	*/
	friend std::ostream &operator<<(std::ostream &out, const NonExistentEdgeException<N> &exception) {
		out << "Non existent edge: " << exception.from << ", " << exception.to;
		return out;
	}
};

#endif //AEDA1920_FP03_EXCEPTION_H
