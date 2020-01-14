// -*- C++ -*-
// $Id: Number_Node.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
* @file       Number_Node.h
*
* $Id: Number_Node.h 380 2010-02-08 05:10:33Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _NUMBER_NODE_H_
#define _NUMBER_NODE_H_

#include "Expr_Node.h"
#include "Expr_Node_Visitor.h"

//COMMENT: Please seperate this file into a .h and .cpp
//FIXED: Added Number_Node.cpp

//Number_Node reprensents the number node
class Number_Node : public Expr_Node
{
public:

	//constructor
	Number_Node(int num);

	//destructor
	virtual ~Number_Node(void);

	//evaluate
	int eval() const;

	// Used to traverse the tree
	virtual void accept(Expr_Node_Visitor &v);
private:
	int num_;
};

#endif