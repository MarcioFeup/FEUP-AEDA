#ifndef AEDA1920_FP06_EMPTY_QUEUE_H
#define AEDA1920_FP06_EMPTY_QUEUE_H


#include <stdexcept>

class EmptyQueueException : std::logic_error {

  public:
	explicit EmptyQueueException(const std::string &message = "The queue is empty");
	const std::string &getMessage() const;

  private:
	const std::string message;

};


#endif //AEDA1920_FP06_EMPTY_QUEUE_H
