/*
@author John Postlewaite
@file CustomerList.h
@date March 4, 2019

File Description: this file contains the SearchTree with the customers
sorted alphabetically by first name, as well as an array which stores each
customer by ID number. 

*/
#pragma once

#include "SearchTree.h"
#include "Customer.h"

using namespace std; 

const int CUSTOMER_LIMIT = 1001; 

class CustomerList{
public:
   /*
   default constructor, initialize customerHash to null 
   pre: Store is created
   post: object is creadted
   */
   CustomerList(); 

   /*
   destructor, deallocates customerTree
   pre: none
   post: memory is deallocated
   */
   ~CustomerList();

   /*
   prints the transactions of all customers contained in tree
   pre: none
   post: all transactions of customers and their names are output to console
   */ 
   void printAllCustomers();

   /*
   finds a specific customer in the tree and prints their transaction 
   history  
   pre: none
   post: returns true if customer is found and
   transaction history is printed, otherwise
   returns false
   */ 
   void printCustomer(int) const;

   /*
   finds a specific customer in the tree and prints their transaction
   history
   pre: none
   post: returns true if customer is found and
   transaction history is printed, otherwise
   returns false
   */
   bool verifyCustomer(int) const;

   /*
   adds a customer to the customer storage
   pre: none
   Post: adds customer, returns true,
    returns false if customer already exists in system
   */
   void addCustomer(Customer*);

   /*
   adds a record of a transaction to a customer
   pre: transaction occurs (Buy or Sell Action)
   post: returns true if transaction is added, false
   if customer cannot be located
   */
   bool addTransaction(Comparable *, int);
   
private:
   SearchTree customerStorage;
   Customer* customerHash[CUSTOMER_LIMIT]; 
};