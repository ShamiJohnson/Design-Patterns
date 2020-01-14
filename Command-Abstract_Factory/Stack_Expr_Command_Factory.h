// -*- C++ -*-
// $Id: Array.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * @file       Array.h
 *
 * $Id: Array.h 380 2010-02-08 05:10:33Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================
#ifndef _STACK_EXPR_COMMAND_H_
#define _STACK_EXPR_COMMAND_H_

#include "Expr_Command_Factory.h"
#include "Stack.h"
#include "Number_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulus_Command.h"

//stack expression command factor
class Stack_Expr_Command_Factory: public Expr_Command_Factory
{
public:

	//constructor
	Stack_Expr_Command_Factory (Stack <int> & stack);
	
	//destructor
	virtual ~Stack_Expr_Command_Factory (void);

	//number command
	virtual Number_Command * create_number_command (int num);

	//add command
	virtual Add_Command * create_add_command (void);

	//substract command
	virtual Subtract_Command * create_subtract_command (void);

	//multiply command
	virtual Multiply_Command * create_multiply_command (void);

	//divide command
	virtual Divide_Command * create_divide_command (void);

	//modulus command
	virtual Modulus_Command * create_modulus_command (void);

private:
	Stack <int> & stack_;

};

#endif