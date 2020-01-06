/*
@author: John Postlewaite
@file: SearchTree.h
date: 1/16/2019

This file contains the interface for the SearchTree class, which
provides the functionality of a binary search tree and allows for
insertion, removal, and retrieval of Comparable objects to the tree. 
Overloaded operators allow comparison of trees for equality, trees can
be erased and reused, and accessor methods are provided to 
check if a Comparable object is stored in the tree, print the contents of 
the tree, and check the number of descendants of a node containing a particular
Comparable object. The file also contains a Node struct which is utilized by the 
SearchTree class for storage. 

It is assumed that the Comparables pointed to into the node contain string data.

The SearchTree class can be used to store and count the occurences of different words in a text
file, and organize them, assuming Comparable stores Strings. It can be used to 
store other data, depending on what Comparable contains. 

*/


#ifndef SEARCH_TREE_H
#define SEARCH_TREE_H
#include "Comparable.h"

using namespace std;

class SearchTree {

   friend ostream& operator << (ostream&, SearchTree&);

   struct Node {

      /*
      Constructs a node to be used by the SearchTree class
      initialized as a new entry
      pre: Comparable pointer paramater points to a Comparable storing a string
      post: a Node struct is created storing a pointer to the comparable object
      */
      Node(Comparable*);

      Comparable* item; 
      int count; 
      Node* leftChild;
      Node* rightChild;
      };

public:
 
// CONSTRUCTOR, COPY CONSTRUCTOR, DESTRUCTOR

/*
Constructs a new SearchTree with root set to nullptr
pre: none
post: an empty SearchTree object is created
*/
SearchTree();

/*
Copy constructor that constructs a new SearchTree identical
to a given search tree, using private helper method copyHelper
pre: SearchTree being copied is valid and does not contain problematic pointers
post: a new SearchTree identical to the other SearchTree is constructed
*/
SearchTree(const SearchTree&);

/*
Destructor for SearchTree that calls a helper method to
deallocated nodes and the Comparables that are pointed to,
along with nulling out pointers
pre: none
post: all Nodes and Comparables stored via pointer in Nodes
have been deleted and pointers nulled out
*/
~SearchTree();

// OPERATORS

/*
Checks if two trees are the same object,
and if they are not, removes all the information from the
tree calling the method, and then copies the structure of
the second tree into the first using helper method copyHelper
pre: both the tree calling the function and the other tree are valid SearchTrees
post: if the trees are the same, the original tree is returned
otherwise, the tree calling the function becomes a copy of
second tree, and it is returned
*/
SearchTree operator = (const SearchTree& ); 

/*
Checks if two trees are identical
using the helper method checkEqual
pre: both the tree calling the function and the other tree are valid SearchTrees
post: returns true if both trees are identical, false otherwise
*/
bool operator == (const SearchTree&);

/*
Checks if two trees are not identical using the
helper method checkEqual
pre:both the tree calling the function and the other tree are valid SearchTrees
post: returns false if both trees are identical, false otherwise
*/
bool operator != (const SearchTree&);

// MUTATOR METHODS

/*
Removes the contents of the tree, deallocating all nodes
and restoring it to a blank tree
pre: valid SearchTree
post: SearchTree is empty and all Nodes and Comparables deallocated
*/
void makeEmpty();


/*
Uses a recursive helper function to add an instance Comparable pointer
to the tree
pre: Comparable pointer has a string stored in the Comparable object
post: the pointer will be added to the tree in a new Node, returning true
unless it already is contained in the tree, in
which case the count will be incremented and the
function returns false
*/
bool insert(Comparable *);


/*
Removes an instance of a Comparable from the tree, decrementing the
count of the Node containing it, or deleting the Node if the count
member variable is reduced to 0, using a recursive helper method
pre: Comparable is populated with a string
post: Node containing Comparable count is decremented returning true
or the Node is deleted and the tree is adjusted returning true
otherwise returns false if the Comparable is not found
*/
bool remove(const Comparable&);


// ACCESSOR METHODS

/*
Finds a Comparable in the SearchTree
and returns a const pointer to it,
using a recursive helper method
pre: Comparable target contains a string
post: returns a const pointer to the Comparable
found in the tree or returns a null pointer
if the Comparable is not contained in the tree
*/
const Comparable *retrieve(const Comparable &) const;


/*
Determines the number of descendants
of a Node containing a Comparable using
a recursive helper method
pre: Comparable contains a string
post: returns int representing number of descendants
returns -1 if Comparable is not found
*/
int descendants (const Comparable &) const;




private:

Node* root;

// HELPER METHODS

/*
Constructs a new SearchTree identical
to a given search tree
pre: none
post: returns a Node containing a copy of the Tree contained
in the other Node
*/
   Node* copyHelper(Node*);


/*
Recursive helper method that deallocates Nodes
and nulls out pointers to destroy the SearchTree
pre: SearchTree destructor has been called
post: all Nodes and Comparables stored via pointer in Nodes
have been deleted and pointers nulled out
*/
void destroyTreeHelper(Node*& curNode);


/*
Checks if two trees are identical by verifying
each of the member variables in each Node are the same, as
well as the structure of the tree being identical
pre: Two SearchTree root pointers are supplied as the parameters
post: returns true if both trees are identical, false otherwise
*/
bool checkEqual(Node*, Node*) const;

/*
Adds a new Node to the tree storing a Comparable pointer,
or increments the existing Node that already contains a
pointer to an identical Comparable object, such that
the tree has the property of a binary search tree
pre: Comparable pointer has a string stored in the Comparable object
post: the pointer will be added to the tree in a new Node, returning true
unless it already is contained in the tree, in
which case the count will be incremented and the
function returns false
*/
bool insertHelper(Node*&, Comparable*);

/*
Helper function that removes an instance of a Comparable from
the tree, decrementing the count of the Node containing it
or deleting the Node if the count member variable is reduced to 0,
pre: Comparable is populated with a string
post: Node containing Comparable count is decremented returning true
or the Node is deleted and the tree is adjusted returning true
otherwise returns false if the Comparable is not found
*/
bool removeHelper(Node*&, Comparable);


/*
Recursive helper function that finds the minimum
tree in the left subtree of the current Node, by
traversing down the left subtrees
pre: None
post: returns the Node with the lowest Comparable value
in the subtree
*/
Node* findMin(Node*&);


/*
Finds a Comparable in the SearchTree
and returns a const pointer to it
pre: Comparable target contains a string
post: returns a const pointer to the Comparable
found in the tree or returns a null pointer
if the Comparable is not contained in the tree
*/
const Comparable* retrieveHelper(Node*, Comparable) const;


/*
Determines the number of descendants
of a Node containing a Comparable
pre: Comparable contains a string
post: returns int representing number of descendants
returns -1 if Comparable is not found
*/
int descendantHelper(Node*, Comparable, bool) const;


/*
Outputs the contents of the tree
using the recursive helper method printHelper
pre: SearchTree is valid and has no problematic pointers
post: outputs strings contained by Comparables
along with their counts to the console
*/
void printHelper(Node*) const;


};

// OSTREAM OPERATOR

/*
Recursive method to print the contents
of the tree along with the count of each
comparable, prints inorder
pre: none
post: outputs strings contained by Comparables
along with their counts to the console
*/
ostream& operator <<(ostream&, SearchTree&);


#endif