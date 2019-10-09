#include "zoo.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

bool Zoo::isYoungAnimal(string name) const {
	for (Animal *animal : animals)
		if (animal->getName() == name && animal->isYoung())
			return true;

	return false;
}

void Zoo::readVets(ifstream &istream) {
	string name, idStr;
	long id;

	while (getline(istream, name)) {
		getline(istream, idStr);
		id = stol(idStr);

		Vet *vet = new Vet(name, id);
		vets.push_back(vet);
	}
}

string Zoo::info() const {
	string info;

	for (Animal *animal : animals)
		info.append(animal->info()).append("\n");

	return info;
}

void Zoo::addAnimal(Animal *animal) {
	this->animals.push_back(animal);
}

bool Zoo::removeVet(const string &name) {
	if (!this->hasVet(name))
		return false;

	vector<Vet *>::iterator index;

	for (Animal *animal : animals) {
		if (animal->getVet()->getName() == name) {
			const Vet *vet = animal->getVet();
			index = std::find(vets.begin(), vets.end(), vet);
			auto toRemove = ((index + 1) == vets.end()) ? vets.begin() : (index + 1);

			animal->setVet(*toRemove);
		}
	}

	this->vets.erase(index);
	return true;
}

int Zoo::qtdAnimals() const {
	return animals.size();
}

int Zoo::qtdVets() const {
	return vets.size();
}

bool Zoo::hasVet(const string &name) const {
	for (Vet *vet : vets)
		if (vet->getName() == name)
			return true;

	return false;
}

bool Zoo::operator<(Zoo &zoo2) const {
	int thisAge = 0, theirAge = 0;

	for (Animal *animal : animals)
		thisAge += animal->getAge();

	for (Animal *animal : zoo2.animals)
		theirAge += animal->getAge();

	return thisAge < theirAge;
}

