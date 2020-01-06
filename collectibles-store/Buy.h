/*
@author John Postlewaite
@file Buy.h
@date March 14, 2019

File Description:
This file contains the Action class Buy, which will send a command to the
Store to add a particular item to the store inventory when the perform method 
is called. Also sends a transaction record to be stored in 
a particular customer's transaction history. 

Buy derives from the Action class, and is used in the ActionSelect
class.
*/

#pragma once

#include "Store.h"
#include "Action.h"
#include <iostream>

using namespace std;

class Buy : public Action{
public:
   /*
   Buy Constructor- sets the store
   object to send commands to
   pre: valid Store object pointer
   post: object is created
   */
   Buy(Store*);

   /*
   perform- constructs a product and adds it to the Store 
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
   char actionCode = 'B';         //determines hashCode
   Store * storePtr; 
};