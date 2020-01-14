// $Id: Array_Base.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array_Base.h"
#include <stdexcept>         // for std::out_of_bounds exception

#ifndef ARRAY_BASE_CPP
#define ARRAY_BASE_CPP

//
// Array_Base
//
template <typename T>
Array_Base <T>::Array_Base (void)
{
	data_ = nullptr;
	cur_size_ = 0;
	max_size_ = 0;
}

//
// Array_Base (size_t)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length)
{
	data_ = new T[length];
	cur_size_ = length;
	max_size_ = length;
}

//
// Array_Base (size_t, char)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill)
{
	data_ = new T[length];
	cur_size_ = length;
	max_size_ = length;

	for (size_t i = 0; i < length; i++)
	{
		data_[i] = fill;
	}
}

//
// Array_Base (const Array_Base &)
//
template <typename T>
Array_Base <T>::Array_Base (const Array_Base & rhs)
{
	data_ = new T[rhs.max_size_];
	cur_size_ = rhs.cur_size_;
	max_size_ = rhs.max_size_;

	//copy data
	for (size_t i = 0; i < max_size_; i++)
	{
		data_[i] = rhs.data_[i];
	}
}

//
// ~Array_Base
//
template <typename T>
Array_Base <T>::~Array_Base (void)
{
	if (data_ != nullptr)
	{
		delete [] data_;
		data_ = nullptr;
	}
	
	cur_size_ = 0;
	max_size_ = 0;
}

//
// operator =
//
template <typename T>
const Array_Base <T> & Array_Base <T>::operator = (const Array_Base & rhs)
{
	if (this != &rhs){

		//clear current data
		if (data_ != nullptr)
		{
			delete [] data_;
		}
		
		data_ = new T[rhs.max_size];
		cur_size_ = rhs.cur_size_;
		max_size_ = rhs.max_size_;

		//copy data
		for (size_t i = 0; i < max_size_; i++)
		{
			data_[i] = rhs.data_[i];
		}

	}
	return *this;
}

//
// operator []
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
	//If the index is not within the range of the Array_Base, then std::out_of_range exception
	//is thrown.
	if (index < 0 || index >= max_size_)
	{
		throw std::out_of_range("Index is out of range");
	}
	return data_[index];
}

//
// operator [] 
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
	//If the index is not within the range of the Array_Base, then std::out_of_range exception
	//is thrown.
	if (index < 0 || index >= max_size_)
	{
		throw std::out_of_range("Index is out of range");
	}
	return data_[index];
}

//
// get
//

template <typename T>
T Array_Base <T>::get (size_t index) const
{
	//If the index is not within the range of the Array_Base, then std::out_of_range exception
	//is thrown.
	if (index < 0 || index >= max_size_)
	{
		throw std::out_of_range("index is out of range");
	}
	return data_[index];
}

//
// set
//
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
	//If the index is not within the range of the Array_Base, then std::out_of_range exception
	//is thrown.
	if (index < 0 || index >= max_size_)
	{
		throw std::out_of_range("Index is out of range");
	}
	data_[index] = value;
}

/**
* Set a new size for the Array_Base. If \a new_size is less than the current
* size, then the Array_Base is truncated. If \a new_size if greater then the
* current size, then the Array_Base is made larger and the new elements are
* not initialized to anything. If \a new_size is the same as the current
* size, then nothing happens.
*
* The Array_Base's original contents are preserved regardless of whether the 
* Array_Base's size is either increased or decreased.
*
* @param[in]       new_size              New size of the Array_Base
*/
template <typename T>
void Array_Base <T>::resize (size_t new_size)
{
	if (new_size <= 0) //empty Array_Base
	{
		if (data_ != nullptr)
		{
			delete [] data_;
			data_ = nullptr;
		}
	
		cur_size_ = 0;
		max_size_ = 0;

	}else if (max_size_ != new_size) //If \a new_size is the same as the current size, then nothing happens.
	{
		//current Array_Base
		T *current = data_;
		
		data_ = new T[new_size];

		//copy Array_Base
		for (size_t i = 0; i < new_size && i < max_size_; i++)
		{
			data_[i] = current[i];
		}

		delete[] current;

		//set new size
		max_size_ = new_size;
		cur_size_ = new_size;
	}
}

//
// find (char)
//
template  <typename T>
int Array_Base <T>::find (T value) const
{
	//iterate and find
	for (size_t i = 0; i < max_size_; i++)
	{
		if (data_[i] == value)
		{
			return i;
		}
	}

	return -1;
}

//
// find (char, size_t) 
//
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
	//If the start is not within the range of the Array_Base, then std::out_of_range exception
	//is thrown.
	if (start < 0 || start >= max_size_)
	{
		throw std::out_of_range("Start is out of range");
	}

	//iterate and find
	for (size_t i = start; i < max_size_; i++)
	{
		if (data_[i] == val)
		{
			return i;
		}
	}

	return -1;
}

//
// operator ==
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
	if (max_size_ == rhs.max_size_)
	{
		//iterate and compare data
		for (size_t i = 0; i < max_size_; i++)
		{
			if (data_[i] !=  rhs.data_[i])
			{
				return false;
			}
		}

		return true;

	}else{ //not equal sizes
		return false;
	}
}

//
// operator !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
	return !(*this == rhs);
}

//
// fill
//
template <typename T>
void Array_Base <T>::fill (T value)
{
	for (size_t i = 0; i < max_size_; i++)
	{
		data_[i] = value;
	}
}

#endif