#ifndef AEDA1920_FP10_PACKING_MACHINE_H
#define AEDA1920_FP10_PACKING_MACHINE_H


#include <queue>
#include "object.h"
#include "box.h"

/**
 * Represents a machine that packs objects into boxes.
 */
class PackingMachine {
  public:
	/**
	 * The constructor that receives the box capacity.
	 *
	 * @param box_capacity the box capacity
	 */
	explicit PackingMachine(unsigned int box_capacity = 10);

	/**
	 * Adds a box to the machine.
	 *
	 * @param box the box to add
	 * @return the amount of boxes after
	 */
	unsigned addBox(Box &box);

	/**
	 * Loads a vector of objects into the machine.
	 *
	 * @param objects the reference to the vector of objects
	 * @return the amount of objects loaded
	 */
	unsigned loadObjects(std::vector<Object> &objects);

	/**
	 * Gets a box that has free space for a certain object, removing it from the machine.
	 * If such box does not exist, creates one.
	 *
	 * @param object the object
	 * @return the box
	 */
	Box searchBox(Object &object);

	/**
	 * Packs the objects in boxes.
	 *
	 * @return the amount of created boxes
	 */
	unsigned packObjects();

	/**
	 * Gets a string with all the objects currently to pack.
	 *
	 * @return the string
	 */
	std::string printUnpackedObjects();

	/**
	 * Gets the box that has more objects.
	 *
	 * @return the box with more objects
	 */
	Box boxWithMostObjects();

	/**
	 * Gets the amount of used boxes.
	 *
	 * @return the amount of used boxes
	 */
	unsigned qtUsedBoxes() const;

	/**
	 * Gets a const priority queue with the objects.
	 *
	 * @return the priority queue with the objects
	 */
	const std::priority_queue<Object> &getObjects() const;

	/**
	 * Gets a const priority queue with the boxes.
	 *
	 * @return the priority queue with the boxes
	 */
	const std::priority_queue<Box> &getBoxes() const;

  private:
	/**
	 * The priority queue with the objects.
	 */
	std::priority_queue<Object> objects;

	/**
	 * The priority queue with the boxes.
	 */
	std::priority_queue<Box> boxes;

	/**
	 * The capacity of the boxes.
	 */
	unsigned box_capacity;

	Box searchBox(Object &object, std::vector<Box *> &aux);
};


#endif //AEDA1920_FP10_PACKING_MACHINE_H
