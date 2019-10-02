#include "Athlete.h"

Athlete::Athlete(Modality modality, Class aClass) : id(++Personal::qtdPersonal), modality(modality), aClass(aClass) {}

const int &Athlete::getId() const {
// the first personal gets 1 as ID.
	return this->id;
}
