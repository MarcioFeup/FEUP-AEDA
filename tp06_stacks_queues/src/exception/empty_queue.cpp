#include "empty_queue.h"

EmptyQueueException::EmptyQueueException(const std::string &message) : std::logic_error(message), message(message) {}

const std::string &EmptyQueueException::getMessage() const {
	return message;
}
