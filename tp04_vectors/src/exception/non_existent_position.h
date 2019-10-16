#ifndef AEDA1920_FP04_NON_EXISTENT_POSITION_H
#define AEDA1920_FP04_NON_EXISTENT_POSITION_H


#include <string>
#include <stdexcept>

class NonExistentPosition : public std::invalid_argument {

  public:
	explicit NonExistentPosition(long position, const std::string &message = "There is no client at this position.");
	long getPosition() const;

  private:
	const long position;
	const std::string message;
};


#endif //AEDA1920_FP04_NON_EXISTENT_POSITION_H
