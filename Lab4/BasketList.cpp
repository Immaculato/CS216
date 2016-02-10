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
   Basket *currPtr = head;
   Basket *prevPtr = NULL;
   Basket *newBasketPtr;      //points to a new basket
   
   while(currPtr != NULL && eggs > currPtr->egg_num)
   {
      prevPtr = currPtr;
      currPtr = currPtr->nextBasket;
   } 

   newBasketPtr = new Basket(eggs, currPtr);
   prevPtr->nextBasket = newBasketPtr;
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

