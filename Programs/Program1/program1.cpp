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
	   cout << "=================================================" << endl;
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
		if (choice == '2')
		{
		 cout << "Sequence:\t";
		 listofnumbers.print();
		}
		if (choice == '3')
		{
		 cout << "1. Insertion sort\n2. Selection sort\n3. Bubble sort\n4. Quit\nOption: ";
		 cin >> line;
		 if (line == "1")
		 {
			listofnumbers.insertion_sort();
		 }
		 else if (line == "2")
		 {
			listofnumbers.selection_sort();
		 }
		 else if (line == "3")
		 {
			listofnumbers.bubble_sort();
		 }
		 else if (line != "4")
		 {
			cout << "Invalid option." << endl;
		 }
		 else
		 {
			continue;
		 }
		}
      } while(choice != 'q');		
}
