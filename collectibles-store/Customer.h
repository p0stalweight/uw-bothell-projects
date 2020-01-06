/*
@author John Postlewaite
@file Customer.h
@date March 4, 2019

File Description:
Customer class inherits from Comparable and can be stored by the SearchTree class. 
Represents a customer in the store, has and ID between 1-1000, and a list of transactions 
that the customer has taken part in, which are Comparables representing products. 
*/
#pragma once
#include "Comparable.h"

#include <vector>

using namespace std;


class Customer : public Comparable {

public:
   /*
   destructor- deallocates the Comparable objects
   that the vector contains pointers to
   pre: none
   post: memory is deallocated
   */
   virtual ~Customer(); 

   /*
   == operator- checks for equality
   of two customers based on their ID
   pre: none
   post: returns a bool indicating equality
   */
   virtual bool operator ==(const Comparable&) const override;

   /*
   != operator- checks for inequality
   of two customers based on their ID
   pre: none
   post: returns a bool indicating inequality
   */
   virtual bool operator !=(const Comparable& c) const override;

   /*
   > operator- checks if left operand has a smaller
   value for customer first name than right
   pre: none
   post: returns a bool indicating if smaller
   */
   virtual bool operator >(const Comparable&) const override;

   /*
   < operator- checks if left operand has a larger
   value for customer first name than right
   pre: none
   post: returns a bool indicating if larger
   */
   virtual bool operator <(const Comparable& c) const override;

   /*
   toString- returns a string of the name, ID and transactions
   of a customer
   pre: none
   post: returns a string with customer information
   */
   virtual string toString() const override; 

   /*
   clone- returns a copy of the customer
   pre: none
   post: pointer is returned with copy of customer
   */
   virtual Comparable* clone()  const override;

   /*
   addTransaction- adds a Comparable representing a 
   product to the end of the customer list
   pre: none
   post: pointer containing product is added
   */
   void addTransaction(Comparable*);

   /*
   getID- returns the ID integer of the customer
   pre: none
   post: returns ID
   */
   int getID() const;

private: 
   /*
   streamIn- sets data fields of Customer
   from cin
   pre: none
   post: sets data fields id, first and last name
   */
   virtual void streamIn(istream&) override;

   int iD; 
   string firstName;
   string lastName; 
   vector<Comparable*> transactionHistory; 

};
