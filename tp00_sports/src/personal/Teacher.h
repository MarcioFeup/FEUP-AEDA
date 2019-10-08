#ifndef EX0_SPORTS_TEACHER_H
#define EX0_SPORTS_TEACHER_H


#include <set>
#include "Personal.h"
#include "../activity/Modality.h"
#include "../activity/Class.h"

/**
 * Represents a teacher.
 *
 * @author Márcio Duarte
 */
class Teacher : public Personal{

  public:

	/**
	 * Constructs a new teacher, assigning its ID, modality and classes
	 *
	 * @param modality the modality of the teacher
	 * @param classes the classes the teacher tutors
	 */
	Teacher(Modality modality, std::set<Class *> classes);

	/**
 	* Gets the unique ID of the teacher.
 	*
 	* @return the unique ID
 	*/
	const int &getId() const override;

  private:

	/**
	 * The unique ID of the teacher.
	 */
	const int id;

	/**
	 * The modality of the teacher.
	 */
	const Modality modality;

	/**
	 * The classes the teacher teaches.
	 */
	std::set<Class *> classes;
};


#endif //EX0_SPORTS_TEACHER_H
