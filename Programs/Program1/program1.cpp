#include "IntSequence.cpp"
#include <cstdlib>
#include <string>

using namespace std;

int main();

int main()
{
	IntSequence listofnumbers;
	char choice;
	string line;
	bool breakflag;
	do
	{
	   cout << "1. Read\n2. Print\n3. Sort\n4. Shuffle\n5. Search\n6. Quit\nOption: ";
	   cin >> choice;
		if (choice == '1')
		{
	 	 breakflag = false;
		 while (!breakflag)
		 {
			//keep reading lines from the file and reversing them.
			cout << "Enter the next element (Enter 'q' to stop): ";
			cin >> line;
			if (line != "q")
			{
				listofnumbers.insert(stoi(line));
			}
			else
			{
				breakflag=true;
			}
			
		 }
		} 
      } while(choice != 'q');		
}
