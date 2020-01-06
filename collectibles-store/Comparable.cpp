/*
@author: John Postlewaite
@file: Comparable.cpp
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

#include "Comparable.h"
#include <iostream>
#include <string>

using namespace std;

/*
== operator- compare two Comparable objects for equality, defined as
storing the same string
pre: both current object and paramater object have wordStore field populated
post: returns a boolean indicating if strings stored in the Comparable are
objects are equivalent
*/
bool Comparable::operator ==(const Comparable & c) const
{
   return this->wordStore == c.wordStore; 
}

/*
!= operator- compare two Comparable objects for inequality, defined as
not storing the same string
pre: both current object and paramater object have wordStore field populated
post: returns a boolean indicating if the strings in the two Comparable objects
are unequal
*/
bool Comparable::operator !=(const Comparable & c) const
{
   return !(this->wordStore == c.wordStore);
}

/*
operator <- determine if the current object stores a string of smaller value
than another object
pre: both current object and parameter object have wordStore field populated
post: returns a boolean indicating if the current object stores a lesser string value
than the other Comparable object
*/
bool Comparable::operator <(const Comparable & c) const
{
  
   return this->wordStore < c.wordStore;
}

/*
operator >- determine if the current object stores a string of greater value
than another object
pre: both current object and parameter object have wordStore field populated
post:returns a boolean indicating if the current object stores a greater string
value than the other Comparable object
*/
bool Comparable::operator >(const Comparable & c) const
{
   return this->wordStore > c.wordStore;
}

/*
toString- returns contents of Comparable as string
pre: none
post: returns string
*/
string Comparable::toString() const
{
   return wordStore;
}

/*
getCode- returns indexing code, used by
Comparable products
pre: none
post: returns code
*/
int Comparable::getCode() const
{
   return -1;
}

/*
getCode- returns product code, used by
Comparable products
pre: none
post: returns productCode
*/
string Comparable::getProductCode() const
{
   return "";
}

/*
clone- returns a copy of the Comparable
pre: none
post: returns pointer containing copy
*/
Comparable * Comparable::clone() const
{
   return new Comparable(*this);
}

/*
setData- sets the data fields of the Comparable
pre: none
post: data fields are set
*/
void Comparable::setData(string data)
{
   wordStore = data; 
}

/*
streamIn- allows data for Comparable to be taken from cin
pre: data must conform to standards of cin
post: data fields are set
*/
void Comparable::streamIn(istream & inputStream)
{
   char c;
   string input = "";
   int found = false;

   while (inputStream.get(c)) {
      if (c >= 'A' && c <= 'Z') c = tolower(c);
      if (c < 'a' || c > 'z') {
         if (found) break;
         else continue;
      }
      found = true;
      input += c;
   }

   wordStore = input;
   return;
}

//istream & operator>>(istream & inputStream, Comparable & toInput)
istream &operator>>(istream &inputStream, Comparable &toInput) {
   toInput.streamIn(inputStream);
   return inputStream;
}

ostream & operator<<(ostream & output, Comparable & c)
{

   cout << c.toString();
   return output;
}