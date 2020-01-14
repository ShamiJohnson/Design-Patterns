// -*- C++ -*-
// $Id: Expr_Command_Factory.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * @file       Expr_Command_Factory.h
 *
 * $Id: Expr_Command_Factory.h 380 2010-02-08 05:10:33Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _EXPR_COMMAND_FACTORY_H_
#define _EXPR_COMMAND_FACTORY_H_

#include "Number_Command.h"
#include "Add_Command.h"
#include "Subtract_Command.h"
#include "Multiply_Command.h"
#include "Divide_Command.h"
#include "Modulus_Command.h"

//COMMENT: Please put the implmentation in the proper .cpp file.
//RESPONSE: I removed the implementation from this file and now
//it is implemented in Expr_Command_Factory.cpp file

class Expr_Command_Factory
{
public:

	//destructor
	virtual ~Expr_Command_Factory (void){};

	//number command
	virtual Number_Command * create_number_command (int num) = 0;

	//add command
	virtual Add_Command * create_add_command (void) = 0;

	//substract command
	virtual Subtract_Command * create_subtract_command (void) = 0;

	//multiply command
	virtual Multiply_Command * create_multiply_command (void) = 0;

	//divide command
	virtual Divide_Command * create_divide_command (void) = 0;

	//modulus command
	virtual Modulus_Command * create_modulus_command (void) = 0;

protected:
	// prevent the following operations
	Expr_Command_Factory ();

private:
	// prevent the following operations
	Expr_Command_Factory (const Expr_Command_Factory &);
	const Expr_Command_Factory & operator = (const Expr_Command_Factory &);

};

#endif
