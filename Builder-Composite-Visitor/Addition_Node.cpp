#include "Addition_Node.h"

//constructor
Addition_Node::Addition_Node(Expr_Node * left, Expr_Node * right) : Binary_Expr_Node(left, right) {}

//destructor
Addition_Node::~Addition_Node(void) {}

//Accept method passes
//control to concrete visitor
void Addition_Node::accept(Expr_Node_Visitor & v) {
	v.Visit_Addition_Node(*this);
}