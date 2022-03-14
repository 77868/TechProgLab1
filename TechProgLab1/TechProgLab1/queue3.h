#ifndef QUEUE_CHILD_3_H
#define QUEUE_CHILD_3_H
#include "queue.h"
class Queue3 :private Queue
{
public:
	void showQueue(void);
	bool isEmpty(void);
	void push(int value);
	int pop(void);
	int getLength(void);
	int countOverAverage(void);
	void showCOA(void);
	Queue3() :Queue() {};
	Queue3(const Queue3& queue) :Queue(queue) {};
	Queue3(const Queue3& queue1, const Queue3& queue2) :Queue(queue1, queue2) {};
	Queue3* copy(void);
};

#endif 