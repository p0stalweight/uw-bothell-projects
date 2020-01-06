/*
@author: John Postlewaite
@file: Action.h
date: 3/15/2019

File description: contains the interface for the
Action class, which allows for a polymorphic perform function
for each different action type, as well as a hashCode function that
returns an integer based one the actionCode stored in the class
*/
#pragma once
#include <string>
using namespace std;

class Action {
   public:
   /*
   does an action based on Child class
   pre: will be used when action is selected from HashTable
   post: performs action
   */
   virtual void perform(string) = 0; 

   /*
   provides hash code
   pre:
   post:
   */
   virtual int hashCode() const = 0; 
};