#ifndef EX0_SPORTS_ATHLETE_H
#define EX0_SPORTS_ATHLETE_H


#include "Personal.h"
#include "../activity/Class.h"
#include "../activity/Modality.h"

/**
 * Represents an athlete.
 */
class Athlete : public Personal {

  public:
	/**
	 * Constructs a new athlete, assigning its ID, modality and class.
	 *
	 * @param modality the modality of the athlete
	 * @param aClass the class of the athlete
	 */
	Athlete(Modality modality, Class aClass);

	/**
 	* Gets the unique ID of the athlete.
 	*
 	* @return the unique ID
 	*/
	const int &getId() const override;

  private:
	/**
	 * The unique ID of the athlete.
	 */
	const int id;

	/**
	 * The modality of the athlete.
	 */
	const Modality modality;

	/**
	 * The class of the athlete
	 */
	const Class aClass;
};


#endif //EX0_SPORTS_ATHLETE_H
