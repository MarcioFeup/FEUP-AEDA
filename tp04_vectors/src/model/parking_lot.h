#ifndef PARK_H_
#define PARK_H_

#include "client.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ParkingLot {

  public:
	ParkingLot(unsigned int capacity, unsigned int numMaxClients);
	~ParkingLot();
	bool enter(const string &name);
	bool leave(const string &name);
	unsigned int getQtSpots() const;
	unsigned int getQtdOccupiedSpots() const;
	unsigned int clientPosition(const string &name) const;
	unsigned int getFrequency(const string &name) const;
	Client getClientAtPos(vector<Client>::size_type p) const;
	void sortClientsByFrequency();
	void sortClientsByName();
	vector<string> findClientsByFrequency(int min_frequency, int max_frequency);
	bool addClient(const string &name);
	bool removeClient(const string &name);
	vector<Client> getClients() const;
	friend ostream &operator<<(ostream &os, const ParkingLot &pl);

  private:
	const unsigned int capacity;
	const unsigned int max_clients;
	vector<Client> clients;
	unsigned int empty_slots;
	unsigned int qt_clients;
};

#endif /*PARK_H_*/
