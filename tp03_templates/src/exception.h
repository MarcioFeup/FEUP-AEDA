#ifndef AEDA1920_FP03_EXCEPTION_H
#define AEDA1920_FP03_EXCEPTION_H


#include <iosfwd>
#include <iostream>

// excecao RepeatedVertexException
template<class N>
class RepeatedVertexException {

  public:
	N info;

	RepeatedVertexException(N inf) : info(inf) {}
};

template<class N>
std::ostream &operator<<(std::ostream &out, const RepeatedVertexException<N> &no) {
	out << "Repeated vertex: " << no.info;
	return out;
}


// excecao NonExistentVertexException
template<class N>
class NonExistentVertexException {

  public:
	N info;

	NonExistentVertexException(N inf) : info(inf) {}
};

template<class N>
std::ostream &operator<<(std::ostream &out, const NonExistentVertexException<N> &ni) {
	out << "Non existent vertex: " << ni.info;
	return out;
}

template <class N>
class RepeatedEdgeException {

  private:
	N *from, *to;

  public:
	RepeatedEdgeException(N *from, N *to) : from(from), to(to) {}

	friend std::ostream &operator<<(std::ostream &out, const RepeatedEdgeException<N> &exception);
};

template <class N>
std::ostream &operator<<(std::ostream &out, const RepeatedEdgeException<N> &exception) {
	out << "Edge from " << exception.from->info << " to " << exception.to->info << std::endl;
	return out;
}

#endif //AEDA1920_FP03_EXCEPTION_H
