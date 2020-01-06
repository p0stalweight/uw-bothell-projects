/*
@author John Postlewaite
@file CustomerList.cpp
@date March 4, 2019

File Description: this file contains the SearchTree with the customers
sorted alphabetically by first name, as well as an array which stores each
customer by ID number.

*/
#include "CustomerList.h"

/*
default constructor, initialize customerHash to null
pre: Store is created
post: object is creadted
*/
CustomerList::CustomerList()
{
   for (int i = 0; i < CUSTOMER_LIMIT; i++){
      customerHash[i] = nullptr; 
   }
}


/*
destructor, deallocates customerTree
pre: none
post: memory is deallocated
*/
CustomerList::~CustomerList()
{
   for (int i = 0; i < CUSTOMER_LIMIT; i++){
         customerHash[i] = nullptr;
   }
}

/*
prints the transactions of all customers contained in tree
pre: none
post: all transactions of customers and their names are output to console
*/
void CustomerList::printAllCustomers() 
{
   cout << customerStorage; 
}

/*
finds a specific customer in the tree and prints their transaction
history
pre: none
post: returns true if customer is found and
transaction history is printed, otherwise
returns false
*/
void CustomerList::printCustomer(int customerID) const
{
   if(!verifyCustomer(customerID)){
      cout << "That customer is not in the system!" << endl;
   }else{
      cout << *customerHash[customerID] << endl;
   }
}

/*
finds a specific customer in the tree and prints their transaction
history
pre: none
post: returns true if customer is found and
transaction history is printed, otherwise
returns false
*/
bool CustomerList::verifyCustomer(int customerID) const
{
   if (customerHash[customerID] == nullptr) {
      return false;
   }else{
      return true;
   }
}

/*
adds a customer to the customer storage
pre: none
Post: adds customer, returns true,
returns false if customer already exists in system
*/
void CustomerList::addCustomer(Customer * customer)
{
   //add to Hash Table as Customer
   customerHash[customer->getID()] = customer; 
   Comparable * sortedCustomer = customer; 
   customerStorage.insert(sortedCustomer); 
   //add to SearchTree as Comparable 
}

/*
adds a record of a transaction to a customer
pre: transaction occurs (Buy or Sell Action)
post: returns true if transaction is added, false
if customer cannot be located
*/
bool CustomerList::addTransaction(Comparable * product, int iD)
{
   if (customerHash[iD] == nullptr){
      cout << "The customer ID number is invalid!" << endl;
      delete product; 
      return false;
   }else{
      customerHash[iD]->addTransaction(product); 
      return true; 
   }
}
