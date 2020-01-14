// -*- C++ -*-
// $Id: Expr_Tree_Builder.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
* @file       Expr_Tree_Builder.h
*
* $Id: Expr_Tree_Builder.h 380 2010-02-08 05:10:33Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EXPR_TREE_BUILDER_H_
#define _EXPR_TREE_BUILDER_H_

#include "Addition_Node.h"
#include "Number_Node.h"
#include "Subtraction_Node.h"
#include "Expr_Node.h"
#include "Expr_Builder.h"
#include "Variable_Node.h"
#include "Multiply_Node.h"
#include "Divide_Node.h"
#include "Modulus_Node.h"
#include "Stack.h"

//Expr_Tree_Builder class
class Expr_Tree_Builder: public Expr_Builder
{
public:

	//constructor
	Expr_Tree_Builder(void);

	//destructor
	virtual ~Expr_Tree_Builder(void);

	//start expression
	virtual void start_expression(void);

	virtual void build_number(int n);

	virtual void build_variable(char var);

	virtual void build_add_operator(void);

	virtual void build_subtract_operator(void);
	
	virtual void build_modulus_operator(void);

	virtual void build_multiply_operator(void);

	virtual void build_divide_operator(void);

	virtual void build_open_parenthesis(void);

	virtual void build_close_parenthesis(void);

	// get the current expression
	virtual Expr_Node * get_expression(void);

	//end expression
	virtual void end_expression(void);

private:
	// current state of expression tree
	Expr_Node * tree_;

	//stack of nodes
	Stack <Expr_Node*> nodeStack;

	//stack of operators
	Stack <char> operStack;

	//process operator
	void process_operator(char oper);

	//create node	
	void build_node(char oper);

	/**
	* calculate the priority of the operation
	*
	* @param op % + - * /
	* @return priority
	*/
	int priority(char op);
};

#endif