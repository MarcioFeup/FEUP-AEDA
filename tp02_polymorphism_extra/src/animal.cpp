#include "animal.h"
#include <sstream>
#include <utility>
#include <limits>

using namespace std;

int Animal::youngest = numeric_limits<int>::max();

Animal::Animal(string name, int age) : name(std::move(name)), age(age), vet(nullptr) {
	if (age < youngest)
		youngest = age;
}

string Animal::info() const {
	string info;
	info.append(name).append(", ").append(to_string(age)).append(", ").append(vet->info());
	return info;
}

int Animal::getYoungest(){
	return youngest;
}

string Animal::getName() const {
	return name;
}

bool Animal::isYoung() const {
	return age < getYoungAge();
}

int Animal::getAge() const {
	return age;
}

const Vet *Animal::getVet() const {
	return vet;
}

void Animal::setVet(Vet *vet) {
	this->vet = vet;
}


Dog::Dog(string name, int age, string breed) : Animal(std::move(name), age), breed(std::move(breed)) {}

string Dog::info() const {
	string info = Animal::info().append(", ").append(breed);
	return info;
}

int Dog::getYoungAge() const {
	return YOUNG_AGE;
}

Flyer::Flyer(int maxVelocity, int maxHeight) : maxVelocity(maxVelocity), maxHeight(maxHeight) {}

string Flyer::info() const {
	string info;
	info.append(to_string(maxVelocity)).append(", ").append(to_string(maxHeight));
	return info;
}

Bat::Bat(string name, int age, int maxVelocity, int maxHeight) : Animal(std::move(name), age), Flyer(maxVelocity, maxHeight) {}

int Bat::getYoungAge() const {
	return YOUNG_AGE;
}

string Bat::info() const {
	string info = Animal::info().append(", ").append(Flyer::info());
	return info;
}
