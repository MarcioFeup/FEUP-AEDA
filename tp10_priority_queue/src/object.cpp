#include "object.h"

Object::Object(unsigned int id, unsigned int weight) : id(id), weight(weight) {}

unsigned int Object::getId() const {
	return id;
}

unsigned int Object::getWeight() const {
	return weight;
}

std::ostream &operator<<(std::ostream &os, const Object &object) {
	os << "O" << object.id << ": " << object.weight;
	return os;
}

bool Object::operator<(const Object &object) const {
	return this->weight < object.getWeight();
}
