/*
@author John Postlewaite
@file StoreHistory.cpp
@date March 4, 2019

File Description:
This file contains the Action class StoreHistory, which will send a command to the
Store to output each customer sorted by first name and their transaction history.

Storehistory derives from the Action class, and is used in the ActionSelect
class.
*/
#include "StoreHistory.h"
#include <iostream>
using namespace std;

/*
StoreHistory Constructor- sets the store
object to send commands to
pre: valid Store object pointer
post: object is created
*/
StoreHistory::StoreHistory(Store * store)
{
   storePtr = store; 
}


/*
perform- sends a command to the store to output
each customer and their transaction history
pre: store is instantiated
post: all transactions from all customers are produced in sorted order
*/
void StoreHistory::perform(string direction)
{
   cout << "Customer transaction history:" << endl;
   storePtr->printAllCustomers();
}


/*
returns hashcode
pre: none
post: int hashcode is returned
*/
int StoreHistory::hashCode() const
{
   int baseCode = actionCode - '0';
   return baseCode;
}

