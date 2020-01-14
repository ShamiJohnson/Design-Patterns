// -*- C++ -*-
// $Id: Variable_Node.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
* @file       Variable_Node.h
*
* $Id: Variable_Node.h 380 2010-02-08 05:10:33Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _VARIABLE_NODE_H_
#define _VARIABLE_NODE_H_

#include "Expr_Node.h"
#include "Expr_Node_Visitor.h"
#include "Array.h"

//Variable_Node reprensents the variable node
class Variable_Node : public Expr_Node
{
public:

	//constructor
	Variable_Node(char var);

	//destructor
	virtual ~Variable_Node(void);

	//get variable
	char getVar() const;

	// Used to traverse the tree
	virtual void accept(Expr_Node_Visitor &v);

private:
	char var_;
};

#endif