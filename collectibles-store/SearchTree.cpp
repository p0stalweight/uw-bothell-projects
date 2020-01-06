/*
@author: John Postlewaite
@file: SearchTree.cpp
date: 3/15/2019

File description: This file contains the SearchTree class which provides
a binary search tree that can store Comparable objects.
*/
#include "SearchTree.h"
#include <iostream>

// NODE METHODS

SearchTree::Node::Node(Comparable* ptr, int amount = 1) : item(ptr), count(amount), leftChild(nullptr), rightChild(nullptr) {}


//SEARCH TREE METHODS

SearchTree::SearchTree()
{
   root = nullptr;
}

SearchTree::SearchTree(const SearchTree &other)
{
   root = copyHelper(other.root);
}

SearchTree::~SearchTree()
{
   destroyTreeHelper(root);
   root = nullptr;
}

void SearchTree::destroyTreeHelper(Node * curNode)
{

   if (curNode != nullptr)
   {
      destroyTreeHelper(curNode->leftChild);
      destroyTreeHelper(curNode->rightChild);
      //delete root->item
      delete curNode;
      curNode = nullptr;
   }
}


bool SearchTree::operator==(const SearchTree &right)
{
   return checkEqual(root, right.root);
}

bool SearchTree::operator!=(const SearchTree &right)
{
   return !(checkEqual(root, right.root));
}

// ******MUTATORS******

bool SearchTree::insert(Comparable * ptr, int quant)
{
   if(quant == 0){
      return insertHelper(root, ptr, 1);
   } else{
      return insertHelper(root, ptr, quant);
   }
}

bool SearchTree::remove(Comparable * target)
{
   return removeHelper(root, target); //return true if target is found, false otherwise
}

void SearchTree::makeEmpty()
{
   destroyTreeHelper(root);
}
// ***** ACCESSORS *****
const Comparable * SearchTree::retrieve(const Comparable& target) const
{
   return retrieveHelper(root, target);
}

int SearchTree::descendants(const Comparable & target) const
{
   return descendantHelper(root, target, false);
}

SearchTree::Node* SearchTree::findMin(Node *& curNode)
{
   if (curNode->leftChild == nullptr) {
      return curNode;
   }
   else {
      return findMin(curNode->leftChild);
   }
}

bool SearchTree::insertHelper(Node*& root, Comparable* ptr, int quant = 1)
{
 
   if (root == nullptr) {
      root = new Node(ptr, quant);

      return true;
   }
   else if (*ptr == *(root->item)) {
      root->count++;
      return false;
   }
   else if (*ptr < *(root->item)) {
      return insertHelper(root->leftChild, ptr, quant);
   }
   else
   {
      return insertHelper(root->rightChild, ptr, quant);
   }
}

//finds a comparable, and then counts the number of descendants
int SearchTree::descendantHelper(Node* curNode, Comparable target, bool targetFound) const
{
   //find the target, if its found set to true
   if (targetFound == false)
   {

      if (curNode == nullptr) {
         return -1;
      }
      else if (target == *(curNode->item))
      {
         return descendantHelper(curNode->leftChild, target, true) + descendantHelper(curNode->rightChild, target, true);
      }
      else if (target < *(curNode->item))
      {
         return descendantHelper(curNode->leftChild, target, false);
      }
      else 
      {
         return descendantHelper(curNode->rightChild, target, false);
      }


   }

   // target has been found, count descendants
   else {

      if (curNode == nullptr) {
         return 0;
      }
      else {
         return 1 + descendantHelper(curNode->leftChild, target, true) + descendantHelper(curNode->rightChild, target, true);
      }
   }

}

void SearchTree::printHelper(Node* curNode) const
{

   if (curNode == nullptr)
   {
      return;
   }

   printHelper(curNode->leftChild);
   cout << *(curNode->item) << " quantity: " << curNode->count << endl;
   printHelper(curNode->rightChild);

}


//searches for a certain comparable, returns reference if found, otherwise return nullptr
const Comparable* SearchTree::retrieveHelper(Node * root, Comparable target) const
{
   if (root == nullptr) {
      return nullptr;
   }
   else if (target == *(root->item)) {
      return root->item;
   }
   else if (target < *(root->item)) {
      return retrieveHelper(root->leftChild, target);
   }
   else  { //(target > *(root->item))
      return retrieveHelper(root->rightChild, target);
   }

}


bool SearchTree::removeHelper(Node*& curNode, Comparable* target)
{
  
   //return true if target is found, false if not found  
   if (curNode == nullptr) {
      return false;
     
   }
   else if (*target < *(curNode->item))
   {
     
      return removeHelper(curNode->leftChild, target);
   }
   else if (*target >  *(curNode->item))
   {
      
      return removeHelper(curNode->rightChild, target);
   }
   else 
   {
  
      curNode->count--;
      
      if (curNode->count <= 0) {
         if (curNode->leftChild == nullptr && curNode->rightChild == nullptr)
         {                     
            delete curNode;
            curNode = nullptr;
         }
         else if (curNode->leftChild == nullptr)
         {
            Node* temp = curNode;
            curNode = curNode->rightChild;
            delete temp->item;
            delete temp;
            temp = nullptr;
         }
         else if (curNode->rightChild == nullptr)
         {
            Node* temp = curNode;
            curNode = curNode->leftChild;
            delete temp->item;
            delete temp;
            temp = nullptr;
         }
         else //neither left or right is nullptr
         {
            Node* temp = findMin(curNode->rightChild);
            *(curNode->item) = *(temp->item); 

            curNode->count = temp->count;
            removeHelper(curNode->rightChild, temp->item); 
         }
        
      }
      return true;
   }


}

SearchTree::Node* SearchTree::copyHelper(Node* other)
{
   if (other == nullptr) {
      return nullptr;
   }
   else {
      Node* root = new Node(other->item);
      root->count = other->count;
      root->leftChild = copyHelper(other->leftChild);
      root->rightChild = copyHelper(other->rightChild);
      return root;
   }
}

bool SearchTree::checkEqual(Node* firstRoot, Node* otherRoot)
{
   if (firstRoot == nullptr && otherRoot == nullptr) {
      return true;
   }
   else if (firstRoot != nullptr && otherRoot != nullptr)
   {
      return((*(firstRoot->item) == *(otherRoot->item)) && firstRoot->count == otherRoot->count 
            && (checkEqual(firstRoot->leftChild, otherRoot->leftChild))
            && (checkEqual(firstRoot->leftChild, otherRoot->leftChild)));
   }
   else {
      return false;
   }
}


ostream & operator<<(ostream & output, SearchTree &t)
{
   t.printHelper(t.root);
   return output;
}

