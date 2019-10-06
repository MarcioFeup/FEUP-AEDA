#include "fileException.h"

FileException::FileException(const std::string &fileName, const std::string &errorMessage) :
		runtime_error(fileName + ": " + errorMessage), error(errorMessage), fileName(fileName) {}

const char *FileException::what() const noexcept {
	return runtime_error::what();
}

NonExistentFileException::NonExistentFileException(const std::string &fileName, const std::string &error) :
		FileException(fileName, error) {}

InputException::InputException(const std::string &fileName, const std::string &error) :
		FileException(fileName, error) {}
