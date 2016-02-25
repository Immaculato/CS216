#include "Scheduler.h"
#include <iostream>
#include <vector>

using namespace std;


bool isPowerOfTwo(int number)
{
	double remainder = number;
	while(remainder>1.0)
	{
		remainder=remainder/2.0;
	}
	if (remainder==1.0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


Scheduler::Scheduler()
{
	teams = -1;
}

Scheduler::Scheduler(int ini_teams)
{
	teams = ini_teams;	
}

void Scheduler::generateSchedule()
{
	cout << "Do some recursive stuff" << endl;
}

void Scheduler::print()
{
	for (int i=0; i<teams; i++)
	{
		for (int j=0; j<teams; j++)
		{
		cout << Arrange[i][j] << " ";
		}
		cout << endl;
	}
}
