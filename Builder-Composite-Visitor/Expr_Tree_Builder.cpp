#include "Expr_Tree_Builder.h"

//constructor
Expr_Tree_Builder::Expr_Tree_Builder(void) {}

//destructor
Expr_Tree_Builder::~Expr_Tree_Builder(void) {}

//start expression
void Expr_Tree_Builder::start_expression(void) {
	this->tree_ = nullptr;
}

void Expr_Tree_Builder::build_number(int n) {
	nodeStack.push(new Number_Node(n));
}

void Expr_Tree_Builder::build_variable(char var) {
	nodeStack.push(new Variable_Node(var));
}

void Expr_Tree_Builder::build_add_operator(void) {
	process_operator('+');
}

void Expr_Tree_Builder::build_subtract_operator(void) {
	process_operator('-');
}

void Expr_Tree_Builder::build_modulus_operator(void) {
	process_operator('%');
}

void Expr_Tree_Builder::build_multiply_operator(void) {
	process_operator('*');
}

void Expr_Tree_Builder::build_divide_operator(void) {
	process_operator('/');
}

void Expr_Tree_Builder::build_open_parenthesis(void) {
	operStack.push('(');
}

void Expr_Tree_Builder::build_close_parenthesis(void) {

	while (!operStack.is_empty() && operStack.top() != '(')
	{
		char topChar = operStack.top();
		operStack.pop();

		//build and push to node stack
		build_node(topChar);
	}

	//pop the '('
	operStack.pop();
}

// get the current expression
Expr_Node * Expr_Tree_Builder::get_expression(void) {
	return tree_;
}

//end expression
void Expr_Tree_Builder::end_expression(void) {
	// check operator in stack, append all of them to queue result
	while (!operStack.is_empty())
	{
		char topChar = operStack.top();
		operStack.pop();

		//build and push to node stack
		build_node(topChar);
	}

	tree_ = nodeStack.top();
	nodeStack.pop();
}


//process operator
void Expr_Tree_Builder::process_operator(char oper) {

	//check with top of stack, if the operator is higher precedence, pop it
	//loop this process
	while (!operStack.is_empty() && priority(oper) <= priority(operStack.top()))
	{
		//operator of top of stack
		char topChar = operStack.top();
		operStack.pop();

		//build and push to node stack
		build_node(topChar);
	}

	//finally, push token to stack
	operStack.push(oper);
}

//create node	
void Expr_Tree_Builder::build_node(char oper) {

	Expr_Node* rightNode = nodeStack.top();
	nodeStack.pop();

	Expr_Node* leftNode = nodeStack.top();
	nodeStack.pop();

	if (oper == '+')
	{
		nodeStack.push(new Addition_Node(leftNode, rightNode));
	}
	else if (oper == '-')
	{
		nodeStack.push(new Subtraction_Node(leftNode, rightNode));
	}
	else if (oper == '*')
	{
		nodeStack.push(new Multiply_Node(leftNode, rightNode));
	}
	else if (oper == '/')
	{
		nodeStack.push(new Divide_Node(leftNode, rightNode));
	}
	else if (oper == '%')
	{
		nodeStack.push(new Modulus_Node(leftNode, rightNode));
	}
}

/**
* calculate the priority of the operation
*
* @param op % + - * /
* @return priority
*/
int Expr_Tree_Builder::priority(char op) {
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