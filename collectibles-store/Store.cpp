/*
@author John Postlewaite
@file Store.h
@date March 4, 2019

File Description: this class provides the manager
for the store actions, it contains the Inventory
and CustomerList objects, and it manages the initialization
of the inventory and customers, as well as processing the
commands from ActionSelect

*/
#include "Store.h"
#include <fstream>

/*
buildProduct- returns a clone of a product type
if a productCode is given
pre: string passed must be valid code
post: returns a product if code is valid
otherwise returns null pointer
*/
Comparable* Store::buildProduct(string productCode)
{
   return inventory.buildProduct(productCode);
}

/*
addProduct- adds a product with a specific quantity
to the Inventory
pre: product has data fields initialized
post: product is added to inventory
*/
void Store::addProduct(Comparable* product, int amount)
{

   inventory.addProduct(product, amount);
}

/*
sell- sends a sell command to the inventory List,
and sends a transaction record to CustomerList
pre: inventory must be initialized
post: returns false if the product is not contained
otherwise removes one instance of item and returns true
sends a transaction record to CustomerList
*/
bool Store::sell(Comparable * product, int iD)
{
   if (inventory.removeProduct(product, product->getCode())) {
      Comparable* productCopy = product->clone(); 
      customerList.addTransaction(productCopy, iD);
      return true; 
   }
   else{
      return false;
   }
}

/*
buy- sends a buy command to inventory list
sends a transaction record to CustomerList
pre: inventory must be initialized
post: adds an instance of the product to the
inventory, sends a transaction record to CustomerList
*/
void Store::buy(Comparable* product, int iD)
{
   Comparable* productCopy = product->clone();
   if(customerList.addTransaction(productCopy, iD)){
      inventory.addProduct(product, product->getCode());  
   }else{
      cout << "Product could not be added!" << endl;
      delete product;   
   }
}

/*
printInventory- a display command to inventory list, printing
each item and its quantity to the console in order
output all coins(1), then all comics(2), then all sports cards(3).
pre:inventory is initialized
post: inventory is displayed to console
*/
void Store::printInventory()
{
   inventory.printInventory(); 
}

/*
addCustomer- adds a customer to the customerList
pre: Customer has data members populated
post: Customer is added to CustomerList
*/
void Store::addCustomer(Customer * customer)
{
   customerList.addCustomer(customer);
}

/*
verifyCustomer- checks if there is a customer
for a given ID in customerList
pre: CustomerList is initialized with customers
post: returns a bool indicating if customer exists
*/
bool Store::verifyCustomer(int customerID)
{
   return customerList.verifyCustomer(customerID);
}

/*
printCustomer- given an ID for a customer, prints
their transactionhistory in chronological order
from customerList
pre: none
post: returns false if customer ID is not found otherwise
prints the customers transaction history in order
*/
void Store::printCustomer(int id)
{
   customerList.printCustomer(id);
}


/*
printAllCustomer- prints the history of each customer
in alphabetical order
pre: none
post: history for each customer is printed to the console
*/
void Store::printAllCustomers()
{
   customerList.printAllCustomers(); 
}

/*
addTransaction- adds a transaction to the record of
a customer indicated by ID number
pre: ID must be valid
post: transaction is added to customer in CustomerList
*/
bool Store::addTransaction(Comparable * product, int iD)
{
   return customerList.addTransaction(product, iD);
}