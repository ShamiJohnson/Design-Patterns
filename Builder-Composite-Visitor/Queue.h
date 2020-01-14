   // -*- C++ -*-
// $Id: Queue.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_QUEUE_H_
#define _CS507_QUEUE_H_

#include <exception>

#include "Array.h"
#define DEFAULT_SIZE 10

/**
 * @class Queue
 *
 * Basic Queue for abitrary elements.
 */
template <typename T>
class Queue
{
public:
  /// Type definition of the type.
  typedef T type;

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the Queue is empty.
   */
  class empty_exception : public std::exception
  {
  public:
    /// Default constructor.
    empty_exception (void)
      : std::exception () { }
  };

  /// Default constructor.
  Queue (void);

  /// Copy constructor.
  Queue (const Queue & s);

  /// Destructor.
  ~Queue (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Queue & operator = (const Queue & rhs);

  /**
   * Push a new \a element onto the Queue. The element is inserted
   * before all the other elements in the list.
   *
   * @param[in]      element       Element to add to the list
   */
  void enqueue (T element);

  /**
   * Remove the top-most element from the Queue.
   *
   * @exception      empty_exception    The Queue is empty.
   */
  void dequeue (void);

  /**
   * Get the top-most element on the Queue. If there are no element 
   * on the Queue, then the Queue_is_empty exception is thrown.
   *
   * @return         Element on top of the Queue.
   * @exception      empty_exception    The Queue is empty
   */
  T peek (void) const;

  /**
   * Test if the Queue is empty
   *
   * @retval         true          The Queue is empty
   * @retval         false         The Queue is not empty
   */
  bool is_empty (void) const;

  /**
   * Number of element on the Queue.
   *
   * @return         Size of the Queue.
   */
  size_t size (void) const;

  /// Remove all elements from the Queue.
  void clear (void);

private:
  // add member variable here
	Array<T> array;

	int front;
	int rear;
	int numElements; //number of elements in queue
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"

#endif  // !defined _CS507_QUEUE_H_
