#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <vector>

using namespace std;

bool isPowerOfTwo(int number);
//helper function to see if a number is a power of two

class Scheduler{   
public:
 Scheduler();  // default constructor
 Scheduler(int ini_teams);  // constructor
// generate the schedule for the number of team = teams
 void generateSchedule(int remainingteams); 
 // display the table content of the schedule for each team
 void print();
 ~Scheduler(); //destructor
// more member functions here ...     
private:
 int teams;    // the number of teams to be scheduled 
 int** Arrange;
                 // array to represent the scheduling table for each team    // the two dimensional vector to represent the 
				  //scheduling table for each team
};

#endif
