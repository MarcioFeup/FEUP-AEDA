#ifndef SRC_VET_H_
#define SRC_VET_H_

#include <string>

using namespace std;

class Vet {

  public:
	Vet(string name, long id);

	string info() const;

	string getName() const;

  private:
	string name;
	long id;
};


#endif /* SRC_VET_H_ */
