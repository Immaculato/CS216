//course: CS216-002
//Project: Lab Assignment 8
//program: Lab8.cpp
//Date: 03/25/2016
//Purpose: calculate the average of exam scores with exceptions
//
//Author: Tristan Basil

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

//I reused the base matherror class from the lab.
class Matherr {
    public:
        Matherr() {this->errname = "Math Error.";}
        string getName() const {return this->errname;}
        void setName(string name) {this->errname = name;}
    private: 
        string errname; 
};

//basic definition for dividebyzero error
class DivideByZero : public Matherr
{
    public:
        DivideByZero() {setName("Division by zero");}
};
 
//here is the basic definition for the outofrange error
class OutOfRange : public Matherr
{
   public:
	OutOfRange() {setName("Number out of range");}
};

double calculateAverage(vector<double>& scores)
{
	string userinput;
	double score;
	//until the end of eternity (or the user puts in q to quit)...
	do
        {
                //get the user's input for a score.
                cout << "Enter a student's score:" << endl;
                cout << "Press Q to quit." << endl;
                cin >> userinput;
                istringstream iss(userinput);
                //if they input Q,
                if (userinput == "Q" | userinput == "q")
                {
			//try and see if the average can be calculated.
			try {
				if (scores.size() == 0)
				{
					//throw a dividebyzero error if it can't!
					throw DivideByZero();
				}
				double total=0.0;
				//if we get this far, calculate the average and return it.
				for (int i=0; i<scores.size(); i++)
				{
					total+=scores[i];
				}
				return (total/scores.size());
			}
			//if a dividebyzero error was thrown, say what happened and continue.
			catch (DivideByZero& err) {
			cout << "Exception: " << err.getName() << endl;
			continue;
			}
			
		}

                //if they input anything else, attempt to convert it to a double.
                iss >> score;
		//try to see if the score is in range, or if it even is a score.
		try {
			//if not,
			if (score < 0 | score > 100 | iss.fail())
			{
				//throw an outofrange error!
				throw OutOfRange();
			}
		}
		//if an outofrange error was thrown,
		catch (OutOfRange& err) {
			//say what happened, and continue,
			cout << "Exception: " << err.getName() << endl;
			continue;
		}
		//iff all of this checks out, put the double on the vector.
		scores.push_back(score);
	}
	while (true);
}
			
			
 
int main() {
    vector<double> scores;
    //calculate the average and display it nicely.
    cout << "The average score of " << scores.size() << " students is: " << calculateAverage(scores) << endl;
    return 0;
}
