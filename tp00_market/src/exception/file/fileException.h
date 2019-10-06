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
	 * @param fileName the name of the file that caused the exception
	 * @param errorMessage the error message
	 */
	explicit FileException(const std::string &fileName, const std::string &errorMessage);

	/*!
	 * Gets an informative message about the exception.
	 *
	 * @return the informative message
	 */
	virtual const char *what() const noexcept override;

  private:
	/*!
	 * An informative message about the exception.
	 */
	const std::string error;

	/*!
 	* The name of the problematic file.
 	*/
	const std::string fileName;
};

/*!
 * Represents an exception caused by calling a non existent file.
 *
 * @author Márcio Duarte
 */
class NonExistentFileException : public FileException {

  public:
	/*!
	 * The constructor of the exception.
	 *
	 * @param fileName the name of the non existent file
	 * @param error an informative message about the exception
	 */
	explicit NonExistentFileException(const std::string &fileName, const std::string &error = "The file does not exist.");
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
	 * @param fileName the name of the file where the input exception exists
	 * @param error an informative message about the exception
	 */
	explicit InputException(const std::string &fileName, const std::string &error = "There is an input error in the file.");
};


#endif //AEDAEX0_FILEEXCEPTION_H
