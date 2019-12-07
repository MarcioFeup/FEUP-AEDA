#include <iostream>
#include <sstream>
#include <list>
#include "packing_machine.h"
#include "empty_machine_exception.h"

PackingMachine::PackingMachine(unsigned int box_capacity) : box_capacity(box_capacity) {}

const std::priority_queue<Object> &PackingMachine::getObjects() const {
	return objects;
}

const std::priority_queue<Box> &PackingMachine::getBoxes() const {
	return boxes;
}

unsigned PackingMachine::addBox(Box &box) {
	boxes.push(box);
	return boxes.size();
}

unsigned PackingMachine::qtUsedBoxes() const {
	return boxes.size();
}

unsigned PackingMachine::loadObjects(std::vector<Object> &objects) {
	unsigned count = 0;

	for (auto it = objects.begin(); it != objects.end();) {
		if ((*it).getWeight() <= box_capacity) {
			count++;
			this->objects.push(*it);
			it = objects.erase(it);
		} else {
			++it;
		}
	}

	return count;
}


Box PackingMachine::searchBox(Object &object) {
	std::vector<Box *> aux;

	return searchBox(object, aux);
}

Box PackingMachine::searchBox(Object &object, std::vector<Box *> &aux) {
	if (boxes.empty()) { // adds a box with the required weight
		for (auto b : aux) // reposes all boxes from "aux" (read the else clause)
			boxes.push(*b);

		Box box;
		return box;
	}

	Box box = boxes.top();
	if (box.getFreeWeight() >= object.getWeight()) {
		boxes.pop();

		for (auto b : aux) // reposes all boxes from "aux" (read the else clause)
			boxes.push(*b);

		return box;
	} else { // removes the box from the queue, saving it in "aux" and keeps searching
		aux.push_back(&box);
		boxes.pop();

		return searchBox(object, aux);
	}
}

unsigned PackingMachine::packObjects() {
	unsigned count = 0;

	while (!objects.empty()) {
		Object obj = objects.top();
		objects.pop();

		Box box = searchBox(obj);
		if (box.getFreeWeight() == box_capacity)
			count++;
		box.addObject(obj);
		boxes.push(box);
	}

	return count;
}

std::string PackingMachine::printUnpackedObjects() {
	if (objects.empty())
		return "There's no objects!\n";

	std::priority_queue<Object> aux;
	std::stringstream ss;

	while (!objects.empty()) {
		Object obj = objects.top();
		ss << obj << std::endl;
		objects.pop();
		aux.push(obj);
	}

	this->objects = aux;
	return ss.str();
}

Box PackingMachine::boxWithMostObjects() {
	std::list<Box> aux;
	std::stack<Box> bigger;
	unsigned max = 0;

	while (!boxes.empty()) {
		Box box = boxes.top();
		aux.push_back(box);
		boxes.pop();

		if (box.qtObjects() >= max) {
			max = box.qtObjects();
			bigger.push(box);
		}
	}

	for (auto p : aux)
		boxes.push(p);

	if (bigger.empty())
		throw EmptyMachineException();

	return bigger.top();
}
