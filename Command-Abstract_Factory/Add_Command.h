// -*- C++ -*-
// $Id: Add_Command.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * @file       Add_Command.h
 *
 * $Id: Add_Command.h 380 2010-02-08 05:10:33Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _ADD_COMMAND_H_
#define _ADD_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"


//COMMENT: Please put the implmentation in the proper .cpp file.
//RESPONSE: I removed the implementation from this file and
//implemented it in the Add_Command.cpp file now

//add command
class Add_Command: public Expr_Command
{
public:
	//execute
	virtual void execute (Stack <int> &s);
};

#endif
