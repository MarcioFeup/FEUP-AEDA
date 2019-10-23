#ifndef AEDA1920_FP05_CHILD_H
#define AEDA1920_FP05_CHILD_H

#include <string>

/**
 * Represents a child, providing access to its name and age.
 * Children are also who play the "pim pam pum" game.
 */
class Child {

  public:

	/**
	 * The empty constructor of the child.
	 */
	Child();

	/**
	 * The copy constructor of the child.
	 * Takes the attributes of a given child and copies them.
	 *
	 * @param child the given child.
	 */
	Child(const Child &child);

	/**
	 * The complete constructor of the child, assigning its name and age.
	 *
	 * @param name the name of the child.
	 * @param age the age of the child.
	 */
	Child(std::string name, unsigned age);

	/**
	 * Describes a child, putting into a string its name and age.
	 *
	 * @return the description string
	 */
	std::string describe() const;

	/**
	 * Gets the name of the child.
	 *
	 * @return the name of the child.
	 */
	std::string getName() const;

	/**
	 * Gets the age of the child.
	 *
	 * @return the age of the child.
	 */
	unsigned getAge() const;

	/**
	 * Compares two children.
	 * Children are equal if they have the same name and age.
	 *
	 * @param child the other child.
	 * @return true if they are equal, false otherwise
	 */
	bool operator==(const Child &child) const;

  private:

	/**
	 * The name of the child.
	 */
	std::string name;

	/**
	 * The age of the child.
	 */
	unsigned age;
};


#endif //AEDA1920_FP05_CHILD_H
