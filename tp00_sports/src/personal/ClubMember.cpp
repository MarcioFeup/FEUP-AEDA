#include "ClubMember.h"

float ClubMember::monthlyQuota = 200; // Speculative value only.

ClubMember::ClubMember() : id(++Personal::qtdPersonal) {}

const int &ClubMember::getId() const {
// the first personal gets 1 as ID.
	return this->id;
}
