// -*- C++ -*-
// $Id: Calculator.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
* Honor Pledge:
*
* I pledge that I have neither given nor received any help
* on this assignment.
*/
//==============================================================================

#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <string>
#include <memory>
#include <exception>
#include <sstream> 
#include "Expr_Builder.h"
#include "Expr_Node.h"
#include "Eval_Expr_Tree.h"

using namespace std;

class Calculator
{
public:

	Calculator(Expr_Builder* builder)
		: builder_(builder) { }

	virtual ~Calculator(){
		
	}

	//parse expression
	bool parse_expr(const string &infix) {

		std::istringstream input(infix); // create a input stream parser
		std::string token; // current token in string/stream
		
		builder_->start_expression(); // start a new expression

		// if there is an operator then build it
		while (!input.eof()) {
			
			input >> token;

			if (token == "+") {
				builder_->build_add_operator();
			}
			else if (token == "-") {
				builder_->build_subtract_operator();
			}
			else if (token == "*") {
				builder_->build_multiply_operator();
			}
			else if (token == "/") {
				builder_->build_divide_operator();
			}
			else if (token == "%") {
				builder_->build_modulus_operator();
			}
			else if (token == "(") {
				builder_->build_open_parenthesis();
			}
			else if (token == ")") {
				builder_->build_close_parenthesis();
			}
			else if (isVariable(token.at(0))) {
				builder_->build_variable(token.at(0));
			}
			else {
                //convert to integer
				int operand = atoi(token.c_str());
				builder_->build_number(operand);
			}
		}

        // end the expression
		builder_->end_expression();

		return true;
	}

	int evaluate(const std::string & infix)
	{
		if (!this->parse_expr(infix))
			throw std::runtime_error("Bad expresssion");

		std::unique_ptr <Expr_Node> expr(builder_->get_expression());

		if (nullptr == expr.get())
			throw std::runtime_error("No expression!!");

		Expr_Node * expr_tree = expr.get();

		Eval_Expr_Tree eval;

		// evaluate the expression tree
		expr_tree->accept(eval);
		int result =  eval.result();

		expr.reset();

		return result;
	}

private:

	Expr_Builder* builder_;

	// check element operator
	bool isOperator(char character) {
		return (character == '+' || character == '-' || character == '*' || character == '/' || character == '%');
	}

	// check element operator
	bool isVariable(char character) {
		return (character >= 'a' && character <= 'z');
	}
	
};

#endif

