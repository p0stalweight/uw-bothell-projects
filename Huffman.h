/*
@author: John Postlewaite
@file: Huffman.h
date: 1/28/2019

Contains the header file for the Huffman class, 
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

#ifndef HUFFMAN_H
#define  HUFFMAN_H 
#include <vector>
#include <string>

using namespace std; 

// characters represented in the tree ('s' added to prevent naming conflict)
const int NUM_CHARS = 26;

class Huffman {

   friend ostream& operator << (ostream&, Huffman&);


   struct Node {
   /*
   Default node constructor
   Preconditions: none
   Postconditions: Node is created
   */
   Node(); 

   /*
   Constructor that populates frequency and letters
   Preconditions: none
   Postconditions: Node is created
   */
   Node(int frequency, char letter);

   int weight; 
   char lastLetter;
   Node* leftChild; 
   Node* rightChild; 

   /*
   Compares two Nodes, based on their weight and the lastLetter
   Preconditions: each Node has a populated frequency and letter data member
   Postconditions: returns bool indicating if current node is smaller
   */
   bool operator < (const Node&); 

   /*
   Compares two Nodes, based on their weight and the lastLetter
   Preconditions: each Node has a populated frequency and letter data member
   Postconditions: returns bool indicating if current node is larger
   */
   bool operator > (const Node&);

   /*
   Compares two Nodes, based on their weight and the lastLetter to determine 
   if they are equal
   Preconditions: each Node has a populated frequency and letter data member
   Postconditions: returns bool indicating if the Nodes are equal
   */
   bool operator == (const Node&);

   };

public: 

   /*
   Constructs a Huffman tree based on the array of weights that is input.
   Builds a set of nodes corresponding to the weight values, and constructs
   the tree using a Heap. Populates the alphabetCodes member with values by
   traversing the tree, calling the retrieveCodes method. 
   Preconditions: array contains 26 integers
   Postconditions: root contains Huffman tree and alphabetCodes is populated
   */
   Huffman(int[NUM_CHARS]);

   /*
   Supplies the Huffman codes for a given string, ignores non-alphabetical 
   characters. 
   Preconditions: Custom constructor was used to build the Huffman tree
   Postconditions: returns a string with Huffman code 
   */
   string getWord(string);

   /*
   Destructor that deallocates memory from the Huffman tree,
   using the clear method
   Preconditions: none
   Postconditions: Nodes in the tree are deallocated 
   */
   ~Huffman(); 


   private:

   /*
   Recursive method that deallocates and nulls 
   each Node in the tree
   Preconditions: none
   Postconditions: deallocates the tree contained by the Node
                   the method is called on
   */
   void clear(Node*);


   /*
   Traverses through the Huffman Tree storing a string, 
   and once a leaf node is reached, the string is stored
   in alphabetCodes at the corresponding index for the character
   Preconditions: tree constructed using custom constructor
   Postconditions: returns bool indicating if the Nodes are equal
   */
   void retrieveCodes(const Node*, string);

   Node* root; 

   //stores the resulting encodings for each letter
   vector<string> alphabetCodes; 

 };

/*
Outputs the character and encoding for each letter
Preconditions: tree constructed using custom constructor
Postconditions: outputs character, a space and corresponding code
*/
ostream& operator << (ostream&, Huffman&);


#endif
