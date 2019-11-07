#ifndef AEDA1920_FP06_DESK_H
#define AEDA1920_FP06_DESK_H


#include "client.h"
#include "../util/time_manager.h"
#include <iostream>
#include <queue>


/**
 * Represents a desk where clients wrap gifts.
 */
class Desk {

  public:

	/**
	 * Constructs a new desk with a given bundle time and starts the simulation.
	 * 
	 * @param bundle_time the bundle time
	 */
	Desk(unsigned bundle_time = 2);

	/**
	 * Simulates the arrival of a client.
	 */
	void arrive();

	/**
	 * Simulates the leaving of a client.
	 */
	void leave();

	/**
	 * Plays the next event (i.e., arrival or leaving), depending on the time each one takes.
	 */
	void next();

	/**
	 * Gets the first client in the queue.
	 * 
	 * @return Client& the first client
	 */
	Client &getNextClient();

	/**
	 * Gets the quantity of attended clients.
	 * 
	 * @return unsigned int the quantity of attended clients 
	 */
	unsigned int getAttendedClients() const;

	/**
	 * Gets the bundle time.
	 * 
	 * @return unsigned the bundle time 
	 */
	unsigned getBundleTime() const;

	/**
	 * Gets the queue of clients.
	 * 
	 * @return const std::queue<Client>& the queue of clients 
	 */
	const std::queue<Client> &getClients() const;

	/**
	 * Gets the time manager.
	 * 
	 * @return const TimeManager& the time manager 
	 */
	const TimeManager &getTimeManager() const;

	/**
	 * Gets the time until at which the next client leaves.
	 * 
	 * @return unsigned the time 
	 */
	unsigned getTimeUntilLeaves() const;

	/**
	 * Prints the information of the desk to a ostream.
	 * 
	 * @param out the ostream 
	 * @param desk the desk
	 * @return std::ostream& the ostream 
	 */
	friend std::ostream &operator<<(std::ostream &out, const Desk &desk);

  private:

	/**
	 * The time that takes to bundle a gift.
	 */
	const unsigned bundle_time;

	/**
	 * The queue of clients to the desk.
	 */
	std::queue<Client> clients;

	/**
	 * The quantity of attended clients.
	 */
	unsigned attended_clients;

	/**
	 * The time manager.
	 */
	TimeManager time_manager;

	/**
	 * The time at which the next client leaves.
	 */
	unsigned leaving_time;
};


#endif //AEDA1920_FP06_DESK_H
