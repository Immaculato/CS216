/*
Program 2 - Main function
Tristan Basil
University of Kentucky
Stu. ID: 12008804
*/

#include "Scheduler.cpp"
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

int main()
{
	int numberteams;
	string userinput;
	//run this until the user is done:
	do
	{
		//get the user's input for number of teams.
		cout << "Please enter the number of teams to be scheduled";
		cout << " (q or Q to quit): ";
		cin >> userinput;
		istringstream iss(userinput); 
		//if they input q or Q,
		if (userinput == "Q" | userinput == "q")
		{
			//thank them for using the program, and end it.
			cout << "Thanks for using the scheduling program." << endl;
			return 0;
		}
		//if they input anything else, attempt to convert it to an integer.
		iss >> numberteams;
		//if it couldn't be converted to an integer:
		if (iss.fail())
		{
			//tell them it couldn't be converted, and re-run the loop.
			cout << "Invalid number!" << endl;
			continue;
		}
		//if the number of teams is greater than 512,
		if (numberteams > 512)
		{
			//say it isn't supported, and re-run the loop.
			cout << "The maximum number of teams is 512." << endl;
			continue;
		}
		//if the number of teams isn't a power of two,
		if (!isPowerOfTwo(numberteams))
		{
			//say so, and re-run the loop.
			cout << "The number of teams is not a power of two!" << endl;
			continue;
		}
		
		//iff all of these checks pass, generate a schedule with the teams.
		Scheduler teamschedule(numberteams);
		teamschedule.generateSchedule(0);
		//print it when done.
		teamschedule.print();
	}
	while (true);
}
