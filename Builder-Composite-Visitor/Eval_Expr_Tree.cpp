#include "Eval_Expr_Tree.h"

Eval_Expr_Tree::Eval_Expr_Tree(void) : variables(Array<char>(100)), values(Array<int>(100)), index(0) {}

Eval_Expr_Tree::~Eval_Expr_Tree(void) {}

// Methods for visiting concrete nodes
void Eval_Expr_Tree::Visit_Addition_Node(const Addition_Node & node) {

    // first visit left node
	node.getLeft()->accept(*this);
	int leftValue = result_;

    //now visit right node
	node.getRight()->accept(*this);
	int rightValue = result_;

    // then perform addition +
	result_ = leftValue + rightValue;
}

void Eval_Expr_Tree::Visit_Subtraction_Node(const Subtraction_Node & node) {

    // first visit left node
	node.getLeft()->accept(*this);
	int leftValue = result_;

    //now visit right node
	node.getRight()->accept(*this);
	int rightValue = result_;

    // then perform subtraction -
	result_ = leftValue - rightValue;
}

void Eval_Expr_Tree::Visit_Multiply_Node(const Subtraction_Node & node) {

	// first visit left node
	node.getLeft()->accept(*this);
	int leftValue = result_;

	//now visit right node
	node.getRight()->accept(*this);
	int rightValue = result_;

    // then perform multiplication *
	result_ = leftValue * rightValue;
}

void Eval_Expr_Tree::Visit_Variable_Node(const Variable_Node &node) {

	bool found = false;

	//check if variable is found
	for (int i = 0; i < index; i++)
	{
		if (node.getVar() == variables[i])
		{
			result_ = values[i];
			found = true;
			break;
		}
	}

	//read value for variable from user
	if (!found)
	{
		//COMMENT: With this code it looks like you will be accepting variable values in
		//PEMDAS order instead of the order of the input.

		//RESPONSE: when the variable is visited, the code will read value 
		//from standard input
		//It is now in the order such as from left to right.


		std::string aString; //a line from user

		std::cout << node.getVar() << " = ";
		getline(std::cin, aString);

        //string stream
		std::stringstream ss(aString);
		ss >> result_;

		variables[index] = node.getVar();
		values[index] = result_;

		index++;
	}

}

void Eval_Expr_Tree::Visit_Divide_Node(const Divide_Node &node) {
	// visit left node, visit right node, then perform /
	node.getLeft()->accept(*this);
	int leftValue = result_;

	node.getRight()->accept(*this);
	int rightValue = result_;

	if (rightValue == 0)
	{
		throw std::runtime_error("Division by zero");
	}
	result_ = leftValue / rightValue;
}

void Eval_Expr_Tree::Visit_Modulus_Node(const Modulus_Node &node) {
	// visit left node, visit right node, then perform /
	node.getLeft()->accept(*this);
	int leftValue = result_;

	node.getRight()->accept(*this);
	int rightValue = result_;

	if (rightValue == 0)
	{
		throw std::runtime_error("Modulus by zero");
	}
	result_ = leftValue % rightValue;
}

void Eval_Expr_Tree::Visit_Multiply_Node(const Multiply_Node &node) {
	// visit left node, visit right node, then perform /
	node.getLeft()->accept(*this);
	int leftValue = result_;

	node.getRight()->accept(*this);
	int rightValue = result_;

	result_ = leftValue * rightValue;
}

void Eval_Expr_Tree::Visit_Number_Node(const Number_Node & node) {

	result_ = node.eval();
}

int Eval_Expr_Tree::result(void) const { return this->result_; }

