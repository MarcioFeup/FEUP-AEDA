#ifndef AEDA1920_FP06_CLIENT_H
#define AEDA1920_FP06_CLIENT_H


/**
 * Represents a client that wraps gifts.
 */
class Client {

  public:

	/**
	 * Constructs a new client with a random number of gifts bewteen 1 and 5.
	 */
	Client();

	/**
	 * Gets the quantity of gifts of the client.
	 * 
	 * @return unsigned int the quantity of gifts 
	 */
	unsigned int getQtGifts() const;

  private:

	/**
	 * The quantity of gifts
	 */
	unsigned qt_gifts;
};


#endif //AEDA1920_FP06_CLIENT_H
