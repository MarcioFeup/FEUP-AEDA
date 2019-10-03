#include "fleet.h"
#include <string>

using namespace std;

void Fleet::addVehicle(Vehicle *v1) {
	this->vehicles.push_back(v1);
}

int Fleet::qtdVehicles() const {
	return this->vehicles.size();
}

int Fleet::getOlderCar() const {
	if (qtdVehicles() < 1)
		return 0;

	int year = vehicles[0]->getYear();
	for (int i = 1; i < qtdVehicles(); ++i)
		if (vehicles[i]->getYear() < year)
			year = vehicles[i]->getYear();

	return year;
}

float Fleet::totalTaxes() const {
	float total = 0;

	for (auto vehicle : vehicles)
		total += vehicle->calcTax();

	return total;
}

vector<Vehicle *> Fleet::operator()(int year) const {
	vector<Vehicle *> res;

	for (Vehicle *v : vehicles)
		if (v->getYear() == year)
			res.push_back(v);

	return res;
}

ostream &operator<<(ostream &o, const Fleet &f) {
	for (auto vehicle : f.vehicles)
		vehicle->info();

	return o;
}

