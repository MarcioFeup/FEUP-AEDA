#ifndef AEDA1920_FP07_CIRCLE_H
#define AEDA1920_FP07_CIRCLE_H


#include <ostream>

/**
 * Represents a circle of a game that stores its score, state (to_right), and visit count.
 */
class Circle {
  public:
	/**
	 * Constructs a circle with visit count 0.
	 *
	 * @param score the score with 0 as default
	 * @param to_right the to_right state that defines if the next circle is in the right, with false as default
	 */
	explicit Circle(int score = 0, bool to_right = false);

	/**
	 * Change the right/left state.
	 */
	void changeState();

	/**
	 * Returns the score of the circle.
	 *
	 * @return the score
	 */
	int getScore() const;

	/**
	 * Gets if the state is to right or left.
	 *
	 * @return true if it is to right, left otherwise
	 */
	bool isToRight() const;

	/**
	 * Gets the visit count.
	 *
	 * @return the visit count
	 */
	int getVisitCount() const;

	/**
	 * Increments the number of visits in the circle.
	 */
	void addVisit();

  private:
	/**
	 * The score, this is, the amount of points the circle represents.
	 */
	int score;

	/**
	 * The state that states (no pun intended) if the next circle is in the right or left.
	 * I.e. true for right, false for left.
	 */
	bool to_right;

	/**
	 * The counter of visits.
	 */
	int visit_count;
};


#endif //AEDA1920_FP07_CIRCLE_H
