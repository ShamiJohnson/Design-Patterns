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

#ifndef _EXPR_NODE_VISITOR_H_
#define _EXPR_NODE_VISITOR_H_

class Number_Node;
class Addition_Node;
class Subtraction_Node;
class Divide_Node;
class Modulus_Node;
class Multiply_Node;
class Variable_Node;

// Visitor class defines an interface that visits 
//all (concrete) nodes in the structure
class Expr_Node_Visitor
{
public:

	//destructor
	virtual ~Expr_Node_Visitor(void);

	// Methods for visiting concrete nodes
	virtual void Visit_Addition_Node(const Addition_Node &node);
	virtual void Visit_Subtraction_Node(const Subtraction_Node &node);
	virtual void Visit_Number_Node(const Number_Node &node);
	virtual void Visit_Variable_Node(const Variable_Node &node);
	virtual void Visit_Divide_Node(const Divide_Node &node);
	virtual void Visit_Modulus_Node(const Modulus_Node &node);
	virtual void Visit_Multiply_Node(const Multiply_Node &node);

	//returns the result of the evaluation
	virtual int result(void) const = 0;

};

#endif