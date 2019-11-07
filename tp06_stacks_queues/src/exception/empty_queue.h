#ifndef AEDA1920_FP06_EMPTY_QUEUE_H
#define AEDA1920_FP06_EMPTY_QUEUE_H


#include <stdexcept>

/**
 * Represents an error that defines when a queue is empty.
 */
class EmptyQueueException : std::logic_error {

  public:

	/**
	 * Constructs a new exception with an indicative message.
	 * 
	 * @param message the indicative message 
	 */
	explicit EmptyQueueException(const std::string &message = "The queue is empty");

	/**
	 * Gets the indicative message.
	 * 
	 * @return const std::string& the indicative message 
	 */
	const std::string &getMessage() const;

  private:

	/**
	 * The indicative message.
	 */
	const std::string message;

};


#endif //AEDA1920_FP06_EMPTY_QUEUE_H
