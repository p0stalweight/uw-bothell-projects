/*
@author John Postlewaite
@file Inventory.h
@date March 15, 2019

File Description: this file contains the storage for the 
inventory, a SearchTree for each product type. It also contains
a simple hash table containing a dummy pointer to each product type.

*/
#pragma once
#include <vector>
#include "SearchTree.h"
#include "Comparable.h"
#include "Coin.h"
#include "ComicBook.h"
#include "SportCard.h"


const int PRODUCT_COUNT = 3;
const int PRODUCT_HASH_SIZE = 101; 

class Inventory {
public:

/*
constructor- creates a SearchTree for each 
Product type by adding a new SearchTree object to productStore
also adds each type of Product to productSelect
pre: Store is constructed
post: object is instantiated
*/
Inventory(); 

/*
destructor- deallocates the productStore vector
and the HashTable productSelect
pre: none
post: all memory in productStore is deallocated
*/
~Inventory(); 

/*
buildProduct- returns a product that
derives from comparable based on code 
that is given
pre: code must be a valid productCode
post: returns pointer to product clone,
      or returns nullpointer if code invalid
*/
Comparable* buildProduct(string);

/*
addProduct- adds a product to the appropriate 
SearchTree by using the index code of the product 
to determine which product tree to add to
pre: none
post: searchTree product is added and quantity 
      is set
*/
void addProduct(Comparable*, int);

/*
removeProduct- attempts to remove a product from 
the appropriate SearchTree by using the index code
of the product to determine which tree to decrement from
pre: none
post: one instance of the product is removed, otherwise
      returns false if product is not there or has a 
      count of 0  
*/
bool removeProduct(Comparable*, int);

/*
prints entire inventory to console by printing each tree
pre: none
post: inventory is printed
*/
void printInventory() const;

private:
vector<SearchTree*> productStore; 
Comparable* productHash[PRODUCT_HASH_SIZE];
};