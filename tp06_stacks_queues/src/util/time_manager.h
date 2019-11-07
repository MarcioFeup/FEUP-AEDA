#ifndef AEDA1920_FP06_TIME_MANAGER_H
#define AEDA1920_FP06_TIME_MANAGER_H


/**
 * Manages the time information.
 */
class TimeManager {

  public:
  
	/**
	 * Constructs a new time manager with a given next arrival and current time.
	 * 
	 * @param next_arrival the next arrival
	 * @param current_time the current time
	 */
	TimeManager(unsigned next_arrival, unsigned current_time = 0);

	/**
	 * Sets the current time to a given time.
	 * 
	 * @param currentTime the given time
	 */
	void setCurrentTime(unsigned int currentTime);

	/**
	 * Gets the current time.
	 * 
	 * @return unsigned the current time
	 */
	unsigned getCurrentTime() const;

	/**
	 * Gets the time of the next arrival of a client.
	 * 
	 * @return unsigned the time of the next arrival 
	 */
	unsigned getNextArrival() const;

	/**
	 * Sets the time to the next arrival of a client.
	 * 
	 * @param nextArrival the time for the next arrival 
	 */
	void setNextArrival(unsigned int nextArrival);

  private:

	/**
	 * The current time of the simulation.
	 */
	unsigned current_time;

	/**
	 * The time for the next arrival.
	 */
	unsigned next_arrival;
};


#endif //AEDA1920_FP06_TIME_MANAGER_H
