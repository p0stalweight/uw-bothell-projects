/*
@author John Postlewaite
@file Display.h
@date March 4, 2019

File Description:
This file contains the Action class Display, which will send a command to the
Store to output the entire inventory of the store. 

Display derives from the Action class, and is used in the ActionSelect
class.
*/
#pragma once

#include "Store.h"
#include "Action.h"
#include <iostream>

using namespace std;

class Display : public Action {
public:
   /*
   Display constructor
   pre: valid Store object pointer
   post: object is created
   */
   Display(Store*);

   /*
   perform- directs the Store object
   to output the entire inventory
   pre: store is instantiated
   post: entire inventory of store is printed to the console
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
   char actionCode = 'D';        //determines hash code
   Store* storePtr;
};