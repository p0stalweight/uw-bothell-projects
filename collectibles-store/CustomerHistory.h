/*
@author John Postlewaite
@file CustomerHistory.h
@date March 14, 2019

File Description:
This file contains the Action class CustomerHistory, which will send a command to the
Store to print the transactionHisotry of a specific customer. 

CustomerHistory derives from the Action class, and is used in the ActionSelect
class.
*/
#pragma once

#include "Store.h"
#include "Action.h"
#include <iostream>

using namespace std; 

class CustomerHistory : public Action {
public:
   /*
   CustomerHistory Constructor- sets the store
   object to send commands to
   pre: valid Store object pointer
   post: object is created
   */
   CustomerHistory(Store*);

   /*
   perform- sends a command to the Store to
            output the chronological customer activity
            of buys/sells
   pre: string parameter contains valid customer, 
            storePtr is populated
   with a store object and inventory intialized
   post: customer history is output to console
   */
   virtual void perform(string);

   /*
   hashCode- returns hashcode based on
   action code
   pre: none;
   post: int hashcode is returned
   */
   virtual int hashCode() const;

private:
   char actionCode = 'C';        //determines hash code
   Store * storePtr; 
};