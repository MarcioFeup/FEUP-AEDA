#ifndef AEDAEX0_MARKET_EXCEPTION_H
#define AEDAEX0_MARKET_EXCEPTION_H

#include <string>
#include <stdexcept>

/*!
 * Represents an exception caused by requesting an unavailable product.
 *
 * @author Márcio Duarte
 */
class UnavailableProductException : public std::invalid_argument {
};

/*!
 * Represents an exception caused by requesting a participant that doesn't exist.
 *
 * @author Márcio Duarte
 */
class NonExistentParticipantException : public std::invalid_argument {

  public:
	/*!
	 * Constructs a new exception.
	 *
	 * @param the invalid ID
	 * @param error a description of the error
	 */
	explicit NonExistentParticipantException(int id, const std::string &error = "The participant does not exist.");

  private:
	/*!
	 * The ID of the participant.
	 */
	const int id;

	/*!
	 * A description of the error.
	 */
	const std::string error;
};


#endif //AEDAEX0_MARKET_EXCEPTION_H
