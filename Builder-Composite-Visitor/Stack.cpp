// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef STACK_CPP
#define STACK_CPP

#include "Stack.h"

//
// Stack
//
template <typename T>
Stack <T>::Stack (void): array(DEFAULT_SIZE)
{
	topIndex = -1;
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
{
	topIndex = stack.topIndex;
	array = stack.array;
	topIndex = stack.topIndex;
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{

}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
	if (topIndex + 1 == array.size()) //full ?
	{
		array.resize(topIndex * 2);
	}

	topIndex++;

	array[topIndex] = element;
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
	if (topIndex == -1)
	{
		throw empty_exception();		
	}
	topIndex--;
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	if (this != &rhs){ //self assignment check

		topIndex = rhs.topIndex;
		array = rhs.array;
		topIndex = rhs.topIndex;
	}

	return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
	topIndex = -1;
}

#endif