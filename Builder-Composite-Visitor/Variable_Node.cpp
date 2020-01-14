#include "Variable_Node.h"

//constructor
Variable_Node::Variable_Node(char var) : var_(var) {}

//destructor
Variable_Node::~Variable_Node(void) {}

//get variable
char Variable_Node::getVar() const {
	return var_;
}

// Used to traverse the tree
void Variable_Node::accept(Expr_Node_Visitor &v) {
	v.Visit_Variable_Node(*this);
}

