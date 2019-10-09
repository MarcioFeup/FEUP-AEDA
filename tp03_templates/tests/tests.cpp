#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "../src/graph.h"

using testing::Eq;

TEST(test, a_ConstrutorNosArestas) {
	Graph<string, int> g;
	ASSERT_EQ(0, g.qtdVertexes());
	ASSERT_EQ(0, g.qtdEdges());
}

TEST(test, b_addVertex) {
	Graph<string, int> f;
	f.addVertex("A");
	f.addVertex("B");
	f.addVertex("C");
	ASSERT_EQ(3, f.qtdVertexes());

	ASSERT_THROW(f.addVertex("B"), RepeatedVertexException<string>);
	try {
		f.addVertex("B");
	}
	catch (RepeatedVertexException<string> &e) {
		ostringstream ostr;
		ostr << e;
		string str = "Repeated vertex: B";
		ASSERT_EQ(str, ostr.str());
	}
	f.addVertex("D");
	f.addVertex("E");
	ASSERT_EQ(5, f.qtdVertexes());
}

TEST(test, c_addEdge) {
	Graph<string, int> f;
	f.addVertex("A");
	f.addVertex("B");
	f.addVertex("C");
	f.addVertex("D");
	f.addVertex("E");
	f.addEdge("A", "B", 5);
	f.addEdge("A", "C", 8);
	f.addEdge("B", "D", 9);
	f.addEdge("C", "D", 3);
	f.addEdge("C", "E", 4);
	f.addEdge("D", "E", 2);
	f.addEdge("D", "B", 11);
	ASSERT_EQ(7, f.qtdEdges());
	ASSERT_THROW(f.addEdge("D", "B", 12), RepeatedEdgeException<string>);
	try {
		f.addEdge("D", "B", 12);
	} catch (RepeatedEdgeException<string> &e) {
		ostringstream ostr;
		ostr << e;
		string str = "Repeated edge: D, B";
		ASSERT_EQ(str, ostr.str());
	}

	ASSERT_THROW(f.addEdge("F", "B", 11), NonExistentVertexException<string>);
	try {
		f.addEdge("F", "B", 11);
	}
	catch (NonExistentVertexException<string> &e) {
		ostringstream ostr1;
		ostr1 << e;
		string str1 = "Non existent vertex: F";
		ASSERT_EQ(str1, ostr1.str());
	}

	ASSERT_EQ(7, f.qtdEdges());
}

TEST(test, d_getEdgeValue) {
	Graph<string, int> f;
	f.addVertex("A");
	f.addVertex("B");
	f.addVertex("C");
	f.addVertex("D");
	f.addVertex("E");
	f.addEdge("A", "B", 5);
	f.addEdge("A", "C", 8);
	f.addEdge("B", "D", 9);
	f.addEdge("C", "D", 3);
	f.addEdge("C", "E", 4);
	f.addEdge("D", "E", 2);
	f.addEdge("D", "B", 11);
	f.getEdgeValue("A", "B") = 15;
	ASSERT_EQ(15, f.getEdgeValue("A", "B"));
	ASSERT_THROW(f.getEdgeValue("A", "A"), NonExistentEdgeException<string>);
	try {
		f.getEdgeValue("A", "A");
	}
	catch (NonExistentEdgeException<string> &e) {
		//cout << "Apanhou excecao " << e << endl;
		ostringstream ostr;
		ostr << e;
		string str = "Non existent edge: A, A";
		ASSERT_EQ(str, ostr.str());
	}

	ASSERT_THROW(f.getEdgeValue("F", "B"), NonExistentVertexException<string>);
	try {
		f.getEdgeValue("F", "B");
	}
	catch (NonExistentVertexException<string> &e) {
		//cout << "Apanhou excecao " << e << endl;
		ostringstream ostr1;
		ostr1 << e;
		string str1 = "Non existent vertex: F";
		ASSERT_EQ(str1, ostr1.str());
	}
}


TEST(test, e_removeEdge) {
	Graph<string, int> f;
	f.addVertex("A");
	f.addVertex("B");
	f.addVertex("C");
	f.addVertex("D");
	f.addVertex("E");
	f.addEdge("A", "B", 5);
	f.addEdge("A", "C", 8);
	f.addEdge("B", "D", 9);
	f.addEdge("C", "D", 3);
	f.addEdge("C", "E", 4);
	f.addEdge("D", "E", 2);
	f.addEdge("D", "B", 11);
	ASSERT_EQ(7, f.qtdEdges());
	f.removeEdge("D", "E");
	ASSERT_EQ(6, f.qtdEdges());
	ASSERT_THROW(f.removeEdge("D", "A"), NonExistentEdgeException<string>);
	try {
		f.removeEdge("A", "A");
	}
	catch (NonExistentEdgeException<string> &e) {
		//cout << "Apanhou excecao " << e << endl;
		ostringstream ostr;
		ostr << e;
		string str = "Non existent edge: A, A";
		ASSERT_EQ(str, ostr.str());
	}

	ASSERT_THROW(f.removeEdge("F", "B"), NonExistentVertexException<string>);
	try {
		f.removeEdge("F", "B");
	}
	catch (NonExistentVertexException<string> &e) {
		//cout << "Apanhou excecao " << e << endl;
		ostringstream ostr1;
		ostr1 << e;
		string str1 = "Non existent vertex: F";
		ASSERT_EQ(str1, ostr1.str());
	}

	ASSERT_EQ(6, f.qtdEdges());
}

TEST(test, f_ImprimirGraph) {
	Graph<string, int> f;
	f.addVertex("A");
	f.addVertex("B");
	f.addVertex("C");
	f.addVertex("D");
	f.addVertex("E");
	f.addEdge("A", "B", 5);
	f.addEdge("A", "C", 8);
	f.addEdge("B", "D", 9);
	f.addEdge("C", "D", 3);
	f.addEdge("C", "E", 4);
	f.addEdge("D", "E", 2);
	f.addEdge("D", "B", 11);
	ASSERT_EQ(7, f.qtdEdges());
	ostringstream ostr;
	f.print(ostr);
	string str = "( A[ B 5] [ C 8] ) ( B[ D 9] ) ( C[ D 3] [ E 4] ) ( D[ E 2] [ B 11] ) ( E) ";
	cout << str.c_str() << endl;
	ASSERT_EQ(str, ostr.str());
}

TEST(test, g_OperadorSaida) {
	Graph<string, int> f;
	f.addVertex("A");
	f.addVertex("B");
	f.addVertex("C");
	f.addVertex("D");
	f.addVertex("E");
	f.addEdge("A", "B", 5);
	f.addEdge("A", "C", 8);
	f.addEdge("B", "D", 9);
	f.addEdge("C", "D", 3);
	f.addEdge("C", "E", 4);
	f.addEdge("D", "E", 2);
	f.addEdge("D", "B", 11);
	ASSERT_EQ(7, f.qtdEdges());
	ostringstream ostr;
	ostr << f;
	string str = "( A[ B 5] [ C 8] ) ( B[ D 9] ) ( C[ D 3] [ E 4] ) ( D[ E 2] [ B 11] ) ( E) ";
	ASSERT_EQ(str, ostr.str());
}