#include "desk.h"
#include "../exception/empty_queue.h"
#include <iostream>

using namespace std;

Desk::Desk(unsigned bundle_time) :
		bundle_time(bundle_time), time_manager(TimeManager(rand() % 20 + 1)), time_until_leaves(0) {}

void Desk::arrive() {
	Client client;
	clients.push(client);
	this->time_manager.setNextArrival(rand() % 20 + 1);

	this->time_until_leaves = time_manager.getCurrentTime() + client.getQtGifts() * bundle_time;
	std::cout << "Time = " << time_manager.getCurrentTime() << "\nArrived new client with " << client.getQtGifts() << " gifts." << endl;
}

void Desk::leave() {
	if (clients.empty())
		return;

	clients.pop();

	Client next_client = clients.front();

	unsigned time_taken = next_client.getQtGifts() * bundle_time;
	this->time_until_leaves = time_manager.getCurrentTime() + time_taken;
	std::cout << "Time = " << time_manager.getCurrentTime() << "\nNew client left." << endl;
}

void Desk::next() {
	(time_until_leaves < time_manager.getNextArrival()) ? leave() : arrive();
}

Client &Desk::getNextClient() {
	if (clients.empty())
		throw EmptyQueueException();
	return clients.front();
}

unsigned Desk::getBundleTime() const {
	return bundle_time;
}

const queue<Client> &Desk::getClients() const {
	return clients;
}

const TimeManager &Desk::getTimeManager() const {
	return time_manager;
}

unsigned int Desk::getTimeUntilLeaves() const {
	return time_until_leaves;
}

unsigned int Desk::getQtClients() const {
	return clients.size();
}

ostream & operator <<(ostream & out, const Desk & desk) {
	out << "Attended " << desk.getQtClients() << ";\tWaiting: " << desk.getClients().size() << "." << std::endl;
	return out;
}