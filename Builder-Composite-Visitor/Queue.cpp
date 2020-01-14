// $Id: Queue.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "Queue.h"

//
// Queue
//
template <typename T>
Queue <T>::Queue (void): array(DEFAULT_SIZE)
{
	front = 0;
	rear = -1;
	numElements = 0;
}

//
// Queue
//
template <typename T>
Queue <T>::Queue (const Queue & rhs)
{
	rhs = rhs.topIndex;
	array = rhs.array;

	front = rhs.front;
	rear = rhs.rear;
	numElements = rhs.numElements;
}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void)
{

}

//
// enqueue
//
template <typename T>
void Queue <T>::enqueue (T element)
{
	if (numElements == array.size()) //full ?
	{
		//temp array
		Array<T> temp(numElements);
		int current = front;
		for (int i = 0; i < numElements; i++)
		{
			temp[i] = array[current];
			current = (current + 1) % array.size();
		}

		array.resize(numElements * 2);

		//copy to array
		for (int i = 0; i < numElements; i++)
		{
			array[i] = temp[i];
		}
		front = 0;
		rear = numElements - 1;
	}

	rear = (rear + 1) % array.size();
	array[rear] = element;

	numElements++;
}

//
// dequeue
//

template <typename T>
void Queue <T>::dequeue (void)
{
	if (numElements == 0)
	{
		throw empty_exception();
	}
	
	front = (front + 1) % array.size();

	numElements--;
}

//
// operator =
//
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
	if (this != &rhs){ //self assignment check

		array = rhs.array;

		front = rhs.front;
		rear = rhs.rear;
		numElements = rhs.numElements;
	}

	return *this;
}

//
// clear
//
template <typename T>
void Queue <T>::clear (void)
{
	front = 0;
	rear = 0;
	numElements = 0;
}

#endif