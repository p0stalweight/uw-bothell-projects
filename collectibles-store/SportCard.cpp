/*
@author John Postlewaite
@file SportCard.cpp
@date March 15, 2019

File Description: this file contains the Comicbook class
which derives from Comparable
*/
#include "SportCard.h"
#include <sstream>


/*
operator ==- checks if two sportcards are equal
pre: none
post: returns true if equal, false if unequal
*/
bool SportCard::operator ==(const Comparable & o) const
{
   const SportCard &c = static_cast<const SportCard &>(o);
   if (player == c.player && year == c.year &&
      manufacturer == c.manufacturer && grade == c.grade) {
      return true;
   }
   else {
      return false;
   }
}

/*
operator !=- checks if two sportcards are unequal
pre: none
post: returns true if unequal, false if equal
*/
bool SportCard::operator !=(const Comparable & o) const
{
   const SportCard &c = static_cast<const SportCard &>(o);
   return !(*this == c);
}

/*
operator >- checks if a sportcard is larger than another sportcard
pre: none
post: returns true if larger, false otherwise
*/
bool SportCard::operator >(const Comparable & o) const
{
   const SportCard &c = static_cast<const SportCard &>(o);
   if (player > c.player) {
      return true;
   }
   else if (player == c.player && year > c.year) {
      return true;
   }
   else if (player == c.player && year == c.year &&
      manufacturer > c.manufacturer) {
      return true;
   }
   else if (player == c.player && year == c.year &&
      manufacturer == c.manufacturer && grade > c.grade) {
      return true;
   }
   else {
      return false;
   }
   
}

/*
toString- returns sportcard data members in string
pre: information variables are initialized
post: returns information as string
*/
bool SportCard::operator <(const Comparable & o) const
{
   
   const SportCard &c = static_cast<const SportCard &>(o);
   if (player < c.player) {
      return true;
   }
   else if (player == c.player && year < c.year) {
      return true;
   }
   else if (player == c.player && year == c.year &&
      manufacturer < c.manufacturer) {
      return true;
   }
   else if (player == c.player && year == c.year &&
      manufacturer == c.manufacturer && grade < c.grade) {
      return true;
   }
   else {
      return false;
   }

}

/*
toString- returns sportcard data members in string
pre: information variables are initialized
post: returns information as string
*/
string SportCard::toString() const
{
   return player + " " + to_string(year) + " " + manufacturer + " " + grade;
}

/*
getCode- returns int for index code for product
to place it in the correct SearchTree storage
pre: none
post: returns integer with proper index
*/
int SportCard::getCode() const
{
   return inventoryCode;
}

/*
creates a copy of the product
pre: none
post: copy is created
*/
Comparable * SportCard::clone() const
{
   return new SportCard(*this);
}

/*
getProductCode- returns a string containing
the product code, used in product hash table
pre: none
post: returns code
*/
string SportCard::getProductCode() const
{
   return productCode;
}

/*
setData- sets each of the data members of the
sportcards by parsing a string
pre: string must conform to structure to be
parsed into a coin
post: data members of coin are populated
*/
void SportCard::setData(string data)
{
   stringstream ss(data);
   string yearString;

   getline(ss, yearString, ',');
   int yearInt = stoi(yearString);
   year = yearInt;

   ss.ignore();

   string gradeString;
   getline(ss, gradeString, ',');
   grade = gradeString;

   ss.ignore();
   string playerString;
   getline(ss, playerString, ',');
   player = playerString;

   ss.ignore();

   string manufacturerString;
   getline(ss, manufacturerString);
   manufacturer = manufacturerString;

}
