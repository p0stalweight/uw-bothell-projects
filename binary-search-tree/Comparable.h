#ifndef COMPARABLE_H
#define COMPARABLE_H

#include <string> 
#include <iostream> 

using namespace std;

class Comparable {
//friend << and >>
   friend istream& operator >> (istream&, Comparable&);
   friend ostream& operator << (ostream&, Comparable&);

public:
   //bool operator== checks if two strings are equal (two comparables)
   bool operator==(const Comparable& c);

   //bool operator!= checks if two strings are not equal
   bool operator!=(const Comparable& c);

   //bool operator<, checks if left operand is less than R operand 
   bool operator<(const Comparable& c);

   //bool  operator> checks if right operand is less than R operand 
   bool operator>(const Comparable& c);



private: 
string wordStore; 


};


//operator>>: this should read in a word similar to your previous assignment (only letters that are not separated by any non-letters).
// The encapsulated string may be empty if there are no letters remaining in the file.
istream& operator >>(istream& inputStream, Comparable& toInput);

//operator<<: Prints a comparable this should use string::operator<< - make sure to use syntax that allows chaining such as: cout << c1 << " " << c2 << endl;
ostream& operator <<(ostream& output, Comparable& c);

#endif