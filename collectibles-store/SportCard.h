/*
@author John Postlewaite
@file SportCard.h
@date March 15, 2019

File Description: this file contains the SportCard class
which derives from Comparable
*/
#pragma once
#include "Comparable.h"

using namespace std; 

class SportCard : public Comparable {
public:
   

   /*
   operator ==- checks if two sportcards are equal
   pre: none
   post: returns true if equal, false if unequal
   */
   virtual bool operator ==(const Comparable&) const override;

   /*
   operator !=- checks if two sportcards are unequal
   pre: none
   post: returns true if unequal, false if equal
   */
   virtual bool operator !=(const Comparable& c) const override;

   /*
   operator >- checks if a sportcard is larger than another sportcard
   pre: none
   post: returns true if larger, false otherwise
   */
   virtual bool operator >(const Comparable&) const override;

   /*
   operator <- checks if a sportcard is smaller than another sportcard
   pre: none
   post: returns true if smaller, false otherwise
   */
   virtual bool operator <(const Comparable& c) const override;

   /*
   toString- returns sportcard data members in string
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
   virtual Comparable* clone() const override;

   /*
   getProductCode- returns a string containing
   the product code, used in product hash table
   pre: none
   post: returns code
   */
   virtual string getProductCode() const override;

   /*
   setData- sets each of the data members of the
   sportcards by parsing a string
   pre: string must conform to structure to be
   parsed into a coin
   post: data members of coin are populated
   */
   virtual void setData(string) override;

private:
   string player;
   int year;
   string manufacturer;
   string grade;

   string productCode = "S";
   int inventoryCode = 2;
};