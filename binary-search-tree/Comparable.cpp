#include "Comparable.h"
#include <iostream>
#include <string>

using namespace std;

bool Comparable::operator==(const Comparable & c)
{
   return this->wordStore == c.wordStore; //double check this
}

bool Comparable::operator!=(const Comparable & c)
{
   return !(this->wordStore == c.wordStore);
}

bool Comparable::operator<(const Comparable & c)
{
  return this->wordStore < c.wordStore;
}

bool Comparable::operator>(const Comparable & c)
{
   return this->wordStore > c.wordStore;
}

//istream & operator>>(istream & inputStream, Comparable & toInput)
istream &operator>>(istream &inputStream, Comparable &toInput) {
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

   toInput.wordStore = input;
   return inputStream;
}

ostream & operator<<(ostream & output, Comparable & c)
{

   cout << c.wordStore;
   return output;
}
