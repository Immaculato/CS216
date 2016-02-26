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
	for (int j=0; j<ini_teams; j++)
	{	
		Arrange.push_back(new vector<int>);
		for (int i=0; i<ini_teams; i++)
		{
			Arrange[j].push_back(i);
		}
	}
	//this basically just makes a grid with garbage values, so that they
	//can be easily changed and manipulated in any order later.
}

void Scheduler::generateSchedule(int remainingteams)
{
	for (int i=remainingteams; i>0; i--)
	{
		Arrange[remainingteams][i];
		Arrange[i][remainingteams];
	}
	remainingteams--;
	if (remainingteams > 0)
	{
		generateSchedule(remainingteams);
	}
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
