#include <stdio.h>
#include <iostream>
#include <list>
#include "House.h"
#include "Car.h"
#include "Motorbike.h"
#include "Tree.h"

#pragma region Lesson 2

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

/// <summary>
/// call createList() in main() to use
/// </summary>

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

#pragma region Lesson 4

class Door
{
	class State	*m_currentState;

public:
	Door();
	~Door();

	void setState(State* state) {
		m_currentState = state;
	}

	void open();
	void close();
	void lock();
	void unlock();
};

class State
{
public:
	State();
	~State();

	//nothing special happens;functions are not overriden; dooe does not change when these functions are called

	virtual void open(Door* door) {
		printf("Door is already opened");
	}

	virtual void close(Door* door) {
		printf("Door is already closed");
	}

	virtual void lock(Door* door) {
		printf("Door is already locked");
	}

	virtual void unlock(Door* door) {
		printf("Door is already unlocked");
	}
};


void Door::open() {
	m_currentState->open(this);
}

void Door::close() {
	m_currentState->close(this);
}

void Door::lock() {
	m_currentState->lock(this);
}

void Door::unlock() {
	m_currentState->unlock(this);
}

class OpenDoor : public State
{
public:
	OpenDoor() {
		printf("Door Opened");
	};
	~OpenDoor() {
		//printf("Door Closed");
	};

	//an opened door can only be closed
	void close(Door* door);

};

class CloseDoor : public State
{
public:
	CloseDoor() {
		printf("Door Closed");
	};
	~CloseDoor() {
		//printf("Door Closed");
	};

	//a closed door can be opened
	void open(Door* door) {
		printf("going from closed to opened");
		door->setState(new OpenDoor());
		delete this;
	}

	//and locked
	void lock(Door* door);
};

void OpenDoor::close(Door* door) {
	printf("going from opened to closed");
	door->setState(new CloseDoor());
	delete this;
}

class LockDoor : public State
{
public:
	LockDoor() {
		printf("Door Locked");
	};
	~LockDoor() {
		//printf("Door Closed");
	};

	//a locked door can only be unlocked(to "closed door")
	void unlock(Door* door) {
		printf("going from locked to closed");
		door->setState(new CloseDoor());
		delete this;
	}

};



void CloseDoor::lock(Door* door) {
	printf("going from closed to locked");
	door->setState(new LockDoor());
	delete this;
}

Door::Door() {
	m_currentState = new OpenDoor();
}

void doorProgram() {
	void(Door:: * ptrs[])() =
	{
	  &Door::open, &Door::close, &Door::lock, &Door::unlock
	};
	Door fsm;
	int num;
	while (1)
	{
		printf("Enter 0/1: ");
		scanf_s("%d", &num);
		(fsm.*ptrs[num])();
	}

}

#pragma endregion




int main() {


	printf("press enter to exit\n");
	getc(stdin);
	return 0;
}