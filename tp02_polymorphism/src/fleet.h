#ifndef FLEET_H_
#define FLEET_H_

#include <vector>
#include "vehicle.h"

using namespace std;

class Fleet {

	vector<Vehicle *> vehicles;

  public:
	void addVehicle(Vehicle *v1);

	int qtdVehicles() const;

	int getOlderCar() const;

	float totalTaxes() const;

	vector<Vehicle *> operator()(int year) const;

	friend ostream &operator<<(ostream &o, const Fleet &f);
};

#endif /*FLEET_H_*/
