#ifndef AEDA1920_FP04_NON_EXISTENT_POSITION_H
#define AEDA1920_FP04_NON_EXISTENT_POSITION_H


#include <string>
#include <stdexcept>

/**
 * Represents an exception that indicates a non existent position.
 *
 * @author Márcio Duarte
 */
class NonExistentPosition : public std::invalid_argument {

  public:

	/**
	 * The constructor of the exception.
	 * It accepts the position and a custom message.
	 *
	 * @param position the position
	 * @param message the custom message
	 */
	explicit NonExistentPosition(long position, const std::string &message = "There is no client at this position.");

	/**
	 * Returns the position.
	 *
	 * @return the position
	 */
	long getPosition() const;

  private:

	/**
	 * Represents the position that called the exception.
	 */
	const long position;

	/**
	 * The custom message of the exception.
	 */
	const std::string message;
};


#endif //AEDA1920_FP04_NON_EXISTENT_POSITION_H
