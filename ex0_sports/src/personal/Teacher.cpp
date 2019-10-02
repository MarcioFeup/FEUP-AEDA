#include "Teacher.h"

#include <utility>

Teacher::Teacher(Modality modality, std::set<Class *> classes) : id(++Personal::qtdPersonal), modality(modality),
																 classes(std::move(classes)) {}

const int &Teacher::getId() const {
// the first personal gets 1 as ID.
	return this->id;
}
