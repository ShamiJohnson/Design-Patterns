
#include "Multiply_Node.h"

//constructor
Multiply_Node::Multiply_Node(Expr_Node * left, Expr_Node * right) : Binary_Expr_Node(left, right) {}

//destructor
Multiply_Node::~Multiply_Node(void) {}

//Accept method passes
//control to concrete visitor
void Multiply_Node::accept(Expr_Node_Visitor & v) {
	v.Visit_Multiply_Node(*this);
}
