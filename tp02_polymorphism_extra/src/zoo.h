#ifndef ZOO_H_
#define ZOO_H_

#include "animal.h"
#include <vector>

class Zoo {

  public:
	bool isYoungAnimal(string name) const;

	void readVets(ifstream &istream);

	string info() const;

	void addAnimal(Animal *animal);

	bool removeVet(const string& name);

	int qtdAnimals() const;

	int qtdVets() const;

	bool operator<(Zoo &zoo2) const;

  private:
	vector<Animal *> animals;
	vector<Vet *> vets;

	bool hasVet(const string &name) const;
};


#endif /* ZOO_H_ */
