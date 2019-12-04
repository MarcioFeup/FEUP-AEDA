#ifndef AEDA1920_FP10_BOX_H
#define AEDA1920_FP10_BOX_H


#include <stack>
#include "object.h"

class Box {
  public:
	explicit Box(unsigned capacity = 10);

	void addObject(Object &object);

	static void resetId();

	std::string print();

	unsigned getSize() const;

	unsigned int getId() const;

	unsigned int getFreeWeight() const;

	unsigned int getCapacity() const;

	bool operator<(const Box &box) const;

  private:
	static unsigned last_id;

	std::stack<Object> objects;

	unsigned id;

	unsigned capacity;

	unsigned free_weight;
};


#endif //AEDA1920_FP10_BOX_H
