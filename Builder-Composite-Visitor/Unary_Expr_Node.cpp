#include "Unary_Expr_Node.h"

//constructor
Unary_Expr_Node::Unary_Expr_Node(Expr_Node* child) : child_(child) {}

//destructor
Unary_Expr_Node::~Unary_Expr_Node(void) {

	if (child_ != nullptr)
	{
		delete child_;
		child_ = nullptr;
	}
}