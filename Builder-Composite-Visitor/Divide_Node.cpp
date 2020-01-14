// -*- C++ -*-
#include "Divide_Node.h"

//constructor
Divide_Node::Divide_Node(Expr_Node * left, Expr_Node * right) : Binary_Expr_Node(left, right) {}

//destructor
 Divide_Node::~Divide_Node(void) {}


//Accept method passes
//control to concrete visitor
void Divide_Node::accept(Expr_Node_Visitor & v) {
	v.Visit_Divide_Node(*this);
}