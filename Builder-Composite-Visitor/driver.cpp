#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

#include "Array.h"
#include "Fixed_Array.h"

#include "Queue.h"
#include "Stack.h"

#include "Expr_Tree_Builder.h"
#include "Calculator.h"

#define LENGTH 6

void correct(bool value, const char* msg){
	if (!value)
	{
		throw std::logic_error(msg);
	}
}

void testCase1(){

	{
		Array<char> array;
		correct(array.size() >= 0, "default constructor failed");
	}

	{
		Array<char> array(LENGTH);
		correct(array.size() >= LENGTH, "default constructor failed");
	}

	{
		Array<char> array(LENGTH, 'n');
		correct(array.size() >= LENGTH, "fill constructor failed");
	}
	{
		Array<char> array(LENGTH);
		Array<char> copy(LENGTH);
		correct(copy.size() >= LENGTH, "copy constructor failed");
	}
	{
		//assignment, size and max_size
		Array<char> array;
		Array<char> copy = array;
		correct(copy.size() >= 0, "assignment operator failed");
		correct(copy.max_size() >= 0, "max_size failed");
	}

	//Subscript operator, get, and set
	Array<char> array6(LENGTH, 'n');

	size_t len = array6.size();
	for(size_t i = 0; i < len; ++i)
	{
		//char msg[128];
		//sprintf(msg, "subscript failed %d", i);
		//correct(array6[i] == 'n', msg);
	}

	array6.set(3, '1');
	correct(array6.get(3) == '1', "set() failed");

	//subscript exception
	try{
		array6[LENGTH + 1];
		correct(false, "subscript out of range failed");
	} catch(const out_of_range& e){
		cerr << e.what() << '\n';
		correct(true, "subcript out of range success");
	}

	//find and reverse
	Array <char > array7(LENGTH);

	array7.set(0, 'n');
	array7.set(1, 'y');
	array7.set(2, 'a');
	array7.set(3, 'l');
	array7.set(4, 'i');
	array7.set(5, 'a');

	correct(array7.find('a') == 2, "find('a') failed");
	correct(array7.find('X') == -1, "find('a') failed");

	//find exception
	try{
		array7.find(LENGTH + 1, 'a');
		correct(false, "find() out of range failed");
	}catch(const out_of_range& e){
		cerr << e.what() << '\n';
		correct(true, "find() out of range success");
	}
	{
		Array<char> array(LENGTH, 'n');
		size_t m = array.max_size();
		array.resize(m+2);
		correct(array.max_size() >= (m+2), "resize larger failed");
	}

	{
		Array<char> array(LENGTH, 'n');
		size_t c = array.size();
		array.resize(c-2);
		correct(array.size() >= (c-2), "resize smaller failed");
	}
}


void testStack(){

	Stack<int> stack;

	for (int i = 0; i < 15; i++)
	{
		stack.push(i);
	}

	while (!stack.is_empty())
	{
		cout << stack.top() << endl;
		stack.pop();
	}
}

void testQueue(){

	Queue<int> queue;

	for (int i = 0; i < 15; i++)
	{
		queue.enqueue(i);
	}

	while (!queue.is_empty())
	{
		cout << queue.peek() << endl;
		queue.dequeue();
	}
}

void testFixedArray(){

	Fixed_Array<int, 10> a;
	Fixed_Array<int, 10> b;
	a[0] = 1;

	b = a;
	cout << b[0] << endl;
}

//test function
//read the infix expression, convert to posfix, evaluate
//until QUIT is entered
int main()
{
	//infix expression
	string infix = "";


	//ask for infix expression, process and print the result
	while (infix != "QUIT" && infix != "quit")
	{
		//read infix expression
		getline(cin, infix);

		if (infix != "QUIT" && infix != "quit")
		{
			//COMMENT: do not use break statements. These are only acceptable with switch.
			//Please come up with a better design.

			//RESPONSE: Okay thanks for the information, I removed break and now using 
			//not operator 
			

			//expression builder
			Expr_Builder* builder = new Expr_Tree_Builder();

			//calculator
			Calculator calculator(builder);

			//parse and evaluate
			try {
				cout << infix << endl;
				int result = calculator.evaluate(infix);
				cout << "Result: " << result << endl;
			}			
			catch (runtime_error &error) {
                cout << "Run time error, Invalid Input! ";
				cout << error.what() << endl;
			}
			catch (exception &error) {
                cout << "Exception error, Invalid Input! ";
				cout << error.what() << endl;
			}

			delete builder;
		}
	}

	return 0;
}
