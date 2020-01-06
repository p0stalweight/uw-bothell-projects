/*
@author John Postlewaite
@file ActionSelect.cpp
@date March 4, 2019

File Description: manages the selection of Actions
while processing the data file with the commands.
Has a pointer to the Store object that it is associated with,
a HashTable that contains each Action.
*/

#include "ActionSelect.h"

/*
constructor- gets a pointer to a store object,
and constructs each type of Action and stores
it in actionHash
pre: store object must be constructed
post: pointer is stored
*/
ActionSelect::ActionSelect(Store * storePtr)
{
   store = storePtr;
   Action* b = new Buy(store);
   actionHash.insert(b);
   Action* s = new Sell(store);
   actionHash.insert(s);
   Action* d = new Display(store);
   actionHash.insert(d);
   Action* c = new CustomerHistory(store);
   actionHash.insert(c);
   Action* h = new StoreHistory(store);
   actionHash.insert(h);
}

/*
doAction- takes in a string containing the code of
the action to be performed, and the customer and product
information for the action (if applicable)
pre: string contains valid action code and valid
customer and product data
post: performs action, or prints an error if data invalid
*/
void ActionSelect::doAction(string actionCode, string actionContent)
{
   char codeChar = actionCode[0]; 
   int codeInt = codeChar - '0';
   if (actionHash.retrieve(codeInt) != nullptr){
      actionHash.retrieve(codeInt)->perform(actionContent); 
   }
   else{
      cout << "Invalid input. No such action!" << endl; 
   }
}
