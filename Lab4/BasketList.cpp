/* 
 * File:   BasketList.cpp
 *
 * Created on January 08, 2016
 *
 * Purpose: provide implementation of member functios of two classes named Basket and BasketList respectively.
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "BasketList.h"

using namespace std;

//---------------------------------------------------
//Basket Members
//---------------------------------------------------
Basket::Basket(int _datum, Basket * _next):
   egg_num(_datum), nextBasket(_next)
{}


int Basket::getEggs() const
{ 
   return egg_num; 
}


Basket const* Basket::getNextBasket() const
{ 
   return nextBasket; 
}



//---------------------------------------------------
//BasketList Members
//---------------------------------------------------
BasketList::BasketList() :
    head (NULL)
{}

void BasketList::insertBasket(int eggs)
{
   Basket* currBasket = head;
   Basket* prevBasket = NULL;

	//if the list is uninitialized (the current basket is null),
   if (currBasket == NULL)
   {
	//the head should be initialized as a new basket, with a NULL next pointer. 
	head = new Basket(eggs, prevBasket);
	//we're done here!
	return;
   }
 	//while the current basket is NOT null, and the given number of eggs is
	//greater than the current baskets, 
   while (currBasket != NULL && eggs > currBasket->egg_num)
   {
	//make the previous basket the current basket (go forwards)
      prevBasket = currBasket;
	//make the current basket the next basket and look again.
      currBasket = currBasket->nextBasket;
   }
 
 
	//if the list was initialzed when inserting (i.e. function is still going),
	//make a new basket at the location it belongs (before the current basket).
	Basket* newBasketPtr = new Basket(eggs, currBasket);
	//don't forget to specify that the previous basket's next pointer is the new one,
	//that is, if there is a previous!!
	if (prevBasket != NULL)
	{
		prevBasket->nextBasket = newBasketPtr;
	}
}

// create a backet list which contains INITIALBASKETS baskets
void BasketList::makeBasketList()
{
   const int INITIALBASKETS = 5;
   int eggValue;
   Basket *newBasketPtr; 
   
   srand(time(0));
   
   for (int i=0; i < INITIALBASKETS; i++)
   {
       eggValue = rand() % (MAXEGGS + 1);
       insertBasket(eggValue);
   }              
} 

void BasketList::deleteBasket (int eggs)
{
   Basket *delPtr = head;
   Basket *prevPtr = NULL;

   // If the list is empty, then do nothing;
   if (delPtr == NULL)
        return;
   
   //Treat the first basket as a special case... head needs to be updated
   if (head->egg_num == eggs)
   {
        head = head->nextBasket;
   }
   else
   {
        prevPtr = delPtr;
        //Look for the basket to be deleted
        while (delPtr != NULL && delPtr->egg_num < eggs)
        {
            prevPtr = delPtr; 
            delPtr = delPtr->nextBasket;
        }
      
        prevPtr->nextBasket = delPtr->nextBasket;      
   }

   //Delete the node
   delete delPtr;
}


void BasketList::printBasketList () 
{
    Basket *currPtr;
    currPtr = head;
    int count = 0;
    if (currPtr == NULL)
    {    
        cout << "Empty! Collect more..." << endl;
        return;
    }   
    while (currPtr != NULL)
    {
        count++; 
        cout << "Basket " << count << " contains " << currPtr->egg_num << " eggs." << endl;
        currPtr = currPtr->nextBasket;
    }
}

