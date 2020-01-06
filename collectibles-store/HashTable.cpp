/*
@author: John Postlewaite
@file: HashTable.cpp
date: 3/15/2019

File description: This file contains the HashTable class which
stores Action pointers. It is used to select an Action based on a
specific character that is input. There will not be any collisions
since the index value is based on the character code for each
Action, which are different. If extended, this class would need to utilize
probing. 
*/
#include "HashTable.h"

/*
default cosntructor creates a new HashTable
pre: none
post: object is created
*/
HashTable::HashTable()
{
   for (int i = 0; i < HASH_TABLE_SIZE; i++){
      hashStorage[i] = nullptr;
   }
}

/*
destructor deallocates all memory in HashTable
pre: none
post: memory is deallocated
*/
HashTable::~HashTable()
{
   for (int i = 0; i < HASH_TABLE_SIZE; i++){
      if(hashStorage[i] != nullptr){
         delete hashStorage[i];
         hashStorage[i] = nullptr;
      } 
   }
}

/*
inserts an object into the array according to hashed index, probes if necessary
pre: none
post: item is inserted into array
*/
void HashTable::insert(Action* object)
{
   hashStorage[object->hashCode() % HASH_TABLE_SIZE] = object;
}

/*
removes an object from the array according to hashed index, probes if necessary
pre: none
post: item is inserted into array
*/
void HashTable::remove(int hashCode)
{
   if(hashStorage[hashCode %  HASH_TABLE_SIZE] != nullptr){
      delete hashStorage[hashCode %  HASH_TABLE_SIZE];
      hashStorage[hashCode % HASH_TABLE_SIZE] = nullptr;
   }
}

/*
returns an object from the array according to hashed index, probes if necessary
pre: none
post: item is inserted into array
*/
Action* HashTable::retrieve(int hashCode) const
{
   return hashStorage[hashCode %  HASH_TABLE_SIZE];
}