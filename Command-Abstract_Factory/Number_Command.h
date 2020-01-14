// -*- C++ -*-
// $Id: Number_Command.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * @file       Number_Command.h
 *
 * $Id: Number_Command.h 380 2010-02-08 05:10:33Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _NUMBER_COMMAND_H_
#define _NUMBER_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

//number command
class Number_Command: public Expr_Command
{
public:
    //COMMENT: Please put the implmentation in the proper .cpp file.
    //RESPONSE: I removed the implmentation from this file to Number_Command.cpp
    

	//constructor
	Number_Command(int num);

	//execute
	virtual void execute (Stack <int> &s);

private:
	int num;
};

#endif
