#include "Infix2Postfix.h"

//constructor
//example
Infix2Postfix::Infix2Postfix(const string& infixExp): infixExpression(infixExp)
{

}

/**
* calculate the priority of the operation
*
* @param op % + - * /
* @return priority
*/
int Infix2Postfix::priority(char op) {
switch (op) {
    case '%':
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
}
}

// check element operator
bool Infix2Postfix::isOperator(char character) {
	return (character == '+' || character == '-' || character == '*' || character == '/' || character == '%');
}

//create command by operator
Expr_Command* Infix2Postfix::create_command(Expr_Command_Factory & factory, char oper, Queue<Expr_Command*> &posfixQueue){
	if (oper == '+')
	{
		posfixQueue.enqueue(factory.create_add_command());
	}else if (oper == '-')
	{
		posfixQueue.enqueue(factory.create_subtract_command());
	}else if (oper == '*')
	{
		posfixQueue.enqueue(factory.create_multiply_command());
	}else if (oper == '/')
	{
		posfixQueue.enqueue(factory.create_divide_command());
	}else if (oper == '%')
	{
		posfixQueue.enqueue(factory.create_modulus_command());
	}

	return NULL;
}

//convert to postfix
//Algorithm for Converting Infix to Postfix
//output: posfixQueue
void Infix2Postfix::toPosfix(Expr_Command_Factory & factory, Queue<Expr_Command*> &posfixQueue){

	//create string stream
	stringstream ss (infixExpression);
	
	//a token
	string token;
	
	//stack of operators
	Stack <char> stack;	

	//process token by token
	while (ss >> token)
	{		
		//is operator
		if(isOperator(token[0]) && token.length() == 1)
		{			
			//check with top of stack, if the operator is higher precedence, pop it
			//loop this process
			while (!stack.is_empty() && priority(token[0]) <= priority(stack.top()))
			{
				//operator of top of stack
				char topChar = stack.top();
				stack.pop();

				//create command
				create_command(factory, topChar, posfixQueue);
			}

			//finally, push token to stack
			stack.push(token[0]);
			
		}
		else if(token[0] == '(')
		{ // (
			stack.push(token[0]);
		}
		else if(token[0] == ')')
		{// )
			while (!stack.is_empty() && stack.top() != '(')
			{
				char par_ = stack.top();
				stack.pop();

				//create command
				create_command(factory, par_, posfixQueue);
			}

			//pop the '('
			stack.pop();
		}
		else
		{ //integer

			int operand = atoi(token.c_str()); //convert to integer

			posfixQueue.enqueue(factory.create_number_command(operand));
		}	
	}

	// check operator in stack, append all of them to queue result
	while (!stack.is_empty())
	{
		char topChar = stack.top();
		stack.pop();

		//create command
		create_command(factory, topChar, posfixQueue);
	}
}

//evaluate in stack
int Infix2Postfix::evaluate_postfix(Queue<Expr_Command*> &posfixQueue)
{
	//stack
	Stack <int> stack;

	//process all nodes in queue
	while (!posfixQueue.is_empty())
	{
		//peek a node
		Expr_Command* node = posfixQueue.peek();
		posfixQueue.dequeue();

		node->execute(stack);

		//delete used node
		delete node;
	}

	//the final is result
	return stack.top();
}
