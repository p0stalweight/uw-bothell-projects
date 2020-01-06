/*
@author John Postlewaite
@file Coin.h
@date March 15, 2019

File Description: this file contains the Coin class
which derives from Comparable

*/
#include "Coin.h"
#include <string>
#include <sstream>

/*
operator ==- checks if two coins are equal
pre: none
post: returns true if equal, false if unequal
*/
bool Coin::operator ==(const Comparable & o) const
{
   const Coin &c = static_cast<const Coin &>(o);
   return type == c.type && year == c.year && grade == c.grade; 
}

/*
operator !=- checks if two coins are unequal
pre: none
post: returns true if unequal, false if equal
*/
bool Coin::operator !=(const Comparable & o) const
{
   const Coin &c = static_cast<const Coin &>(o);
   return !(*this == c);
}

/*
operator >- checks if a coin is larger than another coin
pre: none
post: returns true if larger, false otherwise
*/
bool Coin::operator >(const Comparable & o) const
{
   const Coin &c = static_cast<const Coin &>(o);

   if (type > c.type) {
      return true;
   }
   else if (type == c.type && year > c.year) {
      return true;
   }
   else if (type == c.type && year == c.year && grade > c.grade) {
      return true;
   }
   else {
      return false;
   }
}

/*
operator <- checks if a coin is smaller than another coin
pre: none
post: returns true if smaller, false otherwise
*/
bool Coin::operator <(const Comparable & o) const
{
   const Coin &c = static_cast<const Coin &>(o);

   if (type < c.type) {
      return true;
   }
   else if (type == c.type && year < c.year) {
      return true;
   }
   else if (type == c.type && year == c.year && grade < c.grade) {
      return true;
   }
   else {
      return false;
   }
}

/*
toString- returns coin data members in string
pre: information variables are initialized
post: returns information as string
*/
string Coin::toString() const
{
  return type + " " + to_string(year) + " " + to_string(grade);
}

/*
getCode- returns int for index code for product
to place it in the correct SearchTree storage
pre: none
post: returns integer with proper index
*/
int Coin::getCode() const
{
   return inventoryCode;
}

/*
clone- creates a copy of the product
pre: none
post: copy is created
*/
Comparable * Coin::clone() const
{
   return new Coin(*this);
}

/*
getProductCode- returns a string containing
the product code, used in product hash table
pre: none
post: returns code
*/
string Coin::getProductCode() const
{
   return productCode;
}

/*
setData- sets each of the data members of the
coin by parsing a string
pre: string must conform to structure to be
parsed into a coin
post: data members of coin are populated
*/
void Coin::setData(string data)
{
   stringstream ss(data);
   string yearString;

   getline(ss, yearString, ',');
   int yearInt = stoi(yearString);
   year = yearInt;

   ss.ignore();

   string gradeString;
   getline(ss, gradeString, ',');
   int gradeInt = stoi(gradeString);
   grade = gradeInt;

   ss.ignore();


   string typeString;
   getline(ss, typeString);
   type = typeString;
}