//
// Created by Márcio on 9/28/19.
//

#ifndef AEDAEX0_FILEEXCEPTION_H
#define AEDAEX0_FILEEXCEPTION_H

#include <string>
#include <stdexcept>

/*!
 * Represents an exception caused by file handling.
 */
class FileException : std::runtime_error {

  public:
	/*!
	 * The constructor of the exception.
	 *
	 * @param errorMessage the error message
	 */
	explicit FileException(const std::string &errorMessage);

	/*!
	 * Gets an informative message about the exception.
	 *
	 * @return the informative message
	 */
	const char* what() const noexcept override ;

  private:
	/*!
	 * An informative message about the exception.
	 */
	const std::string error;
};

/*!
 * Represents an exception caused by calling a non existent file.
 *
 * @author Márcio Duarte
 */
class NonExistentFileException : public FileException {

  public:
	/*!
	 * The constructor of the message.
	 *
	 * @param error the error message
	 */
	explicit NonExistentFileException(const std::string &error);
};

/*!
 * Represents an exception caused by an invalid input on a file.
 *
 * @author Márcio Duarte
 */
class InputException : public FileException {

  public:
	/*!
	 * The constructor of the exception.
	 *
	 * @param error the error message
	 */
	explicit InputException(const std::string &error);
};


#endif //AEDAEX0_FILEEXCEPTION_H
