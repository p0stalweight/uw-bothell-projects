/*
@author John Postlewaite
@file Comicbook.cpp
@date March 15, 2019

File Description: this file contains the Comicbook class
which derives from Comparable
*/
#include "ComicBook.h"
#include <string>
#include <sstream>

/*
operator ==- checks if two comicbooks are equal
pre: none
post: returns true if equal, false if unequal
*/
bool ComicBook::operator ==(const Comparable &o) const
{
   const ComicBook &c = static_cast<const ComicBook &>(o);
   if (publisher == c.publisher && title == c.title &&
      year == c.year && grade == c.grade) {
      return true;
   }
   else {
      return false;
   }
}

/*
operator !=- checks if two comicbooks are unequal
pre: none
post: returns true if unequal, false if equal
*/
bool ComicBook::operator !=(const Comparable & o) const
{
   const ComicBook &c = static_cast<const ComicBook &>(o);
   return !(*this == c);
}

/*
operator >- checks if a comicbook is larger than another comicbook
pre: none
post: returns true if larger, false otherwise
*/
bool ComicBook::operator >(const Comparable & o) const
{
   const ComicBook &c = static_cast<const ComicBook &>(o);
   if (publisher > c.publisher) {
      return true;
   }
   else if (publisher == c.publisher && title > c.title) {
      return true;
   }
   else if (publisher == c.publisher && title == c.title &&
      year > c.year) {
      return true;
   }
   else if (publisher == c.publisher && title == c.title &&
      year == c.year && grade > c.grade) {
      return true;
   }
   else {
      return false;
   }
}

/*
operator <- checks if a comicbook is smaller than another comicbook
pre: none
post: returns true if smaller, false otherwise
*/
bool ComicBook::operator <(const Comparable & o) const
{
   const ComicBook &c = static_cast<const ComicBook &>(o);
   if (publisher < c.publisher) {
      return true;
   }
   else if (publisher == c.publisher && title < c.title) {
      return true;
   }
   else if (publisher == c.publisher && title == c.title &&
      year < c.year) {
      return true;
   }
   else if (publisher == c.publisher && title == c.title &&
      year == c.year && grade < c.grade) {
      return true;
   }
   else {
      return false;
   }
}

/*
toString- returns comicbook data members in string
pre: information variables are initialized
post: returns information as string
*/
string ComicBook::toString() const
{
   return publisher + " " + title + " " + to_string(year) + " " + grade; 
}

/*
getCode- returns int for index code for product
to place it in the correct SearchTree storage
pre: none
post: returns integer with proper index
*/
int ComicBook::getCode() const
{
   return inventoryCode;
}

/*
clone- creates a copy of the product
pre: none
post: copy is created
*/
Comparable * ComicBook::clone() const
{
   return new ComicBook(*this); //return new copy of object
}

/*
getProductCode- returns a string containing
the product code, used in product hash table
pre: none
post: returns code
*/
string ComicBook::getProductCode() const
{
   return productCode;
}

/*
setData- sets each of the data members of the
coin by parsing a string
pre: string must conform to structure to be
     parsed into a comicbook
post: data members of comicbook are populated
*/
void ComicBook::setData(string data)
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
   string titleString;
   getline(ss, titleString, ',');
   title = titleString;

   ss.ignore();

   string publisherString;
   getline(ss, publisherString);
   publisher = publisherString;
}
