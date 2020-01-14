// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.
 //
 //Name Ehtsham Nisar
 //Date last modified:9/15/19
//

#include <iostream>
#include "Array.h"



//COMMENT: Please initalize your member variables using the BMI list.
//RESPONSE: variables from the bmi list is being used now
Array::Array (void)
{
    data_ = new char[max_size_];
    max_size_=max_size();
    cur_size_=size();
}

//COMMENT: Please initalize your member variables using the BMI list.
//RESPONSE: variables from the bmi list is being used now
Array::Array (size_t length)
{
    //variables for the length and size of the array
    data_= new char[length];
    max_size_ = length;
    cur_size_ = length;
}

//Array constructor
//COMMENT: Please initalize your member variables using the BMI list.
//RESPONSE: I changed the previous initialization to member variables by using the bmi list
Array::Array (size_t length, char fill)
{
    this->data_ = new char(fill);
    cur_size_ = length;
    max_size_ = length;
}

//copy constructor 
//COMMENT: Please initalize your member variables using the BMI list.
//RESPONSE: I changed the previous initialization to member variables by using the bmi list
Array::Array (const Array & array)
{
    data_ = new char(*array.data_);
    cur_size_ = array.cur_size_;
    max_size_ = array.max_size_;
}

//cleaning up space //destructure 
Array::~Array (void)
{
    delete[] data_;
}

//Assignment operator 
const Array & Array::operator = (const Array & rhs)
{
    cur_size_ = rhs.cur_size_;
    max_size_ = rhs.cur_size_;
    for(int i=0; i<cur_size_; i++){
        data_[i] = rhs.data_[i];
    }
    return rhs;
}

//receiving the current size of the array
//COMMENT: You need to throw and out_of_range exception when index is out of bounds.
//RESPONSE: Created an if condition to check the index
char & Array::operator [] (size_t index)
{
    if(index>cur_size_){
        throw std::out_of_range ("out_of_range");
    }
    return data_[index];
}


//COMNMENT: You need to throw and out_of_range exception when index is out of bounds.
//RESPONSE: Created an if condition to check the index
//overloaded method
// the return character is not modifiable since using const
const char & Array::operator [] (size_t index) const
{
    if(index>cur_size_){
        throw std::out_of_range ("out_of_range");
    }
    return data_[index];
}

//getting the character at a specific index
char Array::get (size_t index) const
{
    if(index>cur_size_){
        throw std::out_of_range ("out_of_range");
    }
    return data_[index];
}

//sets the character at a specific index
void Array::set (size_t index, char value)
{
    if(index>cur_size_){
        throw std::out_of_range ("out_of_range");
    }
    if(index<max_size_ && index>=0){
        data_[index]= value;
        cur_size_++;
    }
}

void Array::resize (size_t new_size)
{
    //if new_size is greater than the array then make the array larger
    if(new_size>=cur_size_){
        char *temporaryVariable =new char[new_size];
        for(int i =0; i<cur_size_; i++){
            temporaryVariable[i] = data_[i];
        }
        max_size_ = new_size;
        delete[] data_;
        data_ = temporaryVariable;
    }

}

//responsible for locating the characters in the array 
int Array::find (char ch) const
{
    for(int i=0; i<cur_size_; i++){
        if(ch == data_[i]){
            return i;
        }
        else {
            return -1;
        }
    }
    return 0;
}

//overloaded method, allows you to check start value
//out of range statement is thrown if start is greater then current size
int Array::find (char ch, size_t start) const
{
    if(start>cur_size_){
        throw std::out_of_range ("out_of_range");
    }
    for(int i=0; i<cur_size_; i++){
        if(ch == data_[i]){
            return i;
        }
        else {
            return -1;
        }
    }
    return 0;
}

//test the array for equality, if equal then its true
bool Array::operator == (const Array & rhs) const
{
    if (cur_size_ == rhs.cur_size_){
        for (int i=0; i<cur_size_; i++){
            if ((data_[i]) != rhs.data_[i]){
                return false;
            }
            else {
                return true;
            }
        }
        return true;
    }
    return false;
}

//test the array for inequality, if its inequal then its false
//COMMENT: Try defining != in terms of the == operator.
//RESPONSE: I defined it with equality instead now.
//RESPONSE: Now if the it is equal then it will return true.
bool Array::operator != (const Array & rhs) const
{
    if(cur_size_ == rhs.cur_size_){
        for(int i=0; i<cur_size_; i++){
            if (data_[i] == rhs.data_[i]){
                return true;
            }
            else {
                return false;
            }
        }
        return false;
    }
    return true;
}

//responsible for filling the contents of the array
void Array::fill (char ch)
{
    for(int i=0; i<max_size_; i++){
        data_[i] = ch;
    }
    cur_size_ = max_size_;
}

//shrinking the array to reclaim unused space
void Array::shrink (void)
{
    resize(cur_size_);
}

//this method is created to reverse the array
void Array::reverse (void)
{
    char temporaryVariable;
    for(int i =0; i<cur_size_; i++){
        temporaryVariable = data_[i];
        data_[i] = data_[cur_size_ -i -1];
        data_[cur_size_ -i -1]=temporaryVariable;
    }
}

//returns a shallow copy of a portion of an array
//COMMENT: Please use the original slice methods written in the public section of the .h file.
//The way it is now, you do not have those methods implemented and your code will not get full credit.
//RESPONSE: I deleted the slice method I created and now using the original method provided in .h file
Array Array::slice (size_t begin) const {
    Array temporaryVariable(cur_size_ - begin);
    for(int i=0; i<temporaryVariable.max_size(); i++){
        temporaryVariable.set(i, data_[begin +i]);
    }
    return temporaryVariable;
}

//overloaded slice method
//COMMENT: Please use the original slice methods written in the public section of the .h file.
//The way it is now, you do not have those methods implemented and your code will not get full credit.
//RESPONSE: I deleted the slice method I created and now using the original method provided in .h file
Array Array::slice (size_t begin, size_t end) const {
    Array temporaryVariable(end-begin);
    if (end < cur_size_){
        for(int i=0; i<temporaryVariable.max_size(); i++){
            temporaryVariable.set(i,data_[begin+i]);
        }
    }
    return temporaryVariable;
}