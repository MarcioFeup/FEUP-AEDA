#ifndef SRC_ANIMAL_H_
#define SRC_ANIMAL_H_

#include "vet.h"
#include <string>

using namespace std;


class Animal {

  public:
	Animal(string name, int age);

	virtual ~Animal() {};

	virtual string info() const;

	static int getYoungest();

	virtual int getYoungAge() const = 0;

	virtual bool isYoung() const;

	string getName() const;

	int getAge() const;

	const Vet *getVet() const;

	void setVet(Vet *vet);

  protected:
	static int youngest;

	string name;
	int age;
	Vet *vet;
};


class Dog : public Animal {

  public:
	Dog(string name, int age, string breed);

	string info() const override;

	int getYoungAge() const override;

  private:
	static const int YOUNG_AGE = 5;

	string breed;
};


class Flyer {

  public:
	Flyer(int maxVelocity, int maxHeight);

	virtual ~Flyer() {};

	virtual string info() const;

  private:
	int maxVelocity;
	int maxHeight;
};


class Bat : public Animal, public Flyer {

  public:
	Bat(string name, int age, int maxVelocity, int maxHeight);

	int getYoungAge() const override;

	string info() const override;

  private:
	static const int YOUNG_AGE = 4;
};


#endif /* SRC_ANIMAL_H_ */
