//course: CS216-00x
//Project: Lab Assignment 5
//Date: 02/14/2016
//Purpose: Read data from an input file which passes in from command line
//         and sort the text lines in a lexicographical order(dictionary order)
//	   No sorting algorithm is needed
//	   Display the sequence before and after sorting
//Author: Yi Pike

#include <fstream>
#include <iostream>
#include <string>
#include "sortings.h"

using namespace std;

int main(int argc, char** argv)  {
   ifstream in_file;

   if (argc != 2)
   {
	cout << "It needs one command line argument: <input filename>!" << endl;
        return 1;
   }

   in_file.open(argv[1]);
   if (!in_file.good())
   {
       cout << "Failure in opening file: " << argv[1] << endl;	
       return 2;
   }

   string  line;
   sortings textLines;

   cout << "The sequence of text lines from FILE " << argv[1] << ", before sorting: " <<endl;

   while (getline(in_file, line))
   {
      cout << line << endl;
      textLines.insert(line);
   }
   if (textLines.getSize() > 0)
   {
      cout <<endl <<endl << "The sequence of text lines after sorting: " <<endl;
      textLines.print();	
   }    

   in_file.close();

   return 0;
}

