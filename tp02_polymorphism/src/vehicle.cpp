#include "vehicle.h"
#include "config.h"
#include <iostream>
#include <utility>

using namespace std;

Vehicle::Vehicle(string brand, int month, int year) : brand(std::move(brand)), month(month), year(year) {}

int Vehicle::info() const {
	cout << "brand: " << brand << endl <<
		 "month: " << month << endl <<
		 "year: " << year << endl;

	return 3;
}

bool Vehicle::operator<(const Vehicle &vehicle) const {
	return (this->year == vehicle.year) ? this->month < vehicle.month : this->year < vehicle.year;
}

int Vehicle::getYear() const {
	return year;
}

string Vehicle::getBrand() const {
	return brand;
}

Motorized::Motorized(string brand, int month, int year, string fuel, int dis) : Vehicle(std::move(brand), month, year),
																				fuelType(std::move(fuel)),
																				displacement(dis) {}

float Motorized::calcTax() const {
	return config::calcTax(fuelType, displacement, year);
}

int Motorized::info() const {
	int n = Vehicle::info();

	cout << "fuel type: " << fuelType << endl <<
		 "displacement: " << displacement << endl;

	return n + 2;
}

string Motorized::getFuelType() const {
	return fuelType;
}

Car::Car(string brand, int month, int year, string fuelType, int displacement) : Motorized(std::move(brand), month,
																						   year, std::move(fuelType),
																						   displacement) {}

int Car::info() const {
	return Motorized::info();
}

Truck::Truck(string brand, int month, int year, string fuelType, int displacement, int ml) : Motorized(std::move(brand),
																									   month, year,
																									   std::move(
																											   fuelType),
																									   displacement),
																							 maxLoad(ml) {}

int Truck::info() const {
	int n = Motorized::info();

	cout << "max load: " << maxLoad << endl;
	return n + 1;
}

Bicycle::Bicycle(string brand, int month, int year, string t) : Vehicle(std::move(brand), month, year),
																type(std::move(t)) {}

float Bicycle::calcTax() const {
	return 0; // no fuel.
}

int Bicycle::info() const {
	int n = Vehicle::info();

	cout << "type: " << type << endl;
	return n + 1;
}
