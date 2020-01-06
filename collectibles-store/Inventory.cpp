/*
@author John Postlewaite
@file Inventory.h
@date March 15, 2019

File Description: this file contains the storage for the
inventory, a SearchTree for each product type. It also contains
a simple hash table containing a dummy pointer to each product type.

*/
#include "Inventory.h"


/*
constructor- creates a SearchTree for each
Product type by adding a new SearchTree object to productStore
also adds each type of Product to productSelect
pre: Store is constructed
post: object is instantiated
*/
Inventory::Inventory()
{
   //initialize SearchTrees for each product type 
   SearchTree* coin = new SearchTree();
   SearchTree* comic = new SearchTree();
   SearchTree* sportCard = new SearchTree();

   productStore.push_back(coin);
   productStore.push_back(comic);
   productStore.push_back(sportCard);

   //initialize productHash for generating products
   for (int i = 0; i < 101; i++) {
      productHash[i] = nullptr;
   }
   Comparable* coinPtr = new Coin();
   Comparable* comicPtr = new ComicBook();
   Comparable* cardPtr = new SportCard();
  
   char coinCode = coinPtr->getProductCode()[0];
   int coinInt = coinCode - '0';
   productHash[coinInt] = coinPtr;

   char comicCode = comicPtr->getProductCode()[0];
   int comicInt = comicCode - '0';
   productHash[comicInt] = comicPtr;

   char cardCode = cardPtr->getProductCode()[0];
   int cardInt = cardCode - '0';
   productHash[cardInt] = cardPtr;
}

/*
destructor- deallocates the productStore vector
and the HashTable productSelect
pre: none
post: all memory in productStore is deallocated
*/
Inventory::~Inventory()
{
   //deallocate trees
   for(unsigned i = 0; i < productStore.size(); i++){
      delete productStore[i];
      productStore[i] = nullptr;
   }
   //deallocate dummy products
   for(unsigned i = 0; i < PRODUCT_HASH_SIZE; i++){
      if(productHash[i] != nullptr){
         delete productHash[i];
         productHash[i] = nullptr;
      }
   }
}

/*
buildProduct- returns a product that
derives from comparable based on code
that is given
pre: code must be a valid productCode
post: returns pointer to product clone,
or returns nullpointer if code invalid
*/
Comparable * Inventory::buildProduct(string codeString)
{
   char codeChar = codeString[0];
   int codeInt = codeChar - '0'; 
   if(productHash[codeInt] != nullptr){
      return productHash[codeInt]->clone();
   }
   else{
      return nullptr;
   }
}

/*
addProduct- adds a product to the appropriate
SearchTree by using the index code of the product
to determine which product tree to add to
pre: none
post: searchTree product is added and quantity
is set
*/
void Inventory::addProduct(Comparable* product, int amount)
{
   productStore[product->getCode()]->insert(product, amount); 
}

/*
removeProduct- attempts to remove a product from
the appropriate SearchTree by using the index code
of the product to determine which tree to decrement from
pre: none
post: one instance of the product is removed, otherwise
      returns false if product is not there or has a
      count of 0
*/
bool Inventory::removeProduct(Comparable * product, int index)
{
   return productStore[index]->remove(product);

}

/*
prints entire inventory to console by printing each tree
pre: none
post: inventory is printed
*/
void Inventory::printInventory() const
{
   for (int i = 0; i < PRODUCT_COUNT; i++) {
      cout << *(productStore[i]) << endl;
   }
}
