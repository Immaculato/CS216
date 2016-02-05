#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

string myrev(string reverse);

string myrev(string reverse)
{
	string tempstring = "";
	//for the length of the given string,
	for (int i=reverse.length()-1; i >= 0; i--)
	{
		//put each character, from back to front, in the string
		tempstring += reverse[i];
	}
	//after, return the reversed string.
	return tempstring;
}

int main(int argc, char* argv[])
{
	//if the program was called without a filename,
	if (argc == 1)
	{
		string line;
		//prompt the user for some lines, and
		cout << "Please enter some lines to reverse:\n";
		//read the lines, reverse them until they input ctrl-d.
		while (!cin.eof())
		{
			getline(cin, line);
			cout << myrev(line) << endl;
		}
	}

	//if the program was called with 1 argument,
	else if (argc == 2)
	{
		string line;
		ifstream infile;
		//attempt the open the argument as a file.
		infile.open(argv[1]);
		//if the argument can't be opened as a file,
		if (infile.fail() == true)
		{
			//say so, and return 1 to indicate an error.
			cout << "File open failure!" << endl;
			return 1;
		}
		//with a good file, while the end of the file isn't reached,
		while (!infile.eof())
		{
			//keep reading lines from the file and reversing them.
			getline(infile, line);
			cout << myrev(line) << endl;
		}
	}

	//if 2 or more arguments are provided,
	else
	{
		//explain correct usage of arguments for the program.
		cout << "Usage: ./myreverse or ./myreverse <filename>\n";
	}
	//return 0 if all goes according to plan!
	return 0;
}
