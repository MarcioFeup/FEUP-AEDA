#ifndef AEDA1920_FP04_NON_EXISTENT_CLIENT_H
#define AEDA1920_FP04_NON_EXISTENT_CLIENT_H


#include <string>
#include <stdexcept>

class NonExistentClient : public std::invalid_argument {

  public:
	explicit NonExistentClient(const std::string &clientName, const std::string &message = "The client doest not exist.");
	std::string getClientName() const;

  private:
	const std::string clientName;
	const std::string message;
};


#endif //AEDA1920_FP04_NON_EXISTENT_CLIENT_H
