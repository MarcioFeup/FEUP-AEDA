#ifndef AEDA1920_FP05_CHILD_H
#define AEDA1920_FP05_CHILD_H

#include <string>

class Child {

  public:
	Child();
	Child(const Child &child);
	Child(std::string name, unsigned age);
	std::string describe() const;
	std::string getName() const;
	unsigned getAge() const;
	bool operator==(const Child &child) const;
	friend std::ostream &operator<<(std::ostream &ostream, const Child &child);

  private:
	std::string name;
	unsigned age;
};


#endif //AEDA1920_FP05_CHILD_H
