/*
@author: John Postlewaite
@file: Huffman.cpp
date: 1/28/2019

Contains the implementation for the Huffman class,
which defines a Node struct that is used to construct Huffman
trees. The main constructor uses an array of 26 integers
representing a set of weights for each letter. It then
constructs a huffman tree by using a heap as a priority
queue, and stores the tree in the root member variable.
This tree is traversed to determine the code for each letter
in the tree, and the codes are stored in the member variable
alphabetCodes. There is a method that takes in a string,
and provides the corresponding code for all alphabetical
characters in the string.

Assumptions: only creates Huffman codes for alphabetical characters
*/
#include "Huffman.h"
#include "Heap.hpp"
#include <iostream>
#include <string>

using namespace std; 

// Node Methods \\

/*
Default node constructor
Preconditions: none
Postconditions: Node is created
*/
Huffman::Node::Node():weight(0), lastLetter(' '), leftChild(nullptr), rightChild(nullptr){}

/*
Constructor that populates frequency and letters
Preconditions: none
Postconditions: Node is created
*/
Huffman::Node::Node(int frequency, char letter): weight(frequency), lastLetter(letter), leftChild(nullptr), rightChild(nullptr){}

/*
Compares two Nodes, based on their weight and the lastLetter
Preconditions: each Node has a populated frequency and letter data member
Postconditions: returns bool indicating if current node is smaller
*/
bool Huffman::Node::operator < (const Node& o)
{
   if(weight < o.weight)
   {
      return true;
   }
   else if (weight > o.weight)
   {
      return false; 
   }
   else{ 

      return lastLetter < o.lastLetter;
     
   }
   
}

/*
Compares two Nodes, based on their weight and the lastLetter
Preconditions: each Node has a populated frequency and letter data member
Postconditions: returns bool indicating if current node is larger
*/
bool Huffman::Node::operator > (const Node& o)
{
   if (weight > o.weight)
   {
      return true;
   }
   else if (weight < o.weight)
   {
      return false;
   }
   else {
      return lastLetter > o.lastLetter;
   }

}

/*
Compares two Nodes, based on their weight and the lastLetter to determine
if they are equal
Preconditions: each Node has a populated frequency and letter data member
Postconditions: returns bool indicating if the Nodes are equal
*/
bool Huffman::Node::operator == (const Node& o)
{
   return weight == o.weight && lastLetter == o.lastLetter; 
}


// Huffman Methods \\

/*
Constructs a Huffman tree based on the array of weights that is input.
Builds a set of nodes corresponding to the weight values, and constructs
the tree using a Heap. Populates the alphabetCodes member with values by
traversing the tree, calling the retrieveCodes method.
Preconditions: array contains 26 integers
Postconditions: root contains Huffman tree and alphabetCodes is populated
*/
Huffman::Huffman(int counts[NUM_CHARS])
{
   Heap<Node> h;

   // generate nodes for each letter and add them to heap
   char currentChar = 'a';
  for(int i = 0; i < NUM_CHARS; i++){
      Node* currentNode = new Node(counts[i], currentChar);
      h.insert(currentNode);
      currentChar++; 
   }
   
   // construct tree until there is only one Node left in Heap
   while(h.size() > 1){

   //pop off first two elements from the heap
   Node* temp = h.deleteMin();
   Node* temp2 = h.deleteMin();

   //determine attributes for subtree
   int sumWeight = temp->weight + temp2->weight; 
   char letter;

   //assign smaller letter to subtree 
   if (temp->lastLetter > temp2->lastLetter){
      letter = temp2->lastLetter; 
   }else{
      letter = temp->lastLetter; 
   }
   
   //create subtree and assign attributes
   Node* newTree = new Node(sumWeight, letter); 

   //attach children to new node
   if (*temp > *temp2){
      newTree->leftChild = temp2; 
      newTree->rightChild = temp; 
   } else{
      newTree->leftChild = temp;
      newTree->rightChild = temp2; 
   }

   h.insert(newTree); 
}

//store tree in Huffman object
root = h.deleteMin(); 


//populate alphaBetCodes, set size of vector
alphabetCodes.resize(NUM_CHARS);  
retrieveCodes(root,""); 

}

/*
Supplies the Huffman codes for a given string, ignores non-alphabetical
characters.
Preconditions: Custom constructor was used to build the Huffman tree
Postconditions: returns a string with Huffman code
*/
string Huffman::getWord(string word)
{
   string result = "";

   for (string::iterator it = word.begin(); it != word.end(); ++it) {
      char currentChar = *it;

      if (isalpha(currentChar)) {
         int charIndex = currentChar - 'a';
         result += alphabetCodes[charIndex];
      }
   }

   return result;
}

/*
Destructor that deallocates memory from the Huffman tree,
using the clear method
Preconditions: none
Postconditions: Nodes in the tree are deallocated
*/
Huffman::~Huffman()
{
   clear(root);
   root = nullptr;
}

/*
Recursive method that deallocates and nulls
each Node in the tree
Preconditions: none
Postconditions: deallocates the tree contained by the Node
the method is called on
*/
void  Huffman::clear(Node* curNode)
{
   if (curNode != nullptr){
      clear(curNode->leftChild);
      clear(curNode->rightChild); 
      
      delete curNode;
      curNode = nullptr; 
   }
}

/*
Traverses through the Huffman Tree storing a string,
and once a leaf node is reached, the string is stored
in alphabetCodes at the corresponding index for the character
Preconditions: tree constructed using custom constructor
Postconditions: returns bool indicating if the Nodes are equal
*/
void Huffman::retrieveCodes(const Node* cur, string code)
{
   
   if(cur == nullptr) return; 

   //if Node is a leaf, set the code for corresponding character
   if(cur->leftChild == nullptr && cur->rightChild == nullptr){
      char letter = cur->lastLetter; 
      int letterIndex = letter - 'a';

      alphabetCodes[letterIndex] = code; 

      return; 
   }

   else{ 

      //traverse left, add '0' to code
      if(cur->leftChild != nullptr){
         string leftCode = code + '0';
         retrieveCodes(cur->leftChild, leftCode);
      }

      //traverse right, add '1' to code
      if(cur->rightChild != nullptr){
         string rightCode = code + '1';
         retrieveCodes(cur->rightChild, rightCode);
      }
      return; 
   }

 }


/*
Outputs the character and encoding for each letter
Preconditions: tree constructed using custom constructor
Postconditions: outputs character, a space and corresponding code
*/
ostream & operator<<(ostream & output, Huffman & h)
{
   char currentChar = 'a'; 
   for (int i = 0; i < NUM_CHARS; i++) {
      cout << currentChar << " " << h.alphabetCodes[i] << endl; 
      currentChar++;
   }
   return output;
}
