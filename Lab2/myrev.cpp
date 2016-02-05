#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

string myrev(string reverse);

string myrev(string reverse)
{
	string tempstring = "";
	//for the length of the provided string,
	for (int i=reverse.length()-1; i >= 0; i--)
	{
		//put each character from back to front into the new string
		tempstring += reverse[i];
	}
	//return the new, reversed string when done.
	return tempstring;
}

int main()
{
	string line;
	//prompt the user for some lines to reverse.
	cout << "Please enter some lines to reverse:\n";
	//while the user hasn't pushed ctrl-d,
	while (!cin.eof())
	{
		//keep getting lines from them, and reversing them.
		getline(cin, line);
		cout << myrev(line) << endl;
	}
	//return 0 to indicate all went well!
	return 0;
}
