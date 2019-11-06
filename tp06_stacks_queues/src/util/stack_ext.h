# include <iostream>
# include <stack>
#include "../exception/empty_queue.h"

using namespace std;

template<class T>
class StackExt : public stack<T> {

  public:
	StackExt() {};

	T &findMin() {
		if (minimums.empty())
			throw EmptyQueueException();
		return minimums.top();
	}

	void pop() {
		if (this->empty())
			throw EmptyQueueException();
		if (this->top() == minimums.top())
			minimums.pop();
		stack<T>::pop();
	}

	void push(const T &val) {
		if (minimums.empty() || val <= minimums.top())
			minimums.push(val);
		stack<T>::push(val);
	}

  private:
	stack<T> minimums;
};