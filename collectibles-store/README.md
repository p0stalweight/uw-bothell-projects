A project designed to simulate a store inventory, using object oriented programming, inheritance, hash tables, and binary trees.
The file takes input as follows:

// Description of Input //

All coins have type, year, and grade (an integer). All comic books have a title, publisher, year, and grade (a string). All sports cards have a player, a manufacturer, a year, and a grade (a string). The items in the inventory are sorted as follows:

Coins are sorted first by type, then by year, then by grade
Comics are sorted first by publisher, then by title, then by year, then by grade
Sports cards are sorted by player, then by year, then by manufacturer, then by grade
You can assume that each item is uniquely identified by the complete set of sorting criteria. To facilitate processing of the files, Coins are marked ‘M’, comics are marked ‘C’, and sports cards are marked ‘S’.

The data file for initialization of the inventory lists each item on a separate line with a character denoting the type of item, number in inventory, year, grade, type/title/player, publisher/manufacture (if necessary). Fields are separated by commas as follows:

  M, 3, 2001, 65, Lincoln Cent
  M, 10, 1913, 70, Liberty Nickel
  C, 1, 1938, Mint, Superman, DC 
  C, 2, 2010, Excellent, X-Men, Marvel
  Z, 4, 1986, Raging, Metallica, Master of Puppets
  S, 9, 1989, Near Mint, Ken Griffey Jr., Upper Deck
  S, 1, 1952, Very Good, Mickey Mantle, Topps
You may assume correct formatting, but the data could be invalid. In this data, the ‘Z’ code is an invalid entry.

Customer information is stored in a similar file. Customers have a 3-digit ID number that uniquely identifies them:

  001, Serena Williams
  456, Keyser Soze
  999, Pele
You can assume that this data is formatted correctly, but not that there will be exactly two names. (Go ahead and sort by first name, if that is first in the file.)

Your code will be tested using a third file containing the commands (S for Sell, B for Buy, D for Display, C for Customer, and H for History). Except for the Display and History commands, the second field is customer ID. For buy and sell commands, the third field is the item type and the remaining fields are the item.

  S, 001, S, 1989, Near Mint, Ken Griffey Jr., Upper Deck
  B, 456, M, 1913, 70, Liberty Nickel
  C, 999
  D
  X, 999, Z, 1986, Raging, Metallica, Master of Puppets
  S, 000, Q, 2112, Gnarly, Windows, Microsoft
  H
Once again, the data will be formatted correctly, but may include errors. You should check to make sure that the number of each item in the inventory doesn’t go below zero. Do not print output for successful buy or sell commands, but do print error messages for incorrect data. Output for your Display, Customer, and History commands should be neatly formatted with one line per item/transaction. The inventory should output all coins, then all comics, then all sports cards.

// 

The implementation has a number of items that can be contained in the inventory, and the action to be take on an item is quickly looked up using a hash table. Each type of item is stored in a binary search tree based on the description above. 
 
