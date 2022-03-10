#ifndef QUEUE_CHILD_1_H
#define QUEUE_CHILD_1_H
#include "queue.h"
class queueChild1 :public Queue
{
public:
	int countOverAverage(void);
	void showCOA(void);
	queueChild1() :Queue() {};
	queueChild1(const queueChild1& queue) :Queue(queue) {};
	queueChild1(const queueChild1& queue1, const queueChild1& queue2) :Queue(queue1,queue2) {};
	queueChild1* copy(void);
};
queueChild1* mergeQ(queueChild1 q1, queueChild1 q2);
#endif QUEUE_CHILD_1_H