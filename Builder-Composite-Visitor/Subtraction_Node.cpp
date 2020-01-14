#include "Subtraction_Node.h"
//constructor
Subtraction_Node::Subtraction_Node(Expr_Node * left, Expr_Node * right) : Binary_Expr_Node(left, right) {}

//destructor
Subtraction_Node::~Subtraction_Node(void) {}

//Accept method passes
//control to concrete visitor
void Subtraction_Node::accept(Expr_Node_Visitor & v) {
	v.Visit_Subtraction_Node(*this);
}
