/*
Program 2 - Scheduler header file
Tristan Basil
Univeristy of Kentucky
Student ID: 12008804
*/

#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <vector>

using namespace std;

/*
bool isPowerOfTwo(int number) -
description: helper function that returns true if the number is a power of two, false otherwise.
input: an integer number (positive)
output: true if a power of two, false otherwise
std. output: none
*/
bool isPowerOfTwo(int number);

class Scheduler{   
public:
 Scheduler();  // default constructor
 Scheduler(int ini_teams);  // constructor

/*
generateSchedule(int remainingteams) -
description: generates the grid schedule for the scheduler object. note that this only works if the teams is a power of two.
input: always 0
output: none
std. output: none
modifies: team schedule array, arranges it
*/
 void generateSchedule(int remainingteams); 
/*
print() -
description: prints the grid of team matchups to standard output.
input: none
output: none
std. output: outputs the team schedule in a grid
modifies: none
*/
 void print();
 ~Scheduler(); //destructor 
private:
 int teams;    // the number of teams to be scheduled 
 int** Arrange;
 // array to represent the scheduling table for each team    

};

#endif
