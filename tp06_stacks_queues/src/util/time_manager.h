#ifndef AEDA1920_FP06_TIME_MANAGER_H
#define AEDA1920_FP06_TIME_MANAGER_H


class TimeManager {

  public:
	TimeManager(unsigned next_arrival, unsigned current_time = 0);
	void start();
	void advance(unsigned time);
	unsigned getCurrentTime() const;
	unsigned getNextArrival() const;
	void setNextArrival(unsigned int nextArrival);

  private:
	unsigned current_time;
	unsigned next_arrival;
};


#endif //AEDA1920_FP06_TIME_MANAGER_H
