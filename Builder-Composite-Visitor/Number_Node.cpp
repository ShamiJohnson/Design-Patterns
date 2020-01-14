#include "Number_Node.h"

//COMMENT: Please seperate this file into a .h and .cpp
//RESPONSE: OKay I added a new file split the code between them.
//New filename: Number_Node.cpp

//constructor
Number_Node::Number_Node(int num) : num_(num) {}

//destructor
Number_Node::~Number_Node(void) {}

//evaluate
int Number_Node::eval() const {
	return num_;
}

// Used to traverse the tree
void Number_Node::accept(Expr_Node_Visitor &v) {
	v.Visit_Number_Node(*this);
}