#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/model/parking_lot.h"
#include "../src/exception/non_existent_client.h"
#include "../src/exception/non_existent_position.h"
#include <string>

using testing::Eq;

TEST(test, a_Search){
    ParkingLot p1(10, 20);
	p1.addClient("Joao Santos");
	p1.addClient("Pedro Morais");
	p1.addClient("Rui Silva");
	p1.addClient("Susana Costa");
	p1.addClient("Maria Tavares");
    EXPECT_EQ(0, p1.clientPosition("Joao Santos"));
    EXPECT_EQ(4, p1.clientPosition("Maria Tavares"));
    EXPECT_EQ(1, p1.clientPosition("Pedro Morais"));
    EXPECT_EQ(-1, p1.clientPosition("Tiago Tavares"));
}

TEST(test, b_ParkUsage){
    ParkingLot p1(10,20);
    p1.addClient("Joao Santos");
    p1.addClient("Pedro Morais");
    p1.addClient("Rui Silva");
    p1.addClient("Susana Costa");
    p1.addClient("Maria Tavares");
    p1.enter("Maria Tavares");
    p1.enter("Susana Costa");
    p1.leave("Susana Costa");
    p1.leave("Maria Tavares");
    p1.enter("Maria Tavares");
    p1.leave("Maria Tavares");
    p1.enter("Rui Silva");
    p1.leave("Rui Silva");
    p1.enter("Susana Costa");
    p1.enter("Rui Silva");
    p1.leave("Rui Silva");
    p1.enter("Rui Silva");
    p1.enter("Pedro Morais");
    EXPECT_EQ(3, p1.getFrequency("Rui Silva"));
    EXPECT_EQ(1, p1.getFrequency("Pedro Morais"));
    EXPECT_EQ(0, p1.getFrequency("Joao Santos"));
    EXPECT_THROW(p1.getFrequency("Tiago Silva"), NonExistentClient);
    try {
        p1.getFrequency("Tiago Silva");
    }
    catch (NonExistentClient &e) {
        cout << "Apanhou excecao. Cliente nao existente: " << e.getClientName() << endl;
        EXPECT_EQ("Tiago Silva", e.getClientName());
    }
}

TEST(test, c_SortByFrequency){
    ParkingLot p1(10, 20);
	p1.addClient("Joao Santos");
	p1.addClient("Pedro Morais");
	p1.addClient("Rui Silva");
	p1.addClient("Susana Costa");
	p1.addClient("Maria Tavares");
	p1.enter("Maria Tavares");
	p1.enter("Susana Costa");
	p1.leave("Susana Costa");
	p1.leave("Maria Tavares");
	p1.enter("Maria Tavares");
	p1.leave("Maria Tavares");
	p1.enter("Rui Silva");
	p1.leave("Rui Silva");
	p1.enter("Susana Costa");
	p1.enter("Rui Silva");
	p1.leave("Rui Silva");
	p1.enter("Rui Silva");
	p1.enter("Pedro Morais");

	p1.sortClientsByFrequency();
    Client ic1= p1.getClients()[2];
    EXPECT_EQ("Susana Costa", ic1.getName());
    EXPECT_EQ(2, ic1.getFrequency());
    Client ic2= p1.getClients()[0];
    EXPECT_EQ("Rui Silva", ic2.getName());
    EXPECT_EQ(3, ic2.getFrequency());
}

TEST(test, d_GetByFrequency){
    ParkingLot p1(10, 20);
	p1.addClient("Joao Santos");
	p1.addClient("Pedro Morais");
	p1.addClient("Rui Silva");
	p1.addClient("Susana Costa");
	p1.addClient("Maria Tavares");
	p1.enter("Maria Tavares");
	p1.enter("Susana Costa");
	p1.leave("Susana Costa");
	p1.leave("Maria Tavares");
	p1.enter("Maria Tavares");
	p1.leave("Maria Tavares");
	p1.enter("Rui Silva");
	p1.leave("Rui Silva");
	p1.enter("Susana Costa");
	p1.enter("Rui Silva");
	p1.leave("Rui Silva");
	p1.enter("Rui Silva");
	p1.enter("Pedro Morais");
    vector<string> clients = p1.findClientsByFrequency(2, 3);
    EXPECT_EQ(3, clients.size());
    if (clients.size() == 3) {
        EXPECT_EQ("Rui Silva", clients[0]);
        EXPECT_EQ("Maria Tavares", clients[1]);
        EXPECT_EQ("Susana Costa", clients[2]);
    }
}

TEST(test, e_SortByName){
    ParkingLot p1(10, 20);
	p1.addClient("Joao Santos");
	p1.addClient("Pedro Morais");
	p1.addClient("Rui Silva");
	p1.addClient("Susana Costa");
	p1.addClient("Maria Tavares");
	p1.enter("Maria Tavares");
	p1.enter("Susana Costa");
	p1.leave("Susana Costa");
	p1.leave("Maria Tavares");
	p1.enter("Maria Tavares");
	p1.leave("Maria Tavares");
	p1.enter("Rui Silva");
	p1.leave("Rui Silva");
	p1.enter("Susana Costa");
	p1.enter("Rui Silva");
	p1.leave("Rui Silva");
	p1.enter("Rui Silva");
	p1.enter("Pedro Morais");
	p1.sortClientsByName();
    Client ic1= p1.getClients()[2];
    EXPECT_EQ("Pedro Morais", ic1.getName());
    Client ic2= p1.getClients()[0];
    EXPECT_EQ("Joao Santos", ic2.getName());
}

TEST(test, f_ClientsInfo){
   	ParkingLot p1(10,20);
    p1.addClient("Joao Santos");
    p1.addClient("Pedro Morais");
    p1.addClient("Rui Silva");
    p1.addClient("Susana Costa");
    p1.addClient("Maria Tavares");
    p1.enter("Maria Tavares");
    p1.enter("Susana Costa");
    p1.leave("Susana Costa");
    p1.enter("Rui Silva");
    p1.enter("Susana Costa");
    cout << "This test never fails." << endl;
    cout << p1;
    Client ic=p1.getClientAtPos(2);
    EXPECT_EQ("Rui Silva", ic.getName());
    EXPECT_THROW(p1.getClientAtPos(6), NonExistentPosition);
    try {
        p1.getClientAtPos(6);
    }
    catch (NonExistentPosition &e) {
        cout << "This test never fails." << endl;
        cout << "Caught non existent position exception: " << e.getPosition() << endl;
        EXPECT_EQ(6, e.getPosition());
    }
}
