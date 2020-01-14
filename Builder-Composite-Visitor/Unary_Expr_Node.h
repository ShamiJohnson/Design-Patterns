// -*- C++ -*-
// $Id: Unary_Expr_Node.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
* @file       Unary_Expr_Node.h
*
* $Id: Unary_Expr_Node.h 380 2010-02-08 05:10:33Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _UNARY_EXPR_NODE_H_
#define _UNARY_EXPR_NODE_H_

#include "Expr_Node.h"

//COMMENT: Please seperate this file into a .h and .cpp
//RESPONSE: Okay I added a new file split the code between them.
//New filename: Unary_Expr_Node.cpp



//Unary_Expr_Node has only 1 child
class Unary_Expr_Node: public Expr_Node
{
public:

	//constructor
	Unary_Expr_Node(Expr_Node* child);

	//destructor
	virtual ~Unary_Expr_Node(void);

protected:
	Expr_Node* child_;
};

#endif