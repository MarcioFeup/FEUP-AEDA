#include <sstream>
#include "box.h"

unsigned Box::last_id = 1;

Box::Box(unsigned int capacity) : id(last_id++), capacity(capacity), free_weight(capacity) {}

unsigned int Box::getId() const {
	return id;
}

unsigned int Box::getFreeWeight() const {
	return free_weight;
}

void Box::addObject(Object &object) {
	free_weight -= object.getWeight();
	objects.push(object);
}

void Box::resetId() {
	last_id = 1;
}

unsigned Box::getSize() const {
	return objects.size();
}

unsigned int Box::getCapacity() const {
	return capacity;
}

bool Box::operator<(const Box &box) const {
	return this->free_weight > box.free_weight;
}

std::string Box::print() {
	if (objects.empty())
		return "Box " + std::to_string(id) + " empty!\n";

	std::stringstream ss;
	std::stack<Object> aux;

	ss << "C" << this->id << "[";

	while(!objects.empty()) {
		Object obj = objects.top();
		ss << " " << obj;
		objects.pop();
		aux.push(obj);
	}

	ss << " ]";

	while (!aux.empty()) {
		objects.push(aux.top());
		aux.pop();
	}

	return ss.str();
}
