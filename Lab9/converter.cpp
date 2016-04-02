//converter.cpp

#include <iostream>
#include "stack.h"
#include "converter.h"



int Binary_to_Decimal(string b_num)
{
    //function for converting binary to decimal

    int d_num = 0;
    for (int i = 0; i < b_num.length(); i++)
    {
        if (b_num.substr(i,1) == "0")
            d_num = 2 * d_num;
        else if (b_num.substr(i,1) == "1")
                d_num = 2 * d_num + 1;
             else {
                 cout << "it contains invalid digit." << endl;
                 return -1;
             }    
    }
    return d_num;   
}

void Decimal_to_Binary(int d_num)
{
    //function for converting decimal to binary
            
    char digit;
    Stack toReverse;
    
    cout << "Decimal:" << d_num; 
    
    while (d_num > 0)
    {
        digit = d_num % 2 + '0';
        toReverse.push(digit);
        d_num = d_num / 2;
    } 
    
    if (toReverse.empty())
    {
        cout << endl << "Invalid Decimal Number" << endl;
        return;
    }
    cout  << "--> Binary: ";
    while (!toReverse.empty())
    {
        cout << toReverse.stackTop();
        toReverse.pop();
    } 
    cout << endl;
}

bool valid_parentheses(string E)
{
	Stack parentheses;
	//for each character in the string,
	for (int i=0; i<E.length(); i++)
	{
		//if the character is a opening parentheses
		if (E[i] == '(')
		{
			//push something on the stack to note it.
			parentheses.push(0);
		}
		//if the character is a closing parentheses and the stack is empty,
		else if (E[i] == ')' && parentheses.empty())
		{
			//this parentheses could never be matched! return false
			return false;
		}
		//if the character is a closing parentheses and the stack isnt empty,
		else if (E[i] == ')')
		{
			//pop off the note you made of an opening one.
			parentheses.pop();
		}
	}
	//at the end, return the status of the stack having something in it.
	return parentheses.empty();
}
