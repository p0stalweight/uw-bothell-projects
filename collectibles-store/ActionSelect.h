/*
@author John Postlewaite
@file ActionSelect.h
@date March 4, 2019

File Description: manages the selection of Actions
while processing the data file with the commands. 
Has a pointer to the Store object that it is associated with,
a HashTable that contains each Action. 
*/
#pragma once
#include "Store.h"
#include "Action.h"
#include "Buy.h"
#include "Sell.h"
#include "CustomerHistory.h"
#include "Display.h"
#include "StoreHistory.h"
#include "HashTable.h"

class ActionSelect {
public:
   /*
   constructor- gets a pointer to a store object,
   and constructs each type of Action and stores
   it in actionHash
   pre: store object must be constructed
   post: pointer is stored
   */
   ActionSelect(Store*);

   /*
   doAction- takes in a string containing the code of 
   the action to be performed, and the customer and product
   information for the action (if applicable)
   pre: string contains valid action code and valid
   customer and product data
   post: performs action, or prints an error if data invalid
   */
   void doAction(string, string);
   
private:
   HashTable actionHash;
   Store * store = nullptr; 
};
