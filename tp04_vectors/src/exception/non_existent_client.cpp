#include "non_existent_client.h"

NonExistentClient::NonExistentClient(const std::string &clientName, const std::string &message) :
		invalid_argument(clientName + ": " + message), clientName(clientName), message(clientName + ": " + message) {}

std::string NonExistentClient::getClientName() const {
	return clientName;
}
