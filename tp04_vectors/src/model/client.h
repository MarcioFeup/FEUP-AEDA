#ifndef AEDA1920_FP04_CLIENT_H
#define AEDA1920_FP04_CLIENT_H

#include <string>

/**
 * Represents a client of the parking lot, providing access to its name, frequency and if it is present there at the moment.
 *
 * @author Márcio Duarte
 */
class Client {

  public:

	/**
	 * The constructor of the client that receives the name and initializes the frequency setting him as non present.
	 *
	 * @param name the name of the client
	 */
	Client(std::string name);

	/**
	 * Increases the frequency of the client by one.
	 */
	void increaseFrequency();

	/**
	 * Gets the name of the client.
	 *
	 * @return the name of the client
	 */
	std::string getName() const;

	/**
	 * Gets if the client is present or not.
	 *
	 * @return true if the client is present, false otherwise
	 */
	bool isPresent() const;

	/**
	 * Gets the frequency of the client.
	 *
	 * @return the frequency of the client
	 */
	unsigned int getFrequency() const;

	/**
	 * Sets the presence of the client.
	 *
	 * @param present the presence of the client
	 */
	void setPresent(bool present);

	/**
	 * Operator that verifies if another client is equal to this one.
	 *
	 * @param another_client the another client
	 * @return true if they are equal, false otherwise
	 */
	bool operator==(const Client &another_client) const;

	/**
	 * Adds the information of a client in a ostream.
	 *
	 * @param os the ostream
	 * @param client the client
	 * @return the ostream
	 */
	friend std::ostream &operator<<(std::ostream &os, const Client &client);

  private:

	/**
	 * The name of the client.
	 */
	std::string name;

	/**
	 * States if the client is present at the moment.
	 */
	bool present;

	/**
	 * The frequency of the client.
	 */
	unsigned int frequency;
};


#endif //AEDA1920_FP04_CLIENT_H
