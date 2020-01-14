#include "Expr_Command_Factory.h"

//COMMENT: This is an interface and therefore doesn't have any implemenation.
//Why do you have a .cpp file then?
//RESPONSE: I have this file for linking purposes and
//calling the functions and getting their values from memory


Expr_Command_Factory::Expr_Command_Factory (){}

Expr_Command_Factory::Expr_Command_Factory (const Expr_Command_Factory &){}

const Expr_Command_Factory & Expr_Command_Factory::operator = (const Expr_Command_Factory &){
	return *this;
}
