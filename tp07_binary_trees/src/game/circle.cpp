#include "circle.h"

Circle::Circle(int score, bool to_right) : score(score), to_right(to_right), visit_count(0) {}

void Circle::changeState() {
	to_right = !to_right;
}

int Circle::getScore() const {
	return score;
}

bool Circle::isToRight() const {
	return to_right;
}

int Circle::getVisitCount() const {
	return visit_count;
}

void Circle::addVisit() {
	this->visit_count = visit_count + 1;
}
