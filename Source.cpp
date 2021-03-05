#include <stdio.h>

#pragma region Week2

//program 1: factorial (n!) calculator
void factorialCalculator() {
	int n = 0; //the number to find the factorial of
	int factorial = 1; //the result

	do {
		printf("enter a non-negative number: ");
		scanf_s("%d", &n);
	} while (n < 0);

	for (int i = 1; i <= n; i++)
	{
		factorial *= i;
	}

	printf("factorial of %d is %d\n",n , factorial); //answer
	getc(stdin);
}

//program 2: positive int filter, stops running until the player inputs a positive number
void positiveIntegerFilter() {
	int n = 0;

	while (n <= 0)
	{
		scanf_s("%d", &n);
	}

	printf("the number enterted is positive\n");
	getc(stdin);
}

#pragma endregion





int main() {
	factorialCalculator();
	//positiveIntegerFilter();

	printf("press enter to exit\n");
	getc(stdin);
	return 0;
}