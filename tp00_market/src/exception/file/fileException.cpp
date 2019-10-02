//
// Created by marcio on 9/28/19.
//

#include "fileException.h"

#include <utility>

FileException::FileException(const std::string &errorMessage) : runtime_error(errorMessage), error(errorMessage) {}

const char *FileException::what() const noexcept {
	return runtime_error::what();
}

NonExistentFileException::NonExistentFileException(const std::string &error) : FileException(error) {}

InputException::InputException(const std::string &error) : FileException(error) {}
