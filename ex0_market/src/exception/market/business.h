//
// Created by marcio on 9/28/19.
//

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
	 * @param error the error to call
	 */
	explicit NonExistentParticipantException(std::string error = "The participant does not exist.");
};


#endif //AEDAEX0_MARKET_EXCEPTION_H
