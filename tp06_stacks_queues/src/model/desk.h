#ifndef AEDA1920_FP06_DESK_H
#define AEDA1920_FP06_DESK_H


#include "client.h"
#include "../util/time_manager.h"
#include <iostream>
#include <queue>


class Desk {

  public:
	Desk(unsigned bundle_time = 2);
	unsigned getServedCostumers() const;
	void arrive();
	void leave();
	void next();
	Client &getNextClient();
	unsigned int getQtClients() const;
	unsigned getBundleTime() const;
	const std::queue<Client> &getClients() const;
	const TimeManager &getTimeManager() const;
	unsigned getTimeUntilLeaves() const;

	friend std::ostream &operator<<(std::ostream &out, const Desk &desk);

  private:
	const unsigned bundle_time;
	std::queue<Client> clients;
	unsigned served_costumers;
	TimeManager time_manager;
	unsigned time_until_leaves;
};


#endif //AEDA1920_FP06_DESK_H
