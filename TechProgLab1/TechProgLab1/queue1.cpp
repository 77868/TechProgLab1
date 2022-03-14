#include "Queue1.h"
#include <iostream>
int Queue1::countOverAverage()
{
	if (getLength() == 0)
		return 0;
	int sum = 0;
	for (node* currentPtr = getFirst(); currentPtr!=nullptr ; currentPtr=currentPtr->next)
	{
		sum += currentPtr->value;
	}
	double averageValue = ((double)sum)/(getLength());
	int count = 0;
	for (node* currentPtr = getFirst(); currentPtr != nullptr; currentPtr = currentPtr->next)
	{
		if (((double)currentPtr->value) > averageValue)
		{
			count++;
		}
	}
	return count;
}
void Queue1::showCOA()
{
	std::cout <<"amount of numbers greater than the average: " << countOverAverage()<<std::endl;
}
Queue1* Queue1::copy(void)
{
	Queue1* newQueue = new Queue1(*this);
	return newQueue;
}
void  Queue1::push(int value)
{
	Queue::push(value);
}
int  Queue1::pop(void)
{
	return Queue::pop();
}
bool  Queue1::isEmpty(void)
{
	return Queue::isEmpty();
}
int  Queue1::getLength()
{
	return Queue::getLength();
}
void Queue1::showQueue(void)
{
	Queue::showQueue();
}
