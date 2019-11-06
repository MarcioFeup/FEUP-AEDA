#ifndef AEDA1920_FP06_DESK_H
#define AEDA1920_FP06_DESK_H


#include "client.h"
#include "../util/time_manager.h"
#include <iostream>
#include <queue>


class Desk {

  public:
	Desk(unsigned bundle_time = 2);
	void arrive();
	void leave();
	void next();
	Client &getNextClient();
	unsigned int getAttendedClients() const;
	unsigned getBundleTime() const;
	const std::queue<Client> &getClients() const;
	const TimeManager &getTimeManager() const;
	unsigned getTimeUntilLeaves() const;

	friend std::ostream &operator<<(std::ostream &out, const Desk &desk);

  private:
	const unsigned bundle_time;
	std::queue<Client> clients;
	unsigned served_costumers;
	unsigned attended_clients;
	TimeManager time_manager;
	unsigned leaving_time;
};


#endif //AEDA1920_FP06_DESK_H
