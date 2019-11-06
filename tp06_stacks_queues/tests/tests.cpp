#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "../src/util/stack_ext.h"
#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>
#include "performance.h"
#include "../src/model/client.h"
#include "../src/model/desk.h"


using testing::Eq;


TEST(test_1, StackExt_FindMin){
    StackExt<int> s1;
    // Teste ao empty()
    EXPECT_EQ(true, s1.empty());
    // Teste ao push() e top()
    s1.push(6);
    s1.push(4);
    s1.push(7);
    s1.push(2);
    s1.push(5);
    EXPECT_EQ(5, s1.top());
    // Teste ao pop() e top()
    s1.pop();
    s1.pop();
    EXPECT_EQ(7, s1.top());

    // Testar findMin()
    EXPECT_EQ(4, s1.findMin());
    s1.push(3);
    s1.push(2);
    EXPECT_EQ(2, s1.findMin());

    // Agora testar findMin() para saber se executa em tempo constante
    // preparar Stack removendo todos os elementos
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    EXPECT_EQ(true, s1.empty());

    // preparar dados para teste TEMPO EXECUCAO
    int size = 9;
    unsigned int elapsedTime[size];
    int x_el[] = {5000000,6000000,7000000,8000000,9000000,10000000,11000000,12000000,13000000};
    int random_int;
    ticks tstart;
    ticks tend;

    for (int i = 0; i < size; i++) {
        // encher stack com numero de elementos indicados pelo x_el
        for (int z = 1; z <= x_el[i]; z++) {
            random_int = rand() % 1000 + 1;
            s1.push(random_int);
        }
        // agora contar tempo invocando o metodo
        tstart = getticks(); // inicio contagem ticks
        s1.findMin(); // este ee constante
        tend = getticks(); // fim da contagem ticks
        // colocar valor no array de elapsedTime
        elapsedTime[i] = getElapsed(tend,tstart);
        // retirar da stack os numeros la colocados
        for (int z = 1; z <= x_el[i]; z++) {
            s1.pop();
        }
    }
    // Verifica se executa em TEMPO CONSTANTE
    // NOTA: o parametro com valor 10 significa que sao considerados constantes valores no intervalo [-10, 10]
    EXPECT_EQ(true, isConstant(elapsedTime, size, 10));
}

TEST(test_2, a_ConstructorCliente){
    srand(time(NULL));
    Client c;
    EXPECT_TRUE((c.getQtGifts()>0 && c.getQtGifts()<=5));
}

TEST(test_2, b_ConstructorDesk){
    srand(time(nullptr));
    Desk b;
    EXPECT_EQ(0, b.getAttendedClients());
    EXPECT_EQ(2, b.getBundleTime());
    EXPECT_EQ(0, b.getTimeManager().getCurrentTime());
    EXPECT_TRUE((b.getTimeManager().getNextArrival()>0 && b.getTimeManager().getNextArrival() <= 20));
    EXPECT_EQ(0, b.getTimeUntilLeaves());
    EXPECT_THROW(b.getNextClient(), EmptyQueueException);
    try {
        b.getNextClient();
    }
    catch (EmptyQueueException &e) {
        cout << "Apanhou excecao. EmptyQueueExceptionException: " << e.getMessage() << endl;
        EXPECT_EQ("The queue is empty", e.getMessage());
    }
}

TEST(test_2, c_ChegadaDesk){
    Desk b;
    cout << "Este teste nao falha. Verifique se na consola aparece (x varia entre 1 e 5): Time = 0\nArrived new client with x gifts." << endl;

	b.arrive();
    // Agora que se invocou o metodo arrive, verifica se fez corretamente alguns dos requisitos
    EXPECT_EQ(0, b.getTimeManager().getCurrentTime());
    EXPECT_TRUE((b.getNextClient().getQtGifts()>0 && b.getNextClient().getQtGifts()<=5));
    EXPECT_TRUE((b.getTimeManager().getNextArrival()>0 && b.getTimeManager().getNextArrival() <= 20));
    EXPECT_TRUE((b.getTimeUntilLeaves()>=2 && b.getTimeUntilLeaves() <= 10)); // entre [0+1*2, 0+5*2]
}

TEST(test_2, d_SaidaDesk){
    Desk b;
    // Simula a arrive de um cliente
	b.arrive();
	b.arrive();

    b.leave();
    // Agora que se invocou o metodo leave, verifica se fez corretamente alguns dos requisitos
    EXPECT_EQ(0, b.getTimeManager().getCurrentTime());
    EXPECT_TRUE((b.getTimeUntilLeaves()>=2 && b.getTimeUntilLeaves() <= 10)); // entre [0+1*2, 0+5*2]
    b.leave();
    try {
        b.getNextClient();
    }
    catch (EmptyQueueException &e) {
        cout << "Apanhou excecao. EmptyQueueException: " << e.getMessage() << endl;
        EXPECT_EQ("The queue is empty", e.getMessage());
    }
}

TEST(test_2, e_ProximoEvento){
	srand(time(nullptr));
    cout << "Este teste nao falha. Verifique na consola os valores." << endl;
    EXPECT_TRUE(true);
    Desk b;
    b.next();
    cout << "01: " << "Clientes atendidos: " << b.getAttendedClients() << " Tempo actual: " << b.getTimeManager().getCurrentTime() << " Prox arrival: " << b.getTimeManager().getNextArrival() << " Prox Saida: " << b.getTimeUntilLeaves() << endl;
    b.next();
    cout << "02: " << "Clientes atendidos: " << b.getAttendedClients() << " Tempo actual: " << b.getTimeManager().getCurrentTime() << " Prox arrival: " << b.getTimeManager().getNextArrival() << " Prox Saida: " << b.getTimeUntilLeaves() << endl;
    b.next();
    cout << "03: " << "Clientes atendidos: " << b.getAttendedClients() << " Tempo actual: " << b.getTimeManager().getCurrentTime() << " Prox arrival: " << b.getTimeManager().getNextArrival() << " Prox Saida: " << b.getTimeUntilLeaves() << endl;
    b.next();
    cout << "04: " << "Clientes atendidos: " << b.getAttendedClients() << " Tempo actual: " << b.getTimeManager().getCurrentTime() << " Prox arrival: " << b.getTimeManager().getNextArrival() << " Prox Saida: " << b.getTimeUntilLeaves() << endl;
}

TEST(test_2, f_Operador){
    cout << "Este teste nao falha. Verifique na consola os valores." << endl;
    EXPECT_TRUE(true);
    Desk b;
    b.next();
    b.next();
    b.next();
    b.next();
    cout << b << endl;
}