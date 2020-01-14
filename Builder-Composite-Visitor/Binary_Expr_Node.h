// -*- C++ -*-
// $Id: Binary_Expr_Node.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
* @file       Binary_Expr_Node.h
*
* $Id: Binary_Expr_Node.h 380 2010-02-08 05:10:33Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _BINARY_EXPR_NODE_H_
#define _BINARY_EXPR_NODE_H_

#include "Expr_Node.h"

//Binary_Expr_Node has only 2 children
class Binary_Expr_Node : public Expr_Node
{
public:

	//constructor
	Binary_Expr_Node(Expr_Node * left, Expr_Node * right);

	//destructor
	virtual ~Binary_Expr_Node(void);

	//get left node
	Expr_Node* getRight() const;

	//get right node
	Expr_Node * getLeft() const;

protected:
	Expr_Node * right_;
	Expr_Node * left_;
};

#endif