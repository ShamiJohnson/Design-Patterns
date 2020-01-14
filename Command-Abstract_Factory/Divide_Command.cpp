#include "Divide_Command.h"

//execute
void Divide_Command::execute (Stack <int> &s){

	//divide two top elements then push back to stack
	int n2 = s.top();
	s.pop();
	int n1 = s.top();
	s.pop();

	if (n2 == 0)
	{
		throw exception();
	}else{
		s.push(n1 / n2);
	}

	
}