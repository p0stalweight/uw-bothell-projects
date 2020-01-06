/*
@author: John Postlewaite
@file: HashTable.h
date: 3/15/2019

File description: This file contains the HashTable class which
stores Action pointers. It is used to select an Action based on a
specific character that is input. There will not be any collisions
since the index value is based on the character code for each
Action, which are different. If extended, this class would need to utilize
probing.
*/
#pragma once
#include "Action.h"

using namespace std; 

const int HASH_TABLE_SIZE = 1001;

class HashTable {

public: 
   /*
   default cosntructor creates a new HashTable
   pre: none
   post: object is created
   */
   HashTable();

   /*
   destructor deallocates all memory in HashTable
   pre: none
   post: memory is deallocated
   */
   ~HashTable(); 

   /*
   inserts an object into the array according to hashed index, probes if necessary
   pre: none
   post: item is inserted into array
   */
   void insert(Action*);

   /*
   removes an object from the array according to hashed index, probes if necessary
   pre: none
   post: item is inserted into array
   */
   void remove(int hashCode); 

   /*
   returns an object from the array according to hashed index, probes if necessary
   pre: none
   post: item is inserted into array
   */
   Action* retrieve(int hashCode) const; 

private:
    Action* hashStorage[HASH_TABLE_SIZE];
};