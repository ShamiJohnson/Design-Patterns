// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

#ifndef ARRAY_CPP
#define ARRAY_CPP

//
// Array
//
template <typename T>
Array <T>::Array (void)
{
	
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length): Array_Base<T>(length)
{
	
}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill): Array_Base<T>(length, fill)
{

}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array): Array_Base<T>(array.size())
{
	for (size_t i = 0; i < array.size(); i++)
	{
		Array_Base<T>::operator[](i) = array[i];
	}
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
	
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	if (this != &rhs){

		Array_Base<T>::resize(0);
		Array_Base<T>::resize(rhs.size());

		for (int i = 0; i < rhs.size(); i++)
		{
			Array_Base<T>::operator[](i) = rhs[i];
		}

	}
	return *this;
}


#endif