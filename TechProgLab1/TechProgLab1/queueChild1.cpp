#include "queueChild1.h"
#include <iostream>
int queueChild1::countOverAverage()
{
	if (getLength() == 0)
		return 0;
	int sum=0;

}
void queueChild1::showCOA()
{
	std::cout <<countOverAverage() ;
}
queueChild1* queueChild1::copy(void)
{
	queueChild1* newQueue = new queueChild1(*this);
	return newQueue;
}

queueChild1* mergeQ(queueChild1 queue1, queueChild1 queue2)
{
	queueChild1* newQueue = new queueChild1(queue1, queue2);
	return newQueue;
}