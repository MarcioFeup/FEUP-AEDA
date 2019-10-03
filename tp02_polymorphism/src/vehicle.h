#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <string>

using namespace std;

class Vehicle {

  public:
	Vehicle(string brand, int month, int year);

	virtual ~Vehicle() = default;

	virtual float calcTax() const = 0;

	virtual int info() const;

	bool operator<(const Vehicle &vehicle) const;

	int getYear() const;

	string getBrand() const;

  protected:
	string brand;
	int month, year;
};

class Motorized : public Vehicle {

	string fuelType;
	int displacement;

  public:
	Motorized(string brand, int month, int year, string fuel, int dis);

	~Motorized() override = default;

	float calcTax() const override;

	int info() const override;

	string getFuelType() const;
};

class Car : public Motorized {

  public:
	Car(string brand, int month, int year, string fuelType, int displacement);

	~Car() override = default;

	int info() const override;
};


class Truck : public Motorized {

	int maxLoad;

  public:
	Truck(string brand, int month, int year, string fuelType, int displacement, int ml);

	~Truck() override = default;

	int info() const override;
};


class Bicycle : public Vehicle {

	string type;

  public:
	Bicycle(string brand, int month, int year, string t);

	~Bicycle() override = default;

	float calcTax() const override;

	int info() const override;
};


#endif /* VEHICLE_H_ */
