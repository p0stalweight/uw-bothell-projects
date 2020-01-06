/*
@author: John Postlewaite
@file: SearchTree.cpp
date: 1/16/2019

This file contains the implementation for the SearchTree class, which
provides the functionality of a binary search tree and allows for
insertion, removal, and retrieval of Comparable objects to the tree.
Overloaded operators allow comparison of trees for equality, trees can
be erased and reused, and accessor methods are provided to
check if a Comparable object is stored in the tree, print the contents of
the tree, and check the number of descendants of a node containing a particular
Comparable object. 

Most of the public methods utilize private, recursive helper methods. 

The SearchTree class can be used to store and count the occurences of different 
words in a text file, and organize them, assuming Comparable stores Strings. 
It can be used to store other data, depending on what Comparable contains.
*/

#include "SearchTree.h"

// NODE METHODS

/*
Constructs a node to be used by the SearchTree class
initialized as a new entry
pre: Comparable pointer paramater points to a Comparable storing a string
post: a Node struct is created storing a pointer to the comparable object
*/
SearchTree::Node::Node(Comparable* ptr) : item(ptr), count(1), leftChild(nullptr), rightChild(nullptr) {}


// SEARCH TREE METHODS

/*
Constructs a new SearchTree with root set to nullptr
pre: none
post: an empty SearchTree object is created
*/
SearchTree::SearchTree()
{
   root = nullptr;
}


/*
Copy constructor that constructs a new SearchTree identical 
to a given search tree, using private helper method copyHelper
pre: SearchTree being copied is valid and does not contain problematic pointers 
post: a new SearchTree identical to the other SearchTree is constructed
*/
SearchTree::SearchTree(const SearchTree& other)
{
   root = copyHelper(other.root);
}


/*
Constructs a new SearchTree identical
to a given search tree
pre: none
post: returns a Node containing a copy of the Tree contained 
      in the other Node
*/
SearchTree::Node* SearchTree::copyHelper(Node* other)
{
   if (other == nullptr) {
      return nullptr;
   }
   else {
      Comparable* comparableCopy = new Comparable;
      *comparableCopy = *(other->item);
      Node* newRoot = new Node(comparableCopy);
       

      newRoot->count = other->count;
      newRoot->leftChild = copyHelper(other->leftChild);
      newRoot->rightChild = copyHelper(other->rightChild);
      return newRoot;
   }
}


/*
Destructor for SearchTree that calls a helper method to
deallocated nodes and the Comparables that are pointed to, 
along with nulling out pointers 
pre: none
post: all Nodes and Comparables stored via pointer in Nodes
      have been deleted and pointers nulled out
*/
SearchTree::~SearchTree()
{

if(root != nullptr){
   destroyTreeHelper(root);
   root = nullptr;
   }
}


/*
Recursive helper method that deallocates Nodes
and nulls out pointers to destroy the SearchTree
pre: SearchTree destructor has been called
post: all Nodes and Comparables stored via pointer in Nodes
      have been deleted and pointers nulled out
*/
void SearchTree::destroyTreeHelper(Node*& curNode)
{

   if (curNode != nullptr)
   {

      //Postorder traversal of tree
      destroyTreeHelper(curNode->leftChild);
      destroyTreeHelper(curNode->rightChild);

      delete curNode->item;
      curNode->item = nullptr;
      delete curNode;
      curNode = nullptr;
   }
}


/*
Removes the contents of the tree, deallocating all nodes
and restoring it to a blank tree
pre: valid SearchTree
post: SearchTree is empty and all Nodes and Comparables deallocated
*/
void SearchTree::makeEmpty()
{
   destroyTreeHelper(root);
   root = nullptr;
}




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
SearchTree SearchTree::operator=(const SearchTree & other)
{

   if(*this != other){
   destroyTreeHelper(root);
   root = nullptr;
   root = copyHelper(other.root);
   }

   return *this; 
}


/*
Checks if two trees are identical
using the helper method checkEqual
pre: both the tree calling the function and the other tree are valid SearchTrees
post: returns true if both trees are identical, false otherwise
*/
bool SearchTree::operator == (const SearchTree &right)
{
   return checkEqual(root, right.root);
}


/*
Checks if two trees are not identical using the
helper method checkEqual
pre:both the tree calling the function and the other tree are valid SearchTrees
post: returns false if both trees are identical, false otherwise
*/
bool SearchTree::operator!=(const SearchTree &right)
{
   return !(checkEqual(root,right.root)); 
}


/*
Checks if two trees are identical by verifying
each of the member variables in each Node are the same, as 
well as the structure of the tree being identical 
pre: Two SearchTree root pointers are supplied as the parameters
post: returns true if both trees are identical, false otherwise
*/
bool SearchTree::checkEqual(Node* firstRoot, Node* otherRoot) const
{
   //base case: if both roots are nullptrs, returns true
   if (firstRoot == nullptr && otherRoot == nullptr) {
      return true;
   }

   //if both nodes are populated, compare each member field of the 
   //Node, and compare each of the descendant nodes
   else if (firstRoot != nullptr && otherRoot != nullptr)
   {
      return((*(firstRoot->item) == *(otherRoot->item)) && firstRoot->count == otherRoot->count  
      && (checkEqual(firstRoot->leftChild, otherRoot->leftChild)) 
      && (checkEqual(firstRoot->rightChild, otherRoot->rightChild)));
   }

   //if one node is populated and one is not, the trees are not identical
   else {
      return false;
   }
}



/*
Uses a recursive helper function to add an instance Comparable pointer
to the tree
pre: Comparable pointer has a string stored in the Comparable object
post: the pointer will be added to the tree in a new Node, returning true
      unless it already is contained in the tree, in 
      which case the count will be incremented and the 
      function returns false
*/
bool SearchTree::insert(Comparable * ptr)
{
   return insertHelper(root, ptr);
}


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
bool SearchTree::insertHelper(Node*& newRoot, Comparable* ptr)
{
   //if the Comparable is not found create a new Node
   if (newRoot == nullptr) {

      newRoot = new Node(ptr);
      delete ptr; 
      return true;
   }

   //if it is found, increment the count of the Node containing it
   else if (*ptr == *(newRoot->item)) {
      newRoot->count++;
      return false;
   }

   //search left subtree if Comparable value is smaller than current Node
   else if (*ptr < *(newRoot->item)) {
      return insertHelper(newRoot->leftChild, ptr);
   }

   //search right subtree if Comparable value is greater than current Node
   else
   {
      return insertHelper(newRoot->rightChild, ptr);
   }
}

/*
Removes an instance of a Comparable from the tree, decrementing the 
count of the Node containing it, or deleting the Node if the count 
member variable is reduced to 0, using a recursive helper method
pre: Comparable is populated with a string
post: Node containing Comparable count is decremented returning true
      or the Node is deleted and the tree is adjusted returning true
      otherwise returns false if the Comparable is not found
*/
bool SearchTree::remove(const Comparable & target)
{
   return removeHelper(root, target);
}

/*


/*
Helper function that removes an instance of a Comparable from 
the tree, decrementing the count of the Node containing it
or deleting the Node if the count member variable is reduced to 0,
pre: Comparable is populated with a string
post: Node containing Comparable count is decremented returning true
      or the Node is deleted and the tree is adjusted returning true
      otherwise returns false if the Comparable is not found
*/
bool SearchTree::removeHelper(Node*& curNode, Comparable target)
{
   //Comparable is not found in the tree 
   if (curNode == nullptr) {
      return false;
   }

   //search left subtree
   else if (target <  *(curNode->item))
   {
      return removeHelper(curNode->leftChild, target);
   }

   //search right subtree
   else if (target >  *(curNode->item))
   {
      return removeHelper(curNode->rightChild, target);
   }

   //Comparable is found
   else 
   {
      curNode->count--;

      //if Node count reaches 0 remove the Node 
      //while maintaining the structure of the tree
      if (curNode->count <= 0) {
         
         //if no children, simply delete node
         if (curNode->leftChild == nullptr && curNode->rightChild == nullptr)
         {
            delete curNode->item;
            delete curNode;
            curNode = nullptr;
         }
         
         //if only right child, replace the Node with the right child 
         else if (curNode->leftChild == nullptr)
         {
            Node* temp = curNode;
            curNode = curNode->rightChild;
            delete temp->item;
            delete temp;
            temp = nullptr;
         }

         //if only left child, replace the Node with the left child;
         else if (curNode->rightChild == nullptr)
         {

            Node* temp = curNode;
            curNode = curNode->leftChild;
            delete temp->item;
            delete temp;
            temp = nullptr;
         }

         //both children of the node are populated,
         //find the smallest node in the right subtree
         //copy it into the current node and then delete
         //the copied node
         else
         {

            Node* temp = findMin(curNode->rightChild);
            *(curNode->item) = *(temp->item);
            curNode->count = temp->count;
            removeHelper(curNode->rightChild, *(temp->item));

         }

      }
      //after completing removal
      return true; 
   }
}


/*
Recursive helper function that finds the minimum 
tree in the left subtree of the current Node, by
traversing down the left subtrees
pre: None
post: returns the Node with the lowest Comparable value  
      in the subtree
*/
SearchTree::Node* SearchTree::findMin(Node *& curNode)
{
   if (curNode->leftChild == nullptr) {
      return curNode;
   }
   else {
      return findMin(curNode->leftChild);
   }
}


/*
Finds a Comparable in the SearchTree
and returns a const pointer to it,
using a recursive helper method
pre: Comparable target contains a string 
post: returns a const pointer to the Comparable
      found in the tree or returns a null pointer
      if the Comparable is not contained in the tree
*/
const Comparable * SearchTree::retrieve(const Comparable& target) const
{
  return retrieveHelper(root, target);
}

/*
Finds a Comparable in the SearchTree
and returns a const pointer to it
pre: Comparable target contains a string
post: returns a const pointer to the Comparable
      found in the tree or returns a null pointer
      if the Comparable is not contained in the tree
*/
const Comparable* SearchTree::retrieveHelper(Node * root, Comparable target) const
{
   //target is not in tree
   if (root == nullptr) {
      return nullptr;
   }

   //target is found
   else if (target == *(root->item)) {
      return root->item;
   }

   //target is smaller than current Comparable
   else if (target < *(root->item)) {
      return retrieveHelper(root->leftChild, target);
   }

   //target is larger than current Comparable
   else
   {
      return retrieveHelper(root->rightChild, target);
   }


}

/*
Determines the number of descendants
of a Node containing a Comparable using
a recursive helper method
pre: Comparable contains a string
post: returns int representing number of descendants
      returns -1 if Comparable is not found
*/
int SearchTree::descendants(const Comparable & target) const
{
   return descendantHelper(root, target, false);
}


/*
Determines the number of descendants
of a Node containing a Comparable 
pre: Comparable contains a string
post: returns int representing number of descendants
      returns -1 if Comparable is not found
*/
int SearchTree::descendantHelper(Node* curNode , Comparable target, bool targetFound) const
{
   //traverses the tree until target is found
   if(targetFound == false)
   {
 
      //target is not in the tree
      if(curNode == nullptr){
         return -1; 
      }

      //target is found, begin counting descendants
      else if(target == *(curNode->item))
      {
         return descendantHelper(curNode->leftChild, target, true) + descendantHelper(curNode->rightChild, target, true);
      }

      //traverse left subtree to find target
      else if(target < *(curNode->item))
      {
        return descendantHelper(curNode->leftChild, target, false);
      }

      //traverse right subtree to find target
      else 
      {
        return descendantHelper(curNode->rightChild, target, false);
      }
     
   }

   // targetFound == true, count descendants
   else{
 
      if(curNode == nullptr){
         return 0;
      }
      
      //counts 1 for each descendant along with its subtrees
      else{
         return 1 + descendantHelper(curNode->leftChild, target, true) + descendantHelper(curNode->rightChild, target, true); 
      }
   }

}


/*
Outputs the contents of the tree
using the recursive helper method printHelper
pre: SearchTree is valid and has no problematic pointers
post: outputs strings contained by Comparables
   along with their counts to the console
*/
ostream & operator<<(ostream & output, SearchTree &t)
{

   t.printHelper(t.root);
   return output;
}


/*
Recursive method to print the contents 
of the tree along with the count of each
comparable, prints inorder
pre: none
post: outputs strings contained by Comparables 
      along with their counts to the console
*/
void SearchTree::printHelper(Node* curNode) const
{

   if (curNode == nullptr)
   {
      return;
   }

   printHelper(curNode->leftChild);
   cout << *(curNode->item) << " " << curNode->count << endl;
   printHelper(curNode->rightChild);

}
