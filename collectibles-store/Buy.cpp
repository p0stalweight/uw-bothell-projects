/*
@author John Postlewaite
@file Buy.cpp
@date March 14, 2019

File Description:
This file contains the Action class Buy, which will send a command to the
Store to add a particular item to the store inventory when the perform method
is called. Also sends a transaction record to be stored in
a particular customer's transaction history.

Buy derives from the Action class, and is used in the ActionSelect
class.
*/
#include "Buy.h"
#include <sstream>

using namespace std; 

/*
Buy Constructor- sets the store
object to send commands to
pre: valid Store object pointer
post: object is created
*/
Buy::Buy(Store * store)
{
   storePtr = store; 
}



/*
perform- constructs a product and adds it to the Store
pre: string parameter contains valid product
     and valid customer, storePtr is populated
     with a store object and inventory intialized
post: product is added to store, customer
     is updated with transaction
*/
void Buy::perform(string direction)
{
   //create a stringstream to process string
   //with customer and product data
   stringstream ss(direction);

   //check customer ID
   string idString;
   getline(ss, idString, ',');
   if(!storePtr->verifyCustomer(stoi(idString))){
      cout << "Invalid transaction! Customer not in system." << endl; 
      return; 
   }

   ss.get(); //skip space

   //construct product
   string productCode;
   getline(ss, productCode, ',');
   Comparable* newProduct = storePtr->buildProduct(productCode);
   if (newProduct == nullptr) {
      cout << "Invalid transaction! Product not in system." << endl;
      return;
   }
   string productData; 
   getline(ss, productData);
   newProduct->setData(productData);

   //add product to store and add transaction to customer
   storePtr->buy(newProduct, stoi(idString)); 
}

/*
hashCode- returns hashcode based on
action code
pre: none
post: int hashcode is returned
*/
int Buy::hashCode() const
{
   int baseCode = actionCode - '0';
   return baseCode;
}