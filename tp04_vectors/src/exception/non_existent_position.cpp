#include "non_existent_position.h"
#include <string>

NonExistentPosition::NonExistentPosition(long position, const std::string &message) :
		invalid_argument(std::to_string(position) + ": " + message), position(position), message(message) {}

long NonExistentPosition::getPosition() const {
	return position;
}
