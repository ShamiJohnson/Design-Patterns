#include "Add_Command.h"

void Add_Command::execute (Stack <int> &s){

	//add two top elements then push back to stack
	int n2 = s.top();
	s.pop();
	int n1 = s.top();
	s.pop();

	s.push(n1 + n2);
}