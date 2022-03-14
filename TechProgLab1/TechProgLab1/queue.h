#ifndef QUEUE_H
#define QUEUE_H
#include "node.h"
class Queue
{
public:
	bool isEmpty(void);
	void push(int value);
	int pop(void);
	int getLength(void);
	void showQueue(void);
    Queue* copy(void);
	Queue();
	Queue(const Queue& queue);
	Queue(const Queue& queue1, const Queue& queue2);
	~Queue();
protected:
	node* getFirst();
	node* getLast();

private:
	void init(void);
	node* first;
	node* last;
	int length;
};

template <class T>
T* mergeQ(T q1, T q2);
#endif