#include <stdio.h>
#include <list>
#include "House.h"
#include "Car.h"
#include "Motorbike.h"
#include "Tree.h"

#pragma region Lesson2

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

#pragma region Lesson 3

void createList() {
	std::list<BaseObject> lObject;

	Tree* tree = new Tree(1, "Oak", 1);
	lObject.push_back(*tree);

	House* house = new House(2, "Flat", 2);
	lObject.push_back(*house);

	Car* car = new Car(3, "Nissan", 2);
	lObject.push_back(*car);

	Motorbike* motorbike = new Motorbike(4, "Honda", 1);
	lObject.push_back(*motorbike);

	for (auto object : lObject) {
		object.printPosition();
	}

	lObject.clear();
}

#pragma endregion





int main() {

	createList();
	printf("press enter to exit\n");
	getc(stdin);
	return 0;
}