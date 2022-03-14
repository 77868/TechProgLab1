#ifndef QUEUE1_H
#define QUEUE1_H
#include "queue.h"
class Queue1 :public Queue
{
public:
	void showQueue(void);
	bool isEmpty(void);
	void push(int value);
	int pop(void);
	int getLength(void);
	int countOverAverage(void);
	void showCOA(void);
	Queue1() :Queue() {};
	Queue1(const Queue1& queue) :Queue(queue) {};
	Queue1(const Queue1& queue1, const Queue1& queue2) :Queue(queue1, queue2) {};
	Queue1* copy(void);
};
#endif