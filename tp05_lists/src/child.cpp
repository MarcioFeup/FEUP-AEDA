#include "child.h"

#include <utility>
#include <sstream>

using namespace std;

Child::Child() : name(""), age(0) {}

Child::Child(string name, unsigned age) : name(move(name)), age(age) {}

Child::Child(const Child &child) {
	this->name = child.name;
	this->age = child.age;
}

string Child::getName() const {
	return this->name;
}

unsigned Child::getAge() const {
	return this->age;
}

bool Child::operator==(const Child &child) const {
	return (this->name == child.name && this->age == child.age);
}

string Child::describe() const {
	stringstream oss;
	oss << name << ": " << age;
	return oss.str();
}



