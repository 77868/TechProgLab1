#include "queue2.h"
#include <iostream>
int Queue2::countOverAverage()
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
void Queue2::showCOA()
{
	std::cout << "amount of numbers greater than the average: " << countOverAverage() << std::endl;
}
Queue2* Queue2::copy(void)
{
	Queue2* newQueue = new Queue2(*this);
	return newQueue;
}
void  Queue2::push(int value)
{
	Queue::push(value);
}
int  Queue2::pop(void)
{
	return Queue::pop();
}
bool  Queue2::isEmpty(void)
{
	return Queue::isEmpty();
}
int  Queue2::getLength()
{
	return Queue::getLength();
}
void Queue2::showQueue(void)
{
	Queue::showQueue();
}