/*
@author John Postlewaite
@file Sell.h
@date March 4, 2019

File Description:
This file contains the Action class Sell, which will send a command to the
Store to decrement a particular item to the store inventory when the perform method
is called. Also send sa transaction record to be stored in a particular 
customer's transaction history.

Sell derives from the Action class, and is used in the ActionSelect
class.
*/
#pragma once

#include "Store.h"
#include "Action.h"
#include <iostream>

using namespace std;

class Sell : public Action {
public:
   /*
   Sell Constructor- sets the store
   object to send commands to
   pre: valid Store object pointer
   post: object is created
   */
   Sell(Store*);

   /*
   perform- constructs a product and decrements it from Store
   pre: string parameter contains valid product
        and valid customer, storePtr is populated
        with a store object and inventory intialized
   post: product is added to store, customer
        is updated with transaction
   */
   virtual void perform(string);

   /*
   hashCode- returns hashcode based on
   action code
   pre: none
   post: int hashcode is returned
   */
   virtual int hashCode() const;

private:
   char actionCode = 'S';        //determines hash code
   Store* storePtr;
};