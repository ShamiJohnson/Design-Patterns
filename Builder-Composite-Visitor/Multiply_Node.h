// -*- C++ -*-
// $Id: Multiply_Node.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
* @file       Multiply_Node.h
*
* $Id: Multiply_Node.h 380 2010-02-08 05:10:33Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _MULTIPLY_NODE_H_
#define _MULTIPLY_NODE_H_

#include "Binary_Expr_Node.h"
#include "Expr_Node_Visitor.h"

//COMMENT: Please seperate this file into a .h and .cpp
//RESPONSE: OKay I added a new file split the code between them.
//New filename: Multiply_Node.cpp


//Multiply Node
class Multiply_Node : public Binary_Expr_Node
{
public:

	//constructor
	Multiply_Node(Expr_Node * left, Expr_Node * right);

	//destructor
	virtual ~Multiply_Node(void);

	//Accept method passes
	//control to concrete visitor
	virtual void accept(Expr_Node_Visitor & v);
};

#endif