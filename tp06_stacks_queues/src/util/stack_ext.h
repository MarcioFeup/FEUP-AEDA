# include <iostream>
# include <stack>
#include "../exception/empty_queue.h"

using namespace std;

/**
 * Represents an extended stack, this is, a stack that keeps tracking of its minimum values.
 * 
 * @tparam T the type of elements the stack contains
 */
template<class T>
class StackExt : public stack<T> {

  public:

	/**
	 * Constructs a new empty stack.
	 */
	StackExt() {};

	/**
	 * Finds the minimum element of the stack.
	 * 
	 * @return T& the minimum element of the stack 
	 */
	T &findMin() {
		if (minimums.empty())
			throw EmptyQueueException();
		return minimums.top();
	}

	/**
	 * Removes the top element of the stack, updating the minimum values.
	 */
	void pop() {
		if (this->empty())
			throw EmptyQueueException();
		if (this->top() == minimums.top())
			minimums.pop();
		stack<T>::pop();
	}

	/**
	 * Adds an element to the top of the stack, updating the minimum values.
	 * 
	 * @param val the element to add 
	 */
	void push(const T &val) {
		if (minimums.empty() || val <= minimums.top())
			minimums.push(val);
		stack<T>::push(val);
	}

  private:

	/**
	 * The parallel stack that keeps track of the minimum values.
	 */
	stack<T> minimums;
};