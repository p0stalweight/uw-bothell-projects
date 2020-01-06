/*
@author: John Postlewaite
@file: SearchTree.h
date: 3/15/2019

File description: This file contains the driver, which creates a store 
object, intializes the inventory from a file, initializes the customer 
list from a file, and then processes commands for the store from a file 
*/
#include "Store.h"
#include "ActionSelect.h"
#include "Action.h"
#include "Store.h"
#include "Coin.h"
#include "ComicBook.h"
#include "SportCard.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Buy.h"
#include "Sell.h"
#include "CustomerHistory.h"
#include "Customer.h"
#include "Display.h"
#include "StoreHistory.h"

using namespace std;

int main(){

   Store* storePtr = new Store(); 
   ActionSelect action(storePtr); 

   //////////////INVENTORY//////////////
   string line;
   ifstream inventoryfile("hw4inventory.txt");
   if (inventoryfile.is_open())
   {
      string type;
      string stringCount;
      int intCount;
      string details;

      while (!inventoryfile.eof())
      {
         getline(inventoryfile, type, ','); 		//get type of inventory
         inventoryfile.get(); 			//discard space
         getline(inventoryfile, stringCount, ','); 	//get count
         inventoryfile.get();        //discard space
         intCount = stoi(stringCount);
         if (storePtr->buildProduct(type) == nullptr || intCount < 1) {
            cout << "Invalid product data!" << endl;
            getline(inventoryfile, details);
            
         }
         else {
            getline(inventoryfile, details);
            Comparable * newProduct = storePtr->buildProduct(type);
            newProduct->setData(details);
            storePtr->addProduct(newProduct, intCount);
          
         }
      }
      inventoryfile.close();
   }

   //////////////CUSTOMERS//////////////
   ifstream customerfile("hw4customers.txt");
   if (customerfile.is_open())
   {
      while (customerfile.peek() != EOF){
         Customer* customer = new Customer();
         customerfile >>  *customer;
         storePtr->addCustomer(customer);
      }
   }
   customerfile.close();


   //////////////COMMANDS//////////////
   ifstream commandfile("hw4commands.txt");
   string command;
   char charCommand; 
   string detail; 
   if (commandfile.is_open())
   {
      while (commandfile.peek() != EOF) {
         commandfile.get(charCommand); 		//get command type
         command = charCommand; 
         if(commandfile.peek() != ','){ //if no comma, indicates rest of line is empty
            commandfile.get();  //skip to next line
            detail = "";
         }
         else{
            commandfile.get(); //skip comma 
            getline(commandfile, detail);
         }
         //take command choice and rest of the line (may be empty) 
         //to process using ActionSelect
         action.doAction(command, detail); 
      }
    }
   commandfile.close();

   //delete Store
   delete storePtr;
   storePtr = nullptr;  

   system("pause");
 
   return 0; 
};
