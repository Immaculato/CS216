#ifndef SORTINGS_H
#define SORTINGS_H

const int INITIAL_CAPACITY = 5;

class sortings
{
   public:
	sortings(); // create an integer array with capacity = INITIAL_CAPACITY
	sortings(int in_capacity); //create an integer array with capacity = in_capacity
	int getSize();  //return the size of the current array
	void insert(int item);  // insert the item into the end of the integer array and size increased by 1
	void InsertionSort();  // put all the items in the array in non-decreasing order using Insertion Sorting algorithm
	void BubbleSort();   // put all the items in the array in non-decreasing order using Bubble Sorting algorithm
	void print();  // display all the items in the array
        ~sortings();  // destructor
   private:
	int capacity;  // the capacity of the array
	int size;   // the number of integers in the array
	int *intArray; // The pointer points at the first item in the integer array
};

#endif
