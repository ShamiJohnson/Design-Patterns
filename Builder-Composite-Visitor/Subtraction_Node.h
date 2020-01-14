// -*- C++ -*-
// $Id: Subtraction_Node.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
* @file       Subtraction_Node.h
*
* $Id: Subtraction_Node.h 380 2010-02-08 05:10:33Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _SUBTRACTION_NODE_H_
#define _SUBTRACTION_NODE_H_

#include "Binary_Expr_Node.h"
#include "Expr_Node_Visitor.h"

//Subtraction_Node
class Subtraction_Node : public Binary_Expr_Node
{
public:

	//constructor
	Subtraction_Node(Expr_Node * left, Expr_Node * right);

	//destructor
	virtual ~Subtraction_Node(void);
	
	//Accept method passes
	//control to concrete visitor
	virtual void accept(Expr_Node_Visitor & v);
};

#endif