#include "Scheduler.h"
#include <iostream>
#include <vector>

using namespace std;


bool isPowerOfTwo(int number)
{
	//remainder = what's left to divide out.
	double remainder = number;
	//while the remainder is greater than 1,
	while(remainder>1.0)
	{
		//divide the remainder by 2.
		remainder=remainder/2.0;
	}
	//if the remainder is equal to 1 after multiple loops,
	if (remainder==1.0)
	{
		//it is a power of 2.
		return true;
	}
	//otherwise, it isn't a power of 2.
	else
	{
		return false;
	}
}

Scheduler::Scheduler()
{
	//initialize teams as -1 to signal that its not ready to be used.
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
	//this basically just makes a grid with no values, so that they
	//can be easily changed and manipulated in any order later.
}

void Scheduler::generateSchedule(int stepnumber) //stepnumber ~ current 2^m term
{
	//if the current step has incremented to the number of teams,
	if (stepnumber == teams)
	{
		//the function is done.
		return;
	}
	//by default, this starts at 0. therefore, if it isn't 0,	
	else if (stepnumber != 0)
	{
		//for each x value up the middle
		for (int i=0; i<stepnumber; i++)
		{
			//and for each y value up to the middle,
			for (int j=0; j<stepnumber; j++)
			{
				//copy the grid below, adding the stepnumber.
				Arrange[i][j+stepnumber] = (Arrange[i][j] + stepnumber);
				//copy the grid to the right, adding the stepnumber.
				Arrange[i+stepnumber][j] = (Arrange[i][j] + stepnumber);
				//copy the grid diagonally as is.
				Arrange[i+stepnumber][j+stepnumber] = Arrange[i][j];
			}
		}
		//the stepnumber should be multiplied by 2 for the power.
		stepnumber = stepnumber*2;
	}
	//if the step is 0 (basecase),
	else
	{
		//the grid is just 1.
		Arrange[0][0] = 1;
		//the stepnumber should be 1 to work properly when multiplied by 2.
		stepnumber=1;
	}
	//call the function again with the new stepnumber.
	generateSchedule(stepnumber);
}


void Scheduler::print()
{
	//for each x and y value,
	for (int i=0; i<teams; i++)
	{
		for (int j=0; j<teams; j++)
		{
		//print the numbers,
			cout << Arrange[i][j] << " ";
		}
		cout << endl;
	}
}

Scheduler::~Scheduler()
{
	//for each array of integers in the main array,
	for (int i=0; i<teams; i++)
	{
		//delete the data.
		delete Arrange[i];
	}
	//finally, delete the main array.
	delete[] Arrange;
}

