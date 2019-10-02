#ifndef EX0_SPORTS_PERSONAL_H
#define EX0_SPORTS_PERSONAL_H


/**
 * Represents a person connected to the sports club.
 *
 * @author Márcio Duarte
 */
class Personal {

  public:
  	/**
 	* Counts the quantity of personal so the ID can be sequential.
 	*/
	static int &qtdPersonal;

	/**
	 * Gets the unique ID of the person.
	 *
	 * @return the unique ID
	 */
	virtual const int &getId() const = 0;
};


#endif //EX0_SPORTS_PERSONAL_H
