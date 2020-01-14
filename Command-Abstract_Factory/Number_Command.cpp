#include "Number_Command.h"

//constructor
Number_Command::Number_Command(int num): num(num){

}

//execute
void Number_Command::execute (Stack <int> &s){
	s.push(num);
}