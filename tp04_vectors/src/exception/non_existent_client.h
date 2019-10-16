#ifndef AEDA1920_FP04_NON_EXISTENT_CLIENT_H
#define AEDA1920_FP04_NON_EXISTENT_CLIENT_H


#include <string>
#include <stdexcept>

/**
 * Represents an exception that indicates a non existent client.
 *
 * @author Márcio Duarte
 */
class NonExistentClient : public std::invalid_argument {

  public:

	/**
	 * The constructor of the exception.
	 * It accepts the name of the client and a custom message.
	 *
	 * @param clientName the name of the client
	 * @param message the custom message
	 */
	explicit NonExistentClient(const std::string &clientName, const std::string &message = "The client doest not exist.");

	/**
	 * Returns the name of the client.
	 *
	 * @return the name of the client
	 */
	std::string getClientName() const;

  private:

	/**
	 * Represents the name of the client.
	 */
	const std::string clientName;

	/**
	 * The custom message of the exception.
	 */
	const std::string message;
};


#endif //AEDA1920_FP04_NON_EXISTENT_CLIENT_H
