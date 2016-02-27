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
	Arrange = new int*[ini_teams];
	for (int i=0; i<ini_teams; i++)
	{
		Arrange[i] = new int[ini_teams];
	}
	teams = ini_teams;
	//this basically just makes a grid with garbage values, so that they
	//can be easily changed and manipulated in any order later.
}

void Scheduler::generateSchedule(int stepnumber) //stepnumber ~ current 2^m term
{
	if (stepnumber == teams)
	{
		return;
	}	
	else if (stepnumber != 0)
	{
		for (int i=0; i<stepnumber; i++)
		{
			for (int j=0; j<stepnumber; j++)
			{
				Arrange[i][j+stepnumber] = (Arrange[i][j] + stepnumber);
				Arrange[i+stepnumber][j] = (Arrange[i][j] + stepnumber);
				Arrange[i+stepnumber][j+stepnumber] = Arrange[i][j];
			}
		}
	}
	else
	{
		Arrange[0][0] = 1;
	}
	if (stepnumber==0)
	{
		stepnumber = 1;
	}
	else
	{
		stepnumber = stepnumber*2;
	}
	generateSchedule(stepnumber);
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

Scheduler::~Scheduler()
{
	for (int i=0; i<teams; i++)
	{
		delete Arrange[i];
	}
	delete[] Arrange;
}

