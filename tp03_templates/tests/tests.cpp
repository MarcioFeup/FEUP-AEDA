#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "../src/graph.h"

using testing::Eq;

TEST(test, a_ConstrutorNosArestas){
   	Graph<string,int> g;
    ASSERT_EQ(0, g.qtdVertexes());
    ASSERT_EQ(0, g.qtdEdges());
}

TEST(test, b_InserirNo){
  	Graph<string,int> f;
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

TEST(test, c_InserirAresta){
  /*  Grafo<string,int> f;
    f.inserirNo("A");
    f.inserirNo("B");
    f.inserirNo("C");
    f.inserirNo("D");
    f.inserirNo("E");
    f.inserirAresta("A", "B", 5);
    f.inserirAresta("A", "C", 8);
    f.inserirAresta("B", "D", 9);
    f.inserirAresta("C", "D", 3);
    f.inserirAresta("C", "E", 4);
    f.inserirAresta("D", "E", 2);
    f.inserirAresta("D", "B", 11);
    ASSERT_EQ(7, f.numArestas());
    ASSERT_THROW(f.inserirAresta("D", "B", 12), ArestaRepetida<string>);
    try {
        f.inserirAresta("D", "B", 12);
    }
    catch (ArestaRepetida<string> &e) {
        ostringstream ostr;
        ostr << e;
        string str = "Edge repetida: D , B";
        ASSERT_EQ(str, ostr.str());
    }

    ASSERT_THROW(f.inserirAresta("F", "B", 11), NonExistentVertexException<string>);
    try {
        f.inserirAresta("F", "B", 11);
    }
    catch (NonExistentVertexException<string> &e) {
        ostringstream ostr1;
        ostr1 << e;
        string str1 = "No inexistente: F";
        ASSERT_EQ(str1, ostr1.str());
    }

    ASSERT_EQ(7, f.qtdEdges());*/
}

TEST(test, d_ValorAresta){
   /* Grafo<string,int> f;
    f.inserirNo("A");
    f.inserirNo("B");
    f.inserirNo("C");
    f.inserirNo("D");
    f.inserirNo("E");
    f.inserirAresta("A", "B", 5);
    f.inserirAresta("A", "C", 8);
    f.inserirAresta("B", "D", 9);
    f.inserirAresta("C", "D", 3);
    f.inserirAresta("C", "E", 4);
    f.inserirAresta("D", "E", 2);
    f.inserirAresta("D", "B", 11);
    f.valorAresta("A", "B") = 15;
    ASSERT_EQ(15, f.valorAresta("A", "B"));
    ASSERT_THROW(f.valorAresta("A", "A"), ArestaInexistente<string>);
    try {
        f.valorAresta("A", "A");
    }
    catch (ArestaInexistente<string> &e) {
        //cout << "Apanhou excecao " << e << endl;
        ostringstream ostr;
        ostr << e;
        string str = "Edge inexistente: A , A";
        ASSERT_EQ(str, ostr.str());
    }

    ASSERT_THROW(f.valorAresta("F", "B"), NonExistentVertexException<string>);
    try {
        f.getEdgeValue("F", "B");
    }
    catch (NonExistentVertexException<string> &e) {
        //cout << "Apanhou excecao " << e << endl;
        ostringstream ostr1;
        ostr1 << e;
        string str1 = "No inexistente: F";
        ASSERT_EQ(str1, ostr1.str());
    }*/
}


TEST(test, e_EliminarAresta){
 /*   Grafo<string,int> f;
    f.inserirNo("A");
    f.inserirNo("B");
    f.inserirNo("C");
    f.inserirNo("D");
    f.inserirNo("E");
    f.inserirAresta("A", "B", 5);
    f.inserirAresta("A", "C", 8);
    f.inserirAresta("B", "D", 9);
    f.inserirAresta("C", "D", 3);
    f.inserirAresta("C", "E", 4);
    f.inserirAresta("D", "E", 2);
    f.inserirAresta("D", "B", 11);
    ASSERT_EQ(7, f.numArestas());
    f.eliminarAresta("D", "E");
    ASSERT_EQ(6, f.numArestas());
    ASSERT_THROW(f.eliminarAresta("D", "A"), ArestaInexistente<string>);
    try {
        f.eliminarAresta("A", "A");
    }
    catch (ArestaInexistente<string> &e) {
        //cout << "Apanhou excecao " << e << endl;
        ostringstream ostr;
        ostr << e;
        string str = "Edge inexistente: A , A";
        ASSERT_EQ(str, ostr.str());
    }

    ASSERT_THROW(f.eliminarAresta("F", "B"), NonExistentVertexException<string>);
    try {
        f.removeEdge("F", "B");
    }
    catch (NonExistentVertexException<string> &e) {
        //cout << "Apanhou excecao " << e << endl;
        ostringstream ostr1;
        ostr1 << e;
        string str1 = "No inexistente: F";
        ASSERT_EQ(str1, ostr1.str());
    }

    ASSERT_EQ(6, f.qtdEdges());*/
}

TEST(test, f_ImprimirGrafo){
   /* Grafo<string,int> f;
    f.inserirNo("A");
    f.inserirNo("B");
    f.inserirNo("C");
    f.inserirNo("D");
    f.inserirNo("E");
    f.inserirAresta("A", "B", 5);
    f.inserirAresta("A", "C", 8);
    f.inserirAresta("B", "D", 9);
    f.inserirAresta("C", "D", 3);
    f.inserirAresta("C", "E", 4);
    f.inserirAresta("D", "E", 2);
    f.inserirAresta("D", "B", 11);
    ASSERT_EQ(7, f.qtdEdges());
    ostringstream ostr;
    f.print(ostr);
    string str = "( A[ B 5] [ C 8] ) ( B[ D 9] ) ( C[ D 3] [ E 4] ) ( D[ E 2] [ B 11] ) ( E) ";
    cout << str.c_str()<<endl;
    ASSERT_EQ(str, ostr.str());*/
}

TEST(test, g_OperadorSaida){
   /* Grafo<string,int> f;
    f.inserirNo("A");
    f.inserirNo("B");
    f.inserirNo("C");
    f.inserirNo("D");
    f.inserirNo("E");
    f.inserirAresta("A", "B", 5);
    f.inserirAresta("A", "C", 8);
    f.inserirAresta("B", "D", 9);
    f.inserirAresta("C", "D", 3);
    f.inserirAresta("C", "E", 4);
    f.inserirAresta("D", "E", 2);
    f.inserirAresta("D", "B", 11);
    ASSERT_EQ(7, f.qtdEdges());
    ostringstream ostr;
    ostr << f;
    string str = "( A[ B 5] [ C 8] ) ( B[ D 9] ) ( C[ D 3] [ E 4] ) ( D[ E 2] [ B 11] ) ( E) ";
    ASSERT_EQ(str, ostr.str());*/
}