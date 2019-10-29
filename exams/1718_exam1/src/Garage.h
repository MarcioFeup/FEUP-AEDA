/*
 * Garage.h
 *
 *  Created on: 24/10/2017
 *      Author: hlc
 */

#ifndef SRC_GARAGE_H_
#define SRC_GARAGE_H_

#include <vector>
#include <algorithm>

template <class Vehicle>
class Garage {
	std::vector<Vehicle *> vehicles;
	const unsigned int capacity;
public:
	Garage(int size);
	~Garage();
	std::vector<Vehicle *> getVehicles() const;
	void setVehicles(std::vector<Vehicle *> vehicles);
	int getCapacity() const;
	bool addVehicle(Vehicle *vehicle);
	Vehicle* removeVehicle(std::string brand, std::string model);
	float avgPrice(std::string brand) const;
	void sortVehicles();
private:
	static bool vehicleMinorThan(Vehicle *v1, Vehicle *v2);
	bool vehicleExists(Vehicle *vehicle) const;
};

class NoSuchVehicleException {
public:
	NoSuchVehicleException() { }
};

class NoSuchBrandException : public std::logic_error {

private:
	const std::string brand;
	const std::string message;

public:
	NoSuchBrandException(const std::string &brand, const std::string &message = "The brand doest not exist.");
	std::string getBrand() const;

};

NoSuchBrandException::NoSuchBrandException(const std::string &brand, const std::string &message)
: std::logic_error(brand + ": " + message), brand(brand), message(message) {}

std::string NoSuchBrandException::getBrand() const {
	return this->brand;
}

template <class Vehicle>
Garage<Vehicle>::Garage(int size) : capacity(size) {
}

template <class Vehicle>
Garage<Vehicle>::~Garage() {
	typename std::vector<Vehicle *>::const_iterator it;
	for (it=vehicles.begin(); it!=vehicles.end(); it++) {
		delete *it;
	}
}

template<class Vehicle>
std::vector<Vehicle *> Garage<Vehicle>::getVehicles() const {
	return vehicles;
}

template<class Vehicle>
void Garage<Vehicle>::setVehicles(std::vector<Vehicle*> vehicles) {
	this->vehicles = vehicles;
}

template<class Vehicle>
int Garage<Vehicle>::getCapacity() const {
	return capacity;
}

template<class Vehicle>
bool Garage<Vehicle>::addVehicle(Vehicle *vehicle) {
	bool valid = true;

	if (vehicles.size() >= capacity ||vehicleExists(vehicle))
		valid = false;
	else
		vehicles.push_back(vehicle);

	return valid;
}

template<class Vehicle>
bool Garage<Vehicle>::vehicleMinorThan(Vehicle *vehicle1, Vehicle *vehicle2) {
	return (*vehicle1 < *vehicle2);
}

template<class Vehicle>
Vehicle *Garage<Vehicle>::removeVehicle(std::string brand, std::string model) {
	Vehicle *erased = nullptr;

	for (auto it = vehicles.begin(); it != vehicles.end(); ++it) {
		if ((*it)->getBrand() == brand && (*it)->getModel() == model) {
			erased = *it;
			vehicles.erase(it);
			return erased;
		}
	}

	throw NoSuchVehicleException();
}

template<class Vehicle>
float Garage<Vehicle>::avgPrice(std::string brand) const {
	unsigned qtVehicles = 0;
	float price = 0;

	for (Vehicle * v: vehicles) {
		if (v->getBrand() == brand) {
			price += v->getPrice();
			qtVehicles++;
		}
	}

	if (!qtVehicles)
		throw NoSuchBrandException(brand);

	return (price / qtVehicles);
}

template<class Vehicle>
void Garage<Vehicle>::sortVehicles() {
	/* With lambda */
	std::sort(vehicles.begin(), vehicles.end(), [] (Vehicle *a, Vehicle *b) {
		return *a < *b;
	});

	/* With auxiliary static function
	std::sort(vehicles.begin(), vehicles.end(), vehicleMinorThan);
	 */
}

template<class Vehicle>
bool Garage<Vehicle>::vehicleExists(Vehicle *vehicle) const {
	for (Vehicle *ve : vehicles)
		if (*ve == *vehicle)
			return true;

	return false;
}


#endif /* SRC_GARAGE_H_ */
