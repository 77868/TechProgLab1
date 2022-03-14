#ifndef QUEUE2_H
#define QUEUE2_H
#include "queue.h"
class Queue2 :protected Queue
{
public:
	void showQueue(void);
	bool isEmpty(void);
	void push(int value);
	int pop(void);
	int getLength(void);
	int countOverAverage(void);
	void showCOA(void);
	Queue2() :Queue() {};
	Queue2(const Queue2& queue) :Queue(queue) {};
	Queue2(const Queue2& queue1, const Queue2& queue2) :Queue(queue1, queue2) {};
	Queue2* copy(void);
	
};

#endif 