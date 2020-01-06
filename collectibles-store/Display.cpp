/*
@author John Postlewaite
@file Display.cpp
@date March 4, 2019

File Description:
This file contains the Action class Display, which will send a command to the
Store to output the entire inventory of the store.

Display derives from the Action class, and is used in the ActionSelect
class.
*/
#include "Display.h"

/*
Display constructor
pre: valid Store object pointer
post: object is created
*/
Display::Display(Store * store)
{
   storePtr = store;
}



/*
perform- directs the Store object
to output the entire inventory
pre: store is instantiated
post: entire inventory of store is printed to the console
*/
void Display::perform(string direction)
{
   cout << "Store inventory:" << endl; 
   storePtr->printInventory();
}

/*
hashCode- returns hashcode based on
action code
pre: none
post: int hashcode is returned
*/
int Display::hashCode() const
{
   int baseCode = actionCode - '0';
   return baseCode;
}