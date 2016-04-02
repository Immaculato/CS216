//course: CS216-00x
//Project: Lab Assignment 9
//Date: 03/25/2016
//Purpose: to implement conversion tool between the following number systems:
//         between Binary numbers and Decimal numbers;
//         
//Author: (your name)

#include <iostream>
#include "converter.h"

using namespace std;

int main() {
    while(true)
    {
        cout << "=========================================" << endl;
        cout << "1: Binary --> Decimal" << endl;
        cout << "2: Decimal --> Binary" << endl;
        cout << "3: Parentheses Matching" << endl;
        cout << "Others: Quit" << endl;
        cout << "=========================================" << endl;
        int option;
        cin >> option;
        
        if (cin.fail())
        {
            option = 4;
            cin.clear();
            cin.ignore(256, '\n');
        }
        
        switch(option)
        {
            case 1:
            {
                cout << "Enter a binary number: ";
                string b_num;
                cin >> b_num;
                int d_num = Binary_to_Decimal(b_num);
                if (d_num != -1)
                    cout << "Binary:" << b_num << "--> Decimal:" << d_num << endl;
                break;
            }
            case 2:
            {
                cout << "Enter a decimal number: ";
                int d_num;
                cin >> d_num;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(256, '\n');
                }
                else
                    Decimal_to_Binary(d_num);
                break;
            }
            case 3:
            {
                cin.ignore(256, '\n');
                cout << "Enter an expression: ";
                string expression;
                getline(cin, expression);
                if (valid_parentheses(expression))
                    cout << "Parsing parentheses: Matched!" << endl;
                else
                    cout << "Parsing parentheses:  Unmatched!" << endl;
                break;
            }
            default:
            {
                cout << "Thanks for using the program" << endl;
                return 0;
            }     
        }
    }    
}
