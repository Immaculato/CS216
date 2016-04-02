//stack.cpp

#include "stack.h"

using namespace std;

Stack::Stack() 
{
	top = -1;
}

void Stack::push(char item)
{
	cstack.push_back(item);
	top++;
}

bool Stack::empty()
{
	if (top == -1) return true;
	else return false;
}

void Stack::pop()
{
	try {
		if (cstack.size()==0) throw 0;
	} catch (int err) {
		cout << "stack is empty." << endl;
		cout << "Cannot pop an item."<< endl;
		return;
	}
	cstack.pop_back();
	top--;
}

char Stack::stackTop()
{
	try {
		if (cstack.size()==0) throw 0;
	} catch (int err) {
		cout << "stack is empty." << endl;
		return 0;
	}
	return (cstack[top]);
}


