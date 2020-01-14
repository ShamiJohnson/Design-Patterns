#include "Modulus_Node.h"

//constructor
Modulus_Node::Modulus_Node(Expr_Node * left, Expr_Node * right) : Binary_Expr_Node(left, right) {}

//destructor
Modulus_Node::~Modulus_Node(void) {}

//Accept method passes
//control to concrete visitor
void Modulus_Node::accept(Expr_Node_Visitor & v) {
	v.Visit_Modulus_Node(*this);
}
