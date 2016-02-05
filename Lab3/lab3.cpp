//course: CS216-00x
//Project: Lab Assignment 3
//Date: 01/30/2016
//Purpose: Read data from two input files which passes in from command line arguments
//         and sort the integers in a non-decreasing order
//         using Insertion Sorting and Bubble Sorting algorithms respectively
//	   Display the sequence before and after sorting
//Author: Yi Pike

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "sortings.h"

using namespace std;

int main(int argc, char** argv)  {
   ifstream in_file1, in_file2;

   if (argc != 3)
   {
	cout << "It needs two command line arguments: <input filename1> <input filename2>!" << endl;
        return 1;
   }

   in_file1.open(argv[1]);
   if (!in_file1.good())
   {
       cout << "Failure in opening file: " << argv[1] << endl;	
       return 2;
   }

   in_file2.open(argv[2]);
   if (!in_file2.good())
   {
       cout << "Failure in opening file: " << argv[2] << endl;  
       return 2;
   }

   string  line;
   sortings myint_sort1, myint_sort2;

   cout << "The sequence of integers from FILE " << argv[1] << " before sorting: " <<endl;

   while (getline(in_file1, line))
   {
      istringstream ss(line);
      int data;
      ss >> data;
      cout << data << endl; 
      myint_sort1.insert(data);
   }
   if (myint_sort1.getSize() > 0)
   {
      myint_sort1.InsertionSort();
      cout << "The sequence of integers after sorting: " <<endl;
      myint_sort1.print();	
   }    

   in_file1.close();

   cout << "The sequence of integers from FILE " << argv[2] << " before sorting: " <<endl;

   while (getline(in_file2, line))
   {
      istringstream ss(line);
      int data;
      ss >> data;
      cout << data << endl; 
      myint_sort2.insert(data);
   }
   if (myint_sort2.getSize() > 0)
   {
      myint_sort2.BubbleSort();
      cout << "The sequence of integers after sorting: " <<endl;
      myint_sort2.print();      
   }    

   in_file2.close();

   return 0;
}

