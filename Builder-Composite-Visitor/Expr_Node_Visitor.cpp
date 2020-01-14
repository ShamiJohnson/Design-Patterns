#include "Expr_Node_Visitor.h"

//destructor
Expr_Node_Visitor::~Expr_Node_Visitor(void) {}

// Methods for visiting concrete nodes
void Expr_Node_Visitor::Visit_Addition_Node(const Addition_Node &node) {}
void Expr_Node_Visitor::Visit_Subtraction_Node(const Subtraction_Node &node) {}
void Expr_Node_Visitor::Visit_Number_Node(const Number_Node &node) {}
void Expr_Node_Visitor::Visit_Variable_Node(const Variable_Node &node) {}
void Expr_Node_Visitor::Visit_Divide_Node(const Divide_Node &node) {}
void Expr_Node_Visitor::Visit_Modulus_Node(const Modulus_Node &node) {}
void Expr_Node_Visitor::Visit_Multiply_Node(const Multiply_Node &node) {}