#ifndef PARK_H_
#define PARK_H_

#include "client.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Represents a parking lot.
 *
 * @author Márcio Duarte
 */
class ParkingLot {

  public:

	/**
	 * The constructor of the parking lot taking into account its capacity and max clients.
	 *
	 * @param capacity the capacity
	 * @param numMaxClients the max number of clients
	 */
	ParkingLot(unsigned int capacity, unsigned int numMaxClients);

	/**
	 * The default destructor.
	 */
	~ParkingLot();

	/**
	 * Makes a client enter the parking lot by its name.
	 *
	 * @param name the name of the client
	 * @return true if the operation succeeded, false otherwise
	 */
	bool enter(const string &name);

	/**
	 * Makes a client leave the parking lot by its name.
	 *
	 * @param name the name of the client
	 * @return true if the operation succeeded, false otherwise
	 */
	bool leave(const string &name);

	/**
	 * Returns the capacity of the parking lot.
	 *
	 * @return the capacity
	 */
	unsigned int getCapacity() const;

	/**
	 * Returns the number of occupied slots.
	 *
	 * @return the number of occupied slots.
	 */
	unsigned int getQtdOccupiedSpots() const;

	/**
	 * Gets a position of a client in the parking lot, by its name.
	 *
	 * @param name the name of the client
	 * @return the position of the client
	 */
	int clientPosition(const string &name) const;

	/**
	 * Gets the frequency of a client, given its name.
	 *
	 * @param name the name of the client
	 * @return the frequency of the client
	 * @throws NonExistentClient if there is no such client
	 */
	unsigned int getFrequency(const string &name) const;

	/**
	 * Gets the client by its position.
	 *
	 * @param position the position
	 * @return the client
	 * @throws NonExistentPosition if there is no such position
	 */
	Client getClientAtPos(vector<Client>::size_type position) const;

	/**
	 * Sorts the clients by frequency, from the most frequent to the least.
	 */
	void sortClientsByFrequency();

	/**
	 * Sorts the clients by alphabetical order of their name.
	 */
	void sortClientsByName();

	/**
	 * Gets the name of the clients who frequency lies between the min_frequency and max_frequency given.
	 *
	 * @param min_frequency the minimum frequency
	 * @param max_frequency the maximum frequency
	 * @return a vector of the names of suh clients
	 */
	vector<string> findClientsByFrequency(int min_frequency, int max_frequency);

	/**
	 * Adds a client to the parking lot by its name.
	 *
	 * @param name the name of the client
	 * @return true if the client was successfully added, false otherwise
	 */
	bool addClient(const string &name);

	/**
	 * Removes a client of the parking lot, given its name.
	 *
	 * @param name the name of the client
	 * @return true if the client was successfully added, false otherwise
	 */
	bool removeClient(const string &name);

	/**
	 * Returns the vector of clients, immutable.
	 *
	 * @return the vector of clients
	 */
	const vector<Client> &getClients() const;

	/**
	 * Gets the information of all clients in an ostream
	 *
	 * @param os the ostream
	 * @param pl the parking lot
	 * @return the ostream
	 */
	friend ostream &operator<<(ostream &os, const ParkingLot &pl);

  private:

	/**
	 * Represents the total capacity of the parking lot, this is, the total number of cars it can carry in a single moment.
	 */
	const unsigned int capacity;

	/**
	 * Represents the max allowed clients of the parking lot.
	 */
	const unsigned int max_clients;

	/**
	 * Stores all the clients.
	 */
	vector<Client> clients;

	/**
	 * Represents the quantity of empty slots.
	 */
	unsigned int empty_slots;

	/**
	 * Represents the quantity of clients.
	 */
	unsigned int qt_clients;
};

#endif /*PARK_H_*/
