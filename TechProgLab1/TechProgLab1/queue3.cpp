#include "queue3.h"
#include <iostream>
int Queue3::countOverAverage()
{
	if (getLength() == 0)
		return 0;
	int sum = 0;
	for (node* currentPtr = getFirst(); currentPtr != nullptr; currentPtr = currentPtr->next)
	{
		sum += currentPtr->value;
	}
	double averageValue = ((double)sum) / (getLength());
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
void Queue3::showCOA()
{
	std::cout << "amount of numbers greater than the average: " << countOverAverage() << std::endl;
}
Queue3* Queue3::copy(void)
{
	Queue3* newQueue = new Queue3(*this);
	return newQueue;
}
void  Queue3::push(int value)
{
	Queue::push(value);
}
int  Queue3::pop(void)
{
	return Queue::pop();
}
bool  Queue3::isEmpty(void)
{
	return Queue::isEmpty();
}
int  Queue3::getLength()
{
	return Queue::getLength();
}
void Queue3::showQueue(void)
{
	Queue::showQueue();
}