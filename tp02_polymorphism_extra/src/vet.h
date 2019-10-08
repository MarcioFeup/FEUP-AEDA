#ifndef SRC_VET_H_
#define SRC_VET_H_

#include <string>

using namespace std;

class Vet {

  public:
	Vet(string name, long id);

	string getName() const;

	// TODO: complete.

  private:
	string name;
	long id;
};


#endif /* SRC_VET_H_ */
