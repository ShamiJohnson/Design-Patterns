// -*- C++ -*-
// $Id: Expr_Node.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
* @file       Expr_Node.h
*
* $Id: Expr_Node.h 380 2010-02-08 05:10:33Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EXPR_NODE_H_
#define _EXPR_NODE_H_

#include "Expr_Node_Visitor.h"

//Expr_Node provide common functionality to the
//subclasses that are binary operators
class Expr_Node
{
public:
	
	//constructor
	Expr_Node(void) {}

	//destructor
	virtual ~Expr_Node(void) {}
	
	// Used to traverse the tree
	virtual void accept(Expr_Node_Visitor &v) = 0;
};

#endif