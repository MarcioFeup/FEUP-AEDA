#ifndef EX0_SPORTS_SPORTSCLUB_H
#define EX0_SPORTS_SPORTSCLUB_H


#include <set>
#include <vector>
#include "../activity/Modality.h"
#include "../personal/Athlete.h"
#include "../personal/Teacher.h"
#include "../personal/ClubMember.h"
#include "../activity/Class.h"

/**
 * Represents a sports club, saving information about its personal.
 *
 * @author Márcio Duarte
 */
class SportsClub {

  private:

	/**
	 * The set of supported modalities.
	 */
	std::set<Modality> modalities;

	/**
	 * The set of classes.
	 */
	std::set<Class> classes;

	/**
	 * The list of athletes.
	 * Pointers so its by association.
	 */
	std::vector<Athlete *> athletes;

	/**
	 * The list of teachers.
	 * Pointers so its by association.
	 */
	std::vector<Teacher *> teachers;

	/**
	 * The list of club members.
	 * Pointers so its by association.
	 */
	std::vector<ClubMember *> clubMembers;
};


#endif //EX0_SPORTS_SPORTSCLUB_H
