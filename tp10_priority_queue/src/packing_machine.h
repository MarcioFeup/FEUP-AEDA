#ifndef AEDA1920_FP10_PACKING_MACHINE_H
#define AEDA1920_FP10_PACKING_MACHINE_H


#include <queue>
#include "object.h"
#include "box.h"

class PackingMachine {
  public:
	explicit PackingMachine(unsigned int box_capacity = 10);

	unsigned addBox(Box &box);

	unsigned loadObjects(std::vector<Object> &objects);

	Box searchBox(Object &object);

	unsigned packObjects();

	std::string printUnpackedObjects();

	Box boxWithMostObjects();

	unsigned qtUsedBoxes() const;

	const std::priority_queue<Object> &getObjects() const;

	const std::priority_queue<Box> &getBoxes() const;

  private:
	std::priority_queue<Object> objects;

	std::priority_queue<Box> boxes;

	unsigned box_capacity;

	Box searchBox(Object &object, std::vector<Box *> &aux);
};


#endif //AEDA1920_FP10_PACKING_MACHINE_H
