// -*- C++ -*-
// $Id: Addition_Node.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
* @file       Addition_Node.h
*
* $Id: Addition_Node.h 380 2010-02-08 05:10:33Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _ADDITION_NODE_H_
#define _ADDITION_NODE_H_

#include "Binary_Expr_Node.h"
#include "Expr_Node_Visitor.h"

//Binary_Expr_Node reprensents the add expression node
class Addition_Node : public Binary_Expr_Node
{
public:

	//constructor
	Addition_Node(Expr_Node * left, Expr_Node * right);

	//destructor
	virtual ~Addition_Node(void);

	//Accept method passes
	//control to concrete visitor
	virtual void accept(Expr_Node_Visitor & v);
};

#endif