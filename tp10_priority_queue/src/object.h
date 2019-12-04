#ifndef AEDA1920_FP10_OBJECT_H
#define AEDA1920_FP10_OBJECT_H


#include <ostream>

class Object {
  public:
	Object(unsigned int id, unsigned int weight);

	unsigned int getId() const;

	unsigned int getWeight() const;

	bool operator<(const Object &object) const;

	friend std::ostream &operator<<(std::ostream &os, const Object &object);

  private:
	unsigned id;

	unsigned weight;
};


#endif //AEDA1920_FP10_OBJECT_H
