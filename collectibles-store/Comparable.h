/*
@author: John Postlewaite
@file: Comparable.h
date: 3/15/2019

File description: The Comparable classprovides a wrapper for a string, 
and overloads operators which allow
comparison for equality as well as greater/lesser relationships.
The class also facillitates usage of the cin and cout operators to
read in a string to the object and to print the contents of an object.

This class can be utilized with the SearchTree class, containing
strings that are stored in the tree.

The Coin, Comicbook, Sportcard and Customer classes inherit from it.
*/


#ifndef COMPARABLE_H
#define COMPARABLE_H

#include <string> 
#include <iostream> 

using namespace std;

class Comparable {

   friend istream& operator >> (istream&, Comparable&);
   friend ostream& operator << (ostream&, Comparable&);

public:
   /*
   == operator- compare two Comparable objects for equality, defined as
   storing the same string
   pre: both current object and paramater object have wordStore field populated
   post: returns a boolean indicating if strings stored in the Comparable are
   objects are equivalent
   */
   virtual bool operator ==(const Comparable& c) const;

   /*
   != operator- compare two Comparable objects for inequality, defined as
   not storing the same string
   pre: both current object and paramater object have wordStore field populated
   post: returns a boolean indicating if the strings in the two Comparable objects
   are unequal
   */
   virtual bool operator !=(const Comparable& c) const;

   /*
   operator <- determine if the current object stores a string of smaller value
   than another object
   pre: both current object and parameter object have wordStore field populated
   post: returns a boolean indicating if the current object stores a lesser string value
   than the other Comparable object
   */
   virtual bool operator <(const Comparable& c) const;

   /*
   operator >- determine if the current object stores a string of greater value
   than another object
   pre: both current object and parameter object have wordStore field populated
   post:returns a boolean indicating if the current object stores a greater string
   value than the other Comparable object
   */
   virtual bool operator >(const Comparable& c) const;

   /*
   toString- returns contents of Comparable as string
   pre: none
   post: returns string
   */
   virtual string toString() const;

   /*
   getCode- returns indexing code, used by
   Comparable products
   pre: none
   post: returns code
   */
   virtual int getCode() const; 

   /*
   getCode- returns product code, used by
   Comparable products
   pre: none
   post: returns productCode
   */
   virtual string getProductCode() const; 

   /*
   clone- returns a copy of the Comparable
   pre: none
   post: returns pointer containing copy
   */
   virtual Comparable* clone() const; 

   /*
   setData- sets the data fields of the Comparable
   pre: none
   post: data fields are set
   */
   virtual void setData (string); 

private:
   /*
   streamIn- allows data for Comparable to be taken from cin
   pre: data must conform to standards of cin
   post: data fields are set
   */
   virtual void streamIn(istream&);
   string wordStore;
};


/*
Adds a string made up of a sequence of alphabetical characters from
istream into the wordStore member variable. Continually adds characters
until a non-alphabetical character is encountered or the stream is completed
pre: istream has characters to be consumed
post: all consective alphabetical charcters from istream are consumed
wordStore is populated with a string
the istream object is returned
*/
istream& operator >>(istream& inputStream, Comparable& toInput);

/*
Outputs the current string stored in the wordStore
member variable in the object
pre: wordStore has been populated with a string
post: the string stored in wordStore is printed to the console
returns the ostream object
*/
ostream& operator <<(ostream& output, Comparable& c);

#endif