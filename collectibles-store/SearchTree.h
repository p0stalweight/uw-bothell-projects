/*
@author: John Postlewaite
@file: SearchTree.h
date: 3/15/2019

File description: This file contains the SearchTree class which provides
a binary search tree that can store Comparable objects.
*/
#ifndef SEARCH_TREE_H
#define SEARCH_TREE_H
#include "Comparable.h"
#include "Coin.h"
#include "ComicBook.h"
#include "SportCard.h"

using namespace std;

class SearchTree {

   friend ostream& operator << (ostream&, SearchTree&);

   struct Node {
      Node(Comparable*, int);
      Comparable* item;
      int count;
      Node* leftChild;
      Node* rightChild;
   };

public:
   Node* root;

   // Construtors/Destructor ****

   //default constructor
   SearchTree();

   //copy constructor
   SearchTree(const SearchTree&);

   // destructor (postorder)
   ~SearchTree();
   void destroyTreeHelper(Node* curNode);

   //operator== compares two trees for equivalency
   bool operator==(const SearchTree&);

   //operator!=
   bool operator!=(const SearchTree&);


   // Mutators ****

   //bool insert (Comparable *) returns false if Comparable is found, otherwise increments count
   //Ownership of the memory is transferred to the tree only if the object is not found in the tree 
   //(in which case it must later be deallocated by the tree).
   bool insert(Comparable *, int quant = 0);


   //bool remove(const Comparable&) decrements count, removes node if count goes to 0. Adjust tree if not a leaf node (see removal algo)
   bool remove(Comparable*);

   //void makeEmpty() removes all data from tree but empty tree with that name can be used again 
   void makeEmpty();

   // Accessors ****

   //const Comparable *retrieve(const Comparable &) const : finds a Comparable in the tree using a key stored in the parameter, returns nullptr if not found
   const Comparable *retrieve(const Comparable &) const;

   //int descendants(const Comparable &) const  returns number of descendants of a node. -1 if not found 
   int descendants(const Comparable &) const;

   Node* findMin(Node*&);

private:

   // Helper methods ****

   //insert helper
   bool insertHelper(Node*&, Comparable*, int);

   int descendantHelper(Node*, Comparable, bool) const;

   void printHelper(Node*) const;

   const Comparable* retrieveHelper(Node*, Comparable) const;

   bool removeHelper(Node*&, Comparable*);

   Node* copyHelper(Node*);

   bool checkEqual(Node*, Node*);


};

ostream& operator <<(ostream&, SearchTree&);


#endif