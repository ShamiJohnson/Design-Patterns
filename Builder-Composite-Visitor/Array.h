// -*- C++ -*-
// $Id: Array.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * @file       Array.h
 *
 * $Id: Array.h 380 2010-02-08 05:10:33Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cstring>          // for size_t definition
#include <cstdlib>
#include <iostream>
#include <cstddef> //for using NULL or nullptr
using namespace std;

#include "Array_Base.h"

/**
 * @class Array
 *
 * Basic implementation of a standard array class for chars.
 */
template <typename T>
class Array: public Array_Base<T>
{
public:
  /// Type definition of the element type.
  typedef T type;

  /// Default constructor.
  Array (void);

  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   */
  Array (size_t length);

  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   * @param[in]      fill          Initial value for each element
   */
  Array (size_t length, T fill);

  /**
   * Copy constructor
   *
   * @param[in]     arr         The source array.
   */
  Array (const Array & arr);

  /// Destructor.
  ~Array (void);

  const Array <T> & operator = (const Array & rhs);

};

#include "Array.inl"
#include "Array.cpp"

#endif   // !defined _ARRAY_H_
