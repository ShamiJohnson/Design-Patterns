// -*- C++ -*-
// $Id: Divide_Command.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * @file       Divide_Command.h
 *
 * $Id: Divide_Command.h 380 2010-02-08 05:10:33Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

//COMMENT: Please put the implmentation in the proper .cpp file.
//RESPONSE: I removed the implementation from this file and
//implemented it in the Divide_Command.cpp file now


#ifndef _DIVIDE_COMMAND_H_
#define _DIVIDE_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

//divide command
class Divide_Command: public Expr_Command
{
public:
	//execute
	virtual void execute (Stack <int> &s);
};

#endif
