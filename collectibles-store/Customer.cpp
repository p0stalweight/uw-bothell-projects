/*
@author John Postlewaite
@file Customer.cpp
@date March 4, 2019

File Description:
Customer class inherits from Comparable and can be stored by the SearchTree class.
Represents a customer in the store, has and ID between 1-1000, and a list of transactions
that the customer has taken part in, which are Comparables representing products.
*/
#include "Customer.h"

using namespace std;

/*
destructor- deallocates the Comparable objects
that the vector contains pointers to
pre: none
post: memory is deallocated
*/
Customer::~Customer()
{
   for (unsigned index = 0; index < transactionHistory.size(); ++index)
   {
      delete transactionHistory[index];
      transactionHistory[index] = nullptr;
   }
}

/*
== operator- checks for equality
of two customers based on their ID
pre: none
post: returns a bool indicating equality
*/
bool Customer::operator ==(const Comparable & o) const
{
   const Customer &c = static_cast<const Customer &>(o);
   return iD == c.iD;
}

/*
!= operator- checks for inequality
of two customers based on their ID
pre: none
post: returns a bool indicating inequality
*/
bool Customer::operator !=(const Comparable & o) const
{
   const Customer &c = static_cast<const Customer &>(o);
   return !(iD == c.iD);
}

/*
> operator- checks if left operand has a smaller
value for customer first name than right
pre: none
post: returns a bool indicating if smaller
*/
bool Customer::operator >(const Comparable & o) const
{
   const Customer &c = static_cast<const Customer &>(o);
   if(firstName > c.firstName){
      return true;
   } else{
      return false;
   }
}

/*
< operator- checks if left operand has a larger
value for customer first name than right
pre: none
post: returns a bool indicating if larger
*/
bool Customer::operator<(const Comparable & o) const
{
   const Customer &c = static_cast<const Customer &>(o);
   if (firstName < c.firstName) {
      return true;
   }
   else {
      return false;
   }
}

/*
toString- returns a string of the name, ID and transactions
of a customer
pre: none
post: returns a string with customer information
*/
string Customer::toString() const
{
   string transactions = "";
   for (unsigned index = 0; index < transactionHistory.size(); ++index)
   {
     transactions += transactionHistory[index]->toString() + '\n' ; 
   }
   return "ID: " + to_string(iD) + " Name: " + firstName + " " + lastName + " " + '\n' + transactions; 
}

/*
clone- returns a copy of the customer
pre: none
post: pointer is returned with copy of customer
*/
Comparable * Customer::clone() const
{
   return new Customer(*this);
}

/*
addTransaction- adds a Comparable representing a
product to the end of the customer list
pre: none
post: pointer containing product is added
*/
void Customer::addTransaction(Comparable * product)
{
   transactionHistory.push_back(product);
}

/*
getID- returns the ID integer of the customer
pre: none
post: returns ID
*/
int Customer::getID() const
{
   return iD;
}

/*
streamIn- sets data fields of Customer
from cin
pre: none
post: sets data fields id, first and last name
*/
void Customer::streamIn(istream & inputStream)
{
   //get ID
   string idString;
   getline(inputStream, idString, ',');
   int idInt = stoi(idString);
   iD = idInt;

   inputStream.ignore(); //skip space

   //get name
   string nameString;
   getline(inputStream, nameString); 
   bool twoNames = false;
   int spaceIndex;
   for(unsigned i = 0; i < nameString.length(); i++){
      if(nameString[i] == ' '){  //space indicates two names
         twoNames = true;
         spaceIndex = i; //indicates where the names are separated in the string
         break;
      }
   }
   if(twoNames){ 
      firstName = nameString.substr(0,spaceIndex);
      lastName = nameString.substr(spaceIndex + 1, nameString.length() - 1);
   }
   else {
      firstName = nameString;
      lastName = ""; 
   }
}
