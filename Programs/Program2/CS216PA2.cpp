#include "Scheduler.cpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

int main()
{
	int numberteams;
	string userinput;
	do
	{
		cout << "Please enter the number of teams to be scheduled";
		cout << " (q or Q to quit): ";
		cin >> userinput;
		if (userinput == "Q" | userinput == "q")
		{
			cout << "Thanks for using the scheduling program." << endl;
			return 0;
		}
		try
		{
			numberteams = stoi(userinput);
		}
		catch (invalid_argument &a)
		{
			cout << "Invalid number!" << endl;
			continue;
		}
		if (!isPowerOfTwo(numberteams))
		{
			cout << "The number of teams is not a power of two!" << endl;
			continue;
		}
		Scheduler teamschedule(numberteams);
		teamschedule.generateSchedule(numberteams);
		teamschedule.print();
	}
	while (true);
}
