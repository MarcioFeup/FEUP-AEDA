#include "time_manager.h"

TimeManager::TimeManager(unsigned next_arrival, unsigned current_time) :
		next_arrival(next_arrival), current_time(current_time) {}

unsigned int TimeManager::getCurrentTime() const {
	return current_time;
}

unsigned int TimeManager::getNextArrival() const {
	return next_arrival;
}

void TimeManager::setNextArrival(unsigned int nextArrival) {
	next_arrival = nextArrival;
}
