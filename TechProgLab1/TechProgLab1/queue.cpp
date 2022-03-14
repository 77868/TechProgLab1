#include "queue.h"
#include <iostream>

bool Queue::isEmpty(void)
{
	return (length > 0) ? false : true;
}
int Queue::getLength(void)
{
	return length;
}
void Queue::init(void)
{
	length = 0;
	node* tmp = new node;
	tmp->prev = nullptr;
	tmp->next = nullptr;
	first = last = tmp;
}
node* Queue::getFirst() { return first;}
node* Queue::getLast() { return last; }

void Queue::push(int value)
{
	
	if (length>0)
	{
		node* tmp = new node;
		last->next = tmp;
		tmp->prev = last;
		tmp->next = nullptr;
		last = tmp;
	}
	last->value = value;
	length++;
 }
int Queue::pop(void)
{
	int returnValue = first->value;
	if (first->next!=nullptr)
	{
		node* tmp = first;
		first = first->next;
		first->prev = nullptr;
		delete(tmp);
	}
	length--;
	return returnValue;
}

Queue* Queue::copy(void)
{
	Queue* copiedQ = new Queue(*this);
	return copiedQ;
}

Queue::Queue()
{
	init();
}
Queue::Queue(const Queue& original)
{
	init();
	if (original.length>0)
	{
		node* currentPtr = original.first;
		this->push(currentPtr->value);
		while (currentPtr->next != nullptr)
		{
			currentPtr = currentPtr->next;
			this->push(currentPtr->value);
		}
	}
}
Queue::Queue(const Queue& queue1, const Queue& queue2)
{
	init();
	if (queue1.length > 0)
	{
		node* currentPtr = queue1.first;
		this->push(currentPtr->value);
		while (currentPtr->next != nullptr)
		{
			currentPtr = currentPtr->next;
			this->push(currentPtr->value);
		}
	}
	if (queue2.length > 0)
	{
		node* currentPtr = queue2.first;
		this->push(currentPtr->value);
		while (currentPtr->next != nullptr)
		{
			currentPtr = currentPtr->next;
			this->push(currentPtr->value);
		}
	}
}

Queue::~Queue()
{	
	node* currentPtr=first;
	while (currentPtr->next!=nullptr)
	{
		if (currentPtr->prev != nullptr)
		{
			delete currentPtr->prev;
		}
		currentPtr = currentPtr->next;
	}
	delete currentPtr;
}

void Queue::showQueue(void) 
{
	Queue tmp(*this);
	while (!tmp.isEmpty())
	{
		std::cout << tmp.pop() << ' ';
	}
	std::cout << "\n";
}