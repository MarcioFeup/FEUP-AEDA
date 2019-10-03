#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/fleet.h"
#include <string>



using testing::Eq;

TEST(test_1, a_CriarVeiculos) {
    Car a1("Fiat", 5, 2017, "gasoline", 1200);
    Truck c1("Ford", 3, 2016, "gasoline", 1400, 1000);
    Car a2("Renault", 9, 2017, "diesel", 1300);
    Bicycle b1("XX", 4, 2018, "AllTerrain");
    ASSERT_EQ("gasoline", c1.getFuelType());
    ASSERT_EQ("Fiat", a1.getBrand());
    ASSERT_EQ("Ford", c1.getBrand());
}

TEST(test_1, b_CriarFrota){
   	Fleet f;
    ASSERT_EQ(0, f.qtdVehicles());
    ASSERT_EQ(0, f.getOlderCar());
    Vehicle *v1 =new Car("Fiat", 5, 1997, "gasoline", 1200);
    Vehicle *v2= new Truck("Ford", 3, 1999, "gasoline", 1400, 1000);
    Vehicle *v3=new Car("Renault", 9, 1997, "diesel", 1300);
    Vehicle *v4=new Bicycle("XX", 4, 2002, "AllTerrain");
	f.addVehicle(v1);
	f.addVehicle(v2);
	f.addVehicle(v3);
	f.addVehicle(v4);
    ASSERT_EQ(4, f.qtdVehicles());
    ASSERT_EQ(1997, f.getOlderCar());
}

TEST(test_1, c_InfoVeiculo){
   	Car a1("Fiat", 5, 1997, "gasoline", 1200);
    Truck c1("Ford", 3, 1999, "gasoline", 1400, 1000);
    Bicycle b1("XX", 4, 2002, "AllTerrain");
    ASSERT_EQ(5, a1.info());
    ASSERT_EQ(6,c1.info());
    ASSERT_EQ(4,b1.info());
}

TEST(test_1, d_InfoFrota){
    Vehicle *v1 =new Car("Fiat", 5, 2016, "gasoline", 1200);
    Vehicle *v2= new Truck("Ford", 3, 2017, "gasoline", 1400, 1000);
    Vehicle *v3=new Bicycle("XX", 4, 2018, "AllTerrain");
    Fleet f;
	f.addVehicle(v1);
	f.addVehicle(v2);
	f.addVehicle(v3);
    ASSERT_TRUE(true);
    cout << "This test never fails! Verify output." << endl;
    cout << f;
}

TEST(test_1, e_OperadorMenor) {
   	Car a1("Fiat", 3, 2017, "gasoline", 1200);
    Truck c1("Ford", 5, 2017, "gasoline", 1400, 1000);
    Bicycle b1("XX", 4, 2018, "AllTerrain");
    ASSERT_EQ(true, a1<c1);
    ASSERT_EQ(false,b1<c1);
    ASSERT_EQ(true,a1<b1);
}

TEST(test_1, f_OperadorFuncao) {
   	Fleet f;
    Vehicle *v1 =new Car("Fiat", 5, 2016, "gasoline", 1200);
    Vehicle *v2= new Truck("Ford", 3, 2017, "gasoline", 1400, 1000);
    Vehicle *v3=new Car("Renault", 9, 2016, "diesel", 1300);
    Vehicle *v4=new Car("Renault", 9, 2010, "diesel", 1300);
    Vehicle *v5=new Bicycle("XX", 4, 2018, "AllTerrain");
	f.addVehicle(v1);
	f.addVehicle(v2);
	f.addVehicle(v3);
	f.addVehicle(v4);
	f.addVehicle(v5);
    ASSERT_EQ(5, f.qtdVehicles());
    vector<Vehicle*> v;
    v = f(2016);
    ASSERT_EQ(2, v.size());
    v = f(2015);
    ASSERT_EQ(0, v.size());
    v = f(2010);
    ASSERT_EQ(1, v.size());
    ASSERT_EQ("Renault", v[0]->getBrand());
}

TEST(test_1, g_ImpostoVeiculo) {
	Car a1("Fiat", 5, 1997, "gasoline", 1200);
    Truck c1("Ford", 3, 1999, "gasoline", 1400, 1000);
    Bicycle b1("XX", 4, 2002, "AllTerrain");
    ASSERT_NEAR(29.06, a1.calcTax(), 0.001);
    ASSERT_NEAR(45.15, c1.calcTax(), 0.001);
    ASSERT_NEAR(0, b1.calcTax(), 0.001);
}

TEST(test_1, h_ImpostoFrota) {
    Vehicle *v1 =new Car("Fiat", 5, 1997, "gasoline", 1200);
    Vehicle *v2= new Truck("Ford", 3, 1999, "gasoline", 1400, 1000);
    Vehicle *v3=new Bicycle("XX", 4, 2002, "AllTerrain");
    Fleet f;
	f.addVehicle(v1);
	f.addVehicle(v2);
	f.addVehicle(v3);
    ASSERT_NEAR(74.21, f.totalTaxes(), 0.001);
}