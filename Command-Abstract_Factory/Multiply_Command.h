// -*- C++ -*-
// $Id: Multiply_Command.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * @file       Multiply_Command.h
 *
 * $Id: Multiply_Command.h 380 2010-02-08 05:10:33Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _MULTIPLY_COMMAND_H_
#define _MULTIPLY_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

//multiply command
class Multiply_Command: public Expr_Command
{
public:
    //COMMENT: Please put the implmentation in the proper .cpp file.
    //RESPONSE: I removed the implmentation from this file to Multiply_Command.cpp
    
	//execute
	virtual void execute (Stack <int> &s);
};

#endif

