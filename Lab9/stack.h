/* 
 * File:   stack.h
 * Author: Pike
 *
 */

#ifndef STACK_H
#define	STACK_H

#include <iostream>
#include <vector>

using namespace std;

class Stack 
{
  public:
	Stack();
	void push(char item);
	void pop();
	char stackTop();
	bool empty();
  private:
	int top;
	vector<char> cstack;
};


#endif	/* STACK_H */

