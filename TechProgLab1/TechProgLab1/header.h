#include <iostream>
#include "queue.h"
#include "queue1.h"
#include "queue2.h"
#include "queue3.h"

template <typename T>
void demonstrate();
template <typename T>
void add_queue(T** list);
template <typename T>
void remove_queue(T** list);
template <typename T>
int listIsEmpty(T** list);
template <typename T>
int listIsFull(T** list);
template <typename T>
void calculateCOA(T** list);
template <typename T>
void pushing(T** list);
template <typename T>
void poping(T** list);
template <typename T>
void copyQueue(T** list);
template <typename T>
void mergeQueue(T** list);
