/*
--------------------------------------------------------------------
* Name:       Stan Turovsky
* Class:      Advanced C++
* Files:      main.cpp, ACD.h, Call.h, LinkedList.h, Node.h, Queue.h
* Purpose:    ACD (Automatic Call Distributor) simulation
*             -Use of template variables for a node, linked list
--------------------------------------------------------------------
*/

#include "ACD.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	ACD dispatcher;
	srand((unsigned)time(0));
	
	// PHASE 1:  During working hours.
	for (int i = 0; i < 10; ++i)
	{
		// Choose a random event (new call, handled call, or nothing)
		int randomEvent = rand() % 3;

		// Process the event.
		switch (randomEvent)
		{
		case 0: // New call comes in.
			dispatcher.newCall();
			break;
		case 1: // A call has been handled.
			dispatcher.handleCall();
			break;
		default: cout << "No new activity." << endl;
		}
		dispatcher.display();
	}

	// PHASE 2:  After working hours.
	// Handle calls until queue is empty.
	while (dispatcher.isCallWaiting())
	{
		// handle the next call
		dispatcher.handleCall();
		dispatcher.display();
	}

	// Leave this stuff at the end.
	cout << endl;
	// system("pause");
	return 0;
}

string ACD::random(int min, int max)
{
	int r = min + (rand() % (max-min));
	return to_string(r);
}

void ACD::newCall()
{
	Call call;
	call.phoneNumber = random(100, 1000) + "-" 
		             + random(100, 1000) + "-" 
					 + random(1000, 10000);
	call.date = random(1, 13) + "-" + random(1, 32) + "-2017";
	call.time = random(0, 25) + ":" + random(0, 60);
	call.id = random(1000, 10000);
	switch(rand() % 4)
	{
	case 0: call.language = "EN"; break;
	case 1: call.language = "SP"; break;
	case 2: call.language = "FR"; break;
	case 3: call.language = "CH"; break;
	default: ;
	}

	cout << ">>>>>>>> New call coming in: ";
	call.display();
	//cout << endl;

	// TODO:  Enqueue the call.
	callQueue.enqueue(call);
}

void ACD::handleCall()
{
	// TODO: if a call is waiting in the queue
	if (!callQueue.isEmpty()) // this->isCallWaiting()
	{
		cout << "<<<<<<<< Call has been handled: ";
		// TODO: Dequeue the call and display it.
		callQueue.getFront().display();
		callQueue.dequeue();
	}
	else
		cout << "<<<<<<<< No calls to handle." << endl;
	// cout << endl;
}

void ACD::display()
{
	// TODO:  if calls are waiting in the queue
	if (!callQueue.isEmpty())
	{
		cout << "Next caller in line: ";
		// TODO:  Display the next call to be handled.
		callQueue.getFront().display();
	}
	else
		cout << "<<<<<<<< No calls to handle." << endl;
	// cout << endl;
}

bool ACD::isCallWaiting()
{
	return !this->callQueue.isEmpty();
}