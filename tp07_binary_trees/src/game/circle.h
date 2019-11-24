#ifndef AEDA1920_FP07_CIRCLE_H
#define AEDA1920_FP07_CIRCLE_H


#include <ostream>

class Circle {
  public:
	explicit Circle(int score = 0, bool state = false);

	void changeState();

	int getScore() const;

	bool getState() const;

	int getVisitCount() const;

	void addVisit();

	friend std::ostream &operator<<(std::ostream &os, Circle &circle);

  private:
	int score;

	bool state;

	int visit_count;
};


#endif //AEDA1920_FP07_CIRCLE_H
