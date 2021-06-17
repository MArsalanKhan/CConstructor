

#include "stdio.h"

void op1()
{
	printf("Operation 1\n");
}

void op2()
{
	printf("Operation 2\n");
}

void op3()
{
	printf("Operation 3\n");
}

int main()
{
	//A simple function pointer, returning void and passing no parameters
	void (*fct)();
	//Array containing 3 Function Pointers
	void (*fctPtr[3])() = {op1,op2,op3};
	int i;

	// Calling the single pointer
	fct = op1;	// Assigning a valid function
	fct();		// Call the function

	//Calling the array


	for (i = 0; i<3; i++)
	{
		fctPtr[i]();
	}

	return 0;
}

