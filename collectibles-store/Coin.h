/*
@author John Postlewaite
@file Coin.h
@date March 15, 2019

File Description: this file contains the Coin class
which derives from Comparable

*/
#pragma once
#include "Comparable.h"
#include <iostream>
#include <sstream>

using namespace std; 

class Coin : public Comparable {
  
public:
   /*
   operator ==- checks if two coins are equal
   pre: none
   post: returns true if equal, false if unequal
   */
   virtual bool operator ==(const Comparable&) const override;

   /*
   operator !=- checks if two coins are unequal
   pre: none
   post: returns true if unequal, false if equal
   */
   virtual bool operator !=(const Comparable& c) const override;
   
   /*
   operator >- checks if a coin is larger than another coin
   pre: none
   post: returns true if larger, false otherwise
   */
   virtual bool operator >(const Comparable&) const override;

   /*
   operator <- checks if a coin is smaller than another coin
   pre: none
   post: returns true if smaller, false otherwise
   */
   virtual bool operator <(const Comparable& c) const override;

   /*
   toString- returns coin data members in string
   pre: information variables are initialized
   post: returns information as string
   */
   virtual string toString() const override;

   /*
   getCode- returns int for index code for product
   to place it in the correct SearchTree storage
   pre: none
   post: returns integer with proper index
   */
   virtual int getCode() const override;

   /*
   clone- creates a copy of the product
   pre: none
   post: copy is created
   */
   virtual Comparable* clone()  const override;

   /*
   getProductCode- returns a string containing 
   the product code, used in product hash table
   pre: none
   post: returns code
   */
   virtual string getProductCode() const override;
   
   /*
   setData- sets each of the data members of the 
   coin by parsing a string
   pre: string must conform to structure to be
   parsed into a coin
   post: data members of coin are populated
   */
   virtual void setData(string) override; 

private:
   string type; 
   int year;
   int grade;
   string productCode = "M";
   int inventoryCode = 0; 
};
