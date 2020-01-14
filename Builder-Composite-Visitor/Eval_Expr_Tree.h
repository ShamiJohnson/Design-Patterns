// -*- C++ -*-
// $Id: Eval_Expr_Tree.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
* @file       Eval_Expr_Tree.h
*
* $Id: Eval_Expr_Tree.h 380 2010-02-08 05:10:33Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EVAL_EXPR_TREE_H_
#define _EVAL_EXPR_TREE_H_

#include "Expr_Node_Visitor.h"
#include "Addition_Node.h"
#include "Subtraction_Node.h"
#include "Number_Node.h"
#include "Divide_Node.h"
#include "Modulus_Node.h"
#include "Multiply_Node.h"
#include "Variable_Node.h"

#include <iostream>
#include <exception>
#include <string>
#include <sstream>

//Eval_Expr_Tree
class Eval_Expr_Tree : public Expr_Node_Visitor {
public:
	
	Eval_Expr_Tree(void);
	
	virtual ~Eval_Expr_Tree(void);

	// Methods for visiting concrete nodes
	virtual void Visit_Addition_Node(const Addition_Node & node);

	virtual void Visit_Subtraction_Node(const Subtraction_Node & node);

	virtual void Visit_Multiply_Node(const Subtraction_Node & node);

	virtual void Visit_Variable_Node(const Variable_Node &node);

	virtual void Visit_Divide_Node(const Divide_Node &node);

	virtual void Visit_Modulus_Node(const Modulus_Node &node);

	virtual void Visit_Multiply_Node(const Multiply_Node &node);

	virtual void Visit_Number_Node(const Number_Node & node);

	virtual int result(void) const;

private:

	int result_;

	Array<char> variables;
	Array<int> values;

	int index; //index of array

};

#endif