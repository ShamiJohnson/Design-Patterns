#include "Binary_Expr_Node.h"

//constructor
Binary_Expr_Node::Binary_Expr_Node(Expr_Node * left, Expr_Node * right) : left_(left), right_(right) {}

//destructor
Binary_Expr_Node::~Binary_Expr_Node(void) {

	if (left_ != nullptr)
	{
		delete left_;
		left_ = nullptr;
	}

	if (right_ != nullptr)
	{
		delete right_;
		right_ = nullptr;
	}
}

//get left node
Expr_Node* Binary_Expr_Node::getRight() const {
	return right_;
}

//get right node
Expr_Node * Binary_Expr_Node::getLeft() const {
	return left_;
}
