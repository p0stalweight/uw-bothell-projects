/*
@author John Postlewaite
@file CustomerHistory.cpp
@date March 14, 2019

File Description:
This file contains the Action class CustomerHistory, which will send a command to the
Store to print the transactionHisotry of a specific customer.

CustomerHistory derives from the Action class, and is used in the ActionSelect
class.
*/
#include "CustomerHistory.h"
#include <sstream>

/*
CustomerHistory Constructor- sets the store
object to send commands to
pre: valid Store object pointer
post: object is created
*/
CustomerHistory::CustomerHistory(Store * store)
{
   storePtr = store; 
}



/*
perform- sends a command to the Store to
output the chronological customer activity
of buys/sells
pre: string parameter contains valid customer,
     storePtr is populated
     with a store object and inventory intialized
post: customer history is output to console
*/
void CustomerHistory::perform(string direction)
{
   stringstream ss(direction); 

   //check customer ID
   string idString; 
   getline(ss, idString, ',');
   if (!storePtr->verifyCustomer(stoi(idString))) {
      cout << "Invalid transaction! Customer not in system." << endl;
      return;
   }
   storePtr->printCustomer(stoi(idString));
}

/*
hashCode- returns hashcode based on
action code
pre: none;
post: int hashcode is returned
*/
int CustomerHistory::hashCode() const
{
   int baseCode = actionCode - '0';
   return baseCode;
}



