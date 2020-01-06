/*
@author John Postlewaite
@file StoreHistory.h
@date March 4, 2019

File Description:
This file contains the Action class StoreHistory, which will send a command to the
Store to output each customer sorted by first name and their transaction history.

Storehistory derives from the Action class, and is used in the ActionSelect
class.
*/

#pragma once
#include "Store.h"
#include "Action.h"
#include <iostream>

using namespace std;

class StoreHistory : public Action {

public:
   /*
   StoreHistory Constructor- sets the store
   object to send commands to
   pre: valid Store object pointer
   post: object is created
   */
   StoreHistory(Store*);

   /*
   perform- sends a command to the store to output
   each customer and their transaction history
   pre: store is instantiated
   post: all transactions from all customers are produced in sorted order
   */
   virtual void perform(string);

   /*
   returns hashcode
   pre: none
   post: int hashcode is returned
   */
   virtual int hashCode() const;

private:
   char actionCode = 'H';        //determines hash code
   Store * storePtr; 
};