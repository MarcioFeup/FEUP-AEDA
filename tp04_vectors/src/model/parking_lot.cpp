#include "parking_lot.h"
#include "../utils/utils.h"
#include "../exception/non_existent_client.h"
#include "../exception/non_existent_position.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


inline bool compareByFrequency(Client a, Client b) {
	return a.getFrequency() < b.getFrequency();
}

inline bool compareByName(Client a, Client b) {
	return a.getName() < b.getName();
}

ParkingLot::ParkingLot(unsigned int capacity, unsigned int numMaxClients) : capacity(capacity), max_clients(numMaxClients) {
	qt_clients = 0;
	empty_slots = capacity;
}

ParkingLot::~ParkingLot() {}

vector<Client> ParkingLot::getClients() const { return clients; }

unsigned int ParkingLot::getQtSpots() const { return capacity; }

unsigned int ParkingLot::getQtdOccupiedSpots() const { return capacity - empty_slots; }

unsigned int ParkingLot::clientPosition(const string &name) const {
	Client client = name;
	return search::sequentialSearch(clients, client);
}

unsigned int ParkingLot::getFrequency(const string &name) const {
	int client_index = clientPosition(name);
	if (client_index == -1)
		throw NonExistentClient(name);

	Client client = clients[clientPosition(name)];
	return client.getFrequency();
}

bool ParkingLot::addClient(const string &name) {
	if (qt_clients == max_clients) return false;
	if (clientPosition(name) != -1) return false;
	Client info = name;
	clients.push_back(info);
	qt_clients++;
	return true;
}

bool ParkingLot::removeClient(const string &name) {
	for (vector<Client>::iterator it = clients.begin(); it != clients.end(); it++)
		if (it->getName() == name) {
			if (!it->isPresent()) {
				clients.erase(it);
				qt_clients--;
				return true;
			} else return false;
		}
	return false;
}

bool ParkingLot::enter(const string &name) {
	if (empty_slots == 0) return false;

	int pos = clientPosition(name);
	if (pos == -1) return false;

	if (clients[pos].isPresent()) return false;

	clients[pos].setPresent(true);
	clients[pos].increaseFrequency();
	empty_slots--;
	return true;
}

bool ParkingLot::leave(const string &name) {
	int pos = clientPosition(name);
	if (pos == -1) return false;
	if (!clients[pos].isPresent()) return false;
	clients[pos].setPresent(false);
	empty_slots++;
	return true;
}

void ParkingLot::sortClientsByFrequency() {
	sort::insertionSort(clients, compareByFrequency);
	std::reverse(clients.begin(), clients.end());
}

void ParkingLot::sortClientsByName() {
	sort::quickSort(clients, 0, clients.size(), compareByName);
}

vector<string> ParkingLot::findClientsByFrequency(int min_frequency, int max_frequency) {
	vector<string> names;
	vector<Client> found_clients;

	for (Client &client : clients)
		if (client.getFrequency() >= min_frequency && client.getFrequency() <= max_frequency)
			found_clients.push_back(client);

	sort::insertionSort(found_clients, compareByFrequency);
	std::reverse(found_clients.begin(), found_clients.end());

	names.reserve(found_clients.size());
	for (Client &found : found_clients)
		names.push_back(found.getName());

	return names;
}

ostream &operator<<(ostream &os, const ParkingLot &pl) {
	for (const Client &client : pl.clients)
		os << client << endl;

	return os;
}

Client ParkingLot::getClientAtPos(vector<Client>::size_type p) const {
	if (p > clients.size() || p < 0)
		throw NonExistentPosition(p);

	Client client = *(clients.begin() + p);
	return client;
}
