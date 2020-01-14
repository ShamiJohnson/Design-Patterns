#include "Subtract_Command.h"

//execute
void Subtract_Command::execute (Stack <int> &s){

	//subtract two top elements then push back to stack
	int n2 = s.top();
	s.pop();
	int n1 = s.top();
	s.pop();

	s.push(n1 - n2);
}