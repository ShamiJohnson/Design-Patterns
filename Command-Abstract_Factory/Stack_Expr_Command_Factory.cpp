#include "Stack_Expr_Command_Factory.h"

//constructor
Stack_Expr_Command_Factory::Stack_Expr_Command_Factory (Stack <int> & stack): stack_(stack){
}
	
//destructor
Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory (void){

}

//number command
Number_Command * Stack_Expr_Command_Factory::create_number_command (int num){
	return new Number_Command(num);
}

//add command
Add_Command * Stack_Expr_Command_Factory::create_add_command (void){
	return new Add_Command();
}

//substract command
Subtract_Command * Stack_Expr_Command_Factory::create_subtract_command (void){
	return new Subtract_Command();
}

//multiply command
Multiply_Command * Stack_Expr_Command_Factory::create_multiply_command (void){
	return new Multiply_Command();
}

//divide command
Divide_Command * Stack_Expr_Command_Factory::create_divide_command (void){
	return new Divide_Command();
}

//modulus command
Modulus_Command * Stack_Expr_Command_Factory::create_modulus_command (void){
	return new Modulus_Command();
}