// -*- C++ -*-
// $Id: Modulus_Command.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * @file       Modulus_Command.h
 *
 * $Id: Modulus_Command.h 380 2010-02-08 05:10:33Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _MODULUS_COMMAND_H_
#define _MODULUS_COMMAND_H_

#include "Expr_Command.h"
#include "Stack.h"

//modulus command
class Modulus_Command: public Expr_Command
{
public:
    //COMMENT: Please put the implmentation in the proper .cpp file.
    //RESPONSE: I removed the implementation now and it is in Modulus_Command.cpp
    
    //COMMENT: Your code will break on mod by 0.
    //RESPONSE: Thank you for letting me know, I fixed that now using an if statement!
    //execute
	//execute
	virtual void execute (Stack <int> &s);
};

#endif
