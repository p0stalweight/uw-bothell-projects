/*
@author: John Postlewaite
@file: Comparable.h
date: 1/16/2019

This file contains the interface for the Comparable class. This class
provides a wrapper for a string, and overloads operators which allow 
comparison for equality as well as greater/lesser relationships. 
The class also facillitates usage of the cin and cout operators to
read in a string to the object and to print the contents of an object.

This class can be utilized with the SearchTree class, containing 
strings that are stored in the tree.
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
   Compare two Comparable objects for equality, defined as
   storing the same string
   pre: both current object and paramater object have wordStore field populated
   post: returns a boolean indicating if strings stored in the Comparable are
   objects are equivalent
   */
   bool operator==(const Comparable& c);

   /*
   Comparare two Comparable objects for inequality, defined as
   not storing the same string
   pre: both current object and paramater object have wordStore field populated
   post: returns a boolean indicating if the strings in the two Comparable objects
   are unequal
   */
   bool operator!=(const Comparable& c);

   /*
   Determine if the current object stores a string of smaller value
   than another object
   pre: both current object and parameter object have wordStore field populated
   post: returns a boolean indicating if the current object stores a lesser string value
   than the other Comparable object
   */
   bool operator<(const Comparable& c);

   /*
   Determine if the current object stores a string of greater value
   than another object
   pre: both current object and parameter object have wordStore field populated
   post:returns a boolean indicating if the current object stores a greater string
   value than the other Comparable object
   */
   bool operator>(const Comparable& c);


private: 
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