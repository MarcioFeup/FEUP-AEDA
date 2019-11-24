#include "circle.h"

Circle::Circle(int score, bool state) : score(score), state(state), visit_count(0) {}

void Circle::changeState() {
	state = !state;
}

int Circle::getScore() const {
	return score;
}

bool Circle::getState() const {
	return state;
}

int Circle::getVisitCount() const {
	return visit_count;
}

void Circle::addVisit() {
	this->visit_count = visit_count + 1;
}
