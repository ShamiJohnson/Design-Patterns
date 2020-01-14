// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef FIXED_ARRAY_CPP
#define FIXED_ARRAY_CPP

#include "Fixed_Array.h"

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void): Array_Base<T>(N)
{
	
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr): Array_Base<T>(N)
{
	for (int i = 0; i < N; i++)
	{
		Array_Base<T>::operator[](i) = arr[i];
	}
}

//
// Fixed_Array
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr): Array_Base<T>(N)
{
	for (int i = 0; i < M && i < N; i++)
	{
		Array_Base<T>::operator[](i) = arr[i];
	}
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill):Array_Base<T>(N, fill)
{
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{

}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	if (this != &rhs){

		for (int i = 0; i < N; i++)
		{
			Array_Base<T>::operator[](i) = rhs[i];
		}

	}
	return *this;
}

//
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
	if (this != &rhs){

		Array_Base<T>::resize(0);
		Array_Base<T>::resize(N);

		for (int i = 0; i < N; i++)
		{
			Array_Base<T>::operator[](i) = rhs[i];
		}

	}
	return *this;
}

#endif