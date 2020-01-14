   // -*- C++ -*-
// $Id: Infix2Postfix.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_INFIX_2_POSTFIX_H_
#define _CS507_INFIX_2_POSTFIX_H_

#include <string>
#include "Array.h"
#include "Stack.h"
#include "Queue.h"
#include "Expr_Command.h"
#include "Expr_Command_Factory.h"
#include <sstream> 

using namespace std;

class Infix2Postfix
{
public:

	//constructor
	Infix2Postfix(const string& infixExpression);

	//convert to postfix
	void toPosfix(Expr_Command_Factory & factory, Queue<Expr_Command*> &posfixQueue);

	//calculater
	int evaluate_postfix(Queue<Expr_Command*> &posfixQueue);
	
private:

	//infix expression
	string infixExpression;

	/*
	get priority of operator + - * / % 
	*/
	int priority(char character);

	/**
	check if character is operator
	*/
	bool isOperator(char character);

	//create command by operator
	Expr_Command* create_command(Expr_Command_Factory & factory, char oper, Queue<Expr_Command*> &posfixQueue);
};

#endif

