#include "desk.h"
#include "../exception/empty_queue.h"
#include <iostream>

using namespace std;

Desk::Desk(unsigned bundle_time) :
		bundle_time(bundle_time), time_manager(TimeManager(rand() % 20 + 1)), leaving_time(0), attended_clients(0) {}

void Desk::arrive() {
	Client client;

	if (clients.empty())
		this->leaving_time = time_manager.getCurrentTime() + client.getQtGifts() * bundle_time;

	clients.push(client);
	this->time_manager.setNextArrival(time_manager.getCurrentTime() + rand() % 20 + 1);

	std::cout << "Time = " << time_manager.getCurrentTime() << "\tArrived new client with " << client.getQtGifts() << " gifts." << endl;
	++attended_clients;
}

void Desk::leave() {
	if (clients.empty())
		return;

	clients.pop();

	std::cout << "Time = " << time_manager.getCurrentTime() << "\tNew client left." << endl;
	if (clients.empty())
		return;

	Client next_client = clients.front();

	unsigned time_taken = next_client.getQtGifts() * bundle_time;
	this->leaving_time = time_manager.getCurrentTime() + time_taken;
}

// TODO
void Desk::next() {
	if (clients.empty()) {
		time_manager.setCurrentTime(time_manager.getNextArrival());
		arrive();
	} else {
		if (time_manager.getNextArrival() < leaving_time) {
			time_manager.setCurrentTime(time_manager.getNextArrival());
			arrive();
		} else {
			time_manager.setCurrentTime(leaving_time);
			leave();
		}
	}
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
	return leaving_time;
}

unsigned int Desk::getAttendedClients() const {
	return attended_clients;
}

ostream &operator<<(ostream &out, const Desk &desk) {
	out << "Attended " << desk.getAttendedClients() << ";\tWaiting: " << desk.getClients().size() << "." << std::endl;
	return out;
}