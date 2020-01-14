// -*- C++ -*-
// $Id: Expr_Builder.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
* @file       Expr_Builder.h
*
* $Id: Expr_Builder.h 380 2010-02-08 05:10:33Z hillj $
*
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _EXPR_BUILDER_H_
#define _EXPR_BUILDER_H_

#include "Expr_Node.h"

//Expr_Builder interface
class Expr_Builder
{
public:
	//start
	virtual void start_expression(void) = 0;

	virtual void build_number(int n) = 0;
	virtual void build_variable(char var) = 0;
	virtual void build_add_operator(void) = 0;
	virtual void build_subtract_operator(void) = 0;
	virtual void build_modulus_operator(void) = 0;
	virtual void build_multiply_operator(void) = 0;
	virtual void build_divide_operator(void) = 0;
	virtual void build_open_parenthesis(void) = 0;
	virtual void build_close_parenthesis(void) = 0;

	//end expression
	virtual void end_expression(void) = 0;

	// get the current expression
	virtual Expr_Node * get_expression(void) = 0;
	
	virtual ~Expr_Builder(){}
};

#endif