#ifndef EX0_SPORTS_CLUBMEMBER_H
#define EX0_SPORTS_CLUBMEMBER_H


#include "Personal.h"

/**
 * Represents a member of the club.
 */
class ClubMember : public Personal {

  public:

	/**
	 * The monthly quota.
	 */
	static float monthlyQuota;

	/**
	 * Constructs a new club member, assigning its ID.
	 */
	ClubMember();

	/**
 	* Gets the unique ID of the club member.
 	*
 	* @return the unique ID
 	*/
	const int &getId() const override;

  private:
	/**
	 * The unique ID of the club member.
	 */
	const int id;
};


#endif //EX0_SPORTS_CLUBMEMBER_H
