// -*- C++ -*-
// $Id: Divide_Node.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
* @file       Divide_Node.h
*
* $Id: Divide_Node.h 380 2010-02-08 05:10:33Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _DIVIDE_NODE_H_
#define _DIVIDE_NODE_H_

#include "Binary_Expr_Node.h"
#include "Expr_Node_Visitor.h"

//Divide Node
class Divide_Node : public Binary_Expr_Node
{
public:

	//constructor
	Divide_Node(Expr_Node * left, Expr_Node * right);

	//destructor
	virtual ~Divide_Node(void);


	//Accept method passes
	//control to concrete visitor
	virtual void accept(Expr_Node_Visitor & v);
};

#endif