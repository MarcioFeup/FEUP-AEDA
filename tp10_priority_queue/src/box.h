#ifndef AEDA1920_FP10_BOX_H
#define AEDA1920_FP10_BOX_H


#include <stack>
#include "object.h"

/**
 * Represents a box that stores objects.
 */
class Box {
  public:
    /**
     * Constructs an empty box given its capacity.
     * The box ID is assigned automatically.
     *
     * @param capacity the capacity
     */
	explicit Box(unsigned capacity = 10);

	/**
	 * Resets the Ids to the starting one.
	 */
    static void resetId();

	/**
	 * Adds an object to the box.
	 *
	 * @param object the object to add
	 */
	void addObject(Object &object);

	/**
	 * Gets the information of the box in a string.
	 *
	 * @return the string
	 */
	std::string toString();

	/**
	 * Gets the amount of objects in the box.
	 *
	 * @return the amount of objects in the box
	 */
	unsigned qtObjects() const;

	/**
	 * Gets the ID of the box.
	 *
	 * @return the ID
	 */
	unsigned int getId() const;

	/**
	 * Gets the weight left in the box.
	 *
	 * @return the free weight
	 */
	unsigned int getFreeWeight() const;

	/**
	 * Compares with another box.
	 *
	 * @param box the other box
	 * @return true if this box is "lower", false otherwise
	 */
    bool operator<(const Box &box) const;

  private:
    /**
     * The ID tracker.
     */
	static unsigned last_id;

	/**
	 * The stack of objects in the box.
	 */
	std::stack<Object> objects;

	/**
	 * The ID of the box.
	 */
	unsigned id;

	/**
	 * The total capacity of the box.
	 */
	unsigned capacity;

	/**
	 * The free weight of the box.
	 */
	unsigned free_weight;
};


#endif //AEDA1920_FP10_BOX_H
