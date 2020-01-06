/*
Author: Olson (borrowing from a previous edition of Carrano/Henry), modified by John Postlewaite
Heap class:    Implements a priority queue with the following methods:       
insert, deleteMin, findMin, heapify  
The heap is stored in a vector 
Assumptions:     Can only store data for which operator< exists     
(hence the Comparable type variable)
*/

#include <vector>

using namespace std;

template <typename Comparable>
class Heap {
public:

/*
Default Constructor, has a null dummy value in first 
position of items array and size 0
pre: none
post: Heap object is constructed
*/
Heap(){
   numElements = 0;
}

/*
Copy constructor that deep copies
the pointers stored in the items array
pre: none
post: copy of Heap is created
*/
Heap(const Heap& other){
   numElements = 0;
   copy(other);      
}
   
/*
Assignment operator that uses the clear method
to remove the contents of the heap, and then the
copy method to copy the contents of another Heap
pre: none
post: old data is removed and deallocater, new data
      is copied into Heap
*/
Heap Heap::operator = (const Heap & other){
   if (*this != other){
      numElements = 0;
      clear(); 
      copy(other); 
   }
   return *this; 
}


/*
Destructor, iterates through non-dummy nodes   
pre: none
post: any memory in the Heap is deallocated,
      and numElements is set to 0 
*/
~Heap(){
   
   clear(); 
}

  

/*
insert- adds a single item to the heap
Preconditions: the intial heap has sufficient memory allocated
               and satisfies the heap order property
Postconditions: inserts the item into the queue, such that a new heap 
                is created containing the union of the elements
*/
void Heap::insert(Comparable *c) {
   if ( c == NULL) return;

      // add item in position 0 (dummy position) to prevent percolating
      // up from the root
      if (items.size() < 1) items.push_back(c);
      else items[0] = c; 

      // ensure we have enough space
      numElements++; 
      while((int) items.size() <= numElements)
         items.push_back(nullptr);

      // percolate up
      int position = numElements; 
      while (*c < *items[position / 2]) {
         items[position] = items[position / 2];
         position = position / 2;
      }
      items[position] = c; 
   }

/*
findMin - returns a const pointer to the minimum value in the heap
Preconditions: items[0] exists if numElements is larger than zero
Postconditions: Returns nullptr if the heap is empty, otherwise returns
                the item at the root of the heap (presumably the minimum priority).
*/
   const Comparable * findMin() const 
   { 
      if (numElements <= 0) return nullptr;
      else return items[1]; 
   }

/*
deleteMin - delete the minimum and return a pointer to it
Preconditions: items[0] exists if numElements is larger than zero
Postconditions: Returns nullptr if the heap is empty, otherwise returns    
                the item at the root of the heap (presumably the minimum priority)
                That element is deleted from the heap and the heap order property is
                restored.
*/
Comparable * Heap::deleteMin() {
   if (numElements == 0) return nullptr;

   // Give memory back to userComparable 
   Comparable *toReturn = items[1];
   items[1] = items[numElements];
   numElements--;
   percolateDown(1);

   return toReturn;
   }



/*
heapify - modifies any set of data into a heap
NOTE: not used in this assignment
Preconditions: items has been allocated space for numElements pointers
Postconditions: The items stored form a heapvoid 
*/
void Heap::heapify() {
   for (int i = numElements / 2; i > 0; i--)
      percolateDown(i);
   }

/* 
size
Preconditions: none
Postconditions: returns the size of the heapint 
*/
int Heap::size() {
      return numElements;
   }

/*
isEmpty
Preconditions: none
Postconditions: returns whether the heap is empty (zero elements)
*/
   bool Heap::isEmpty() {
      return numElements == 0;
   }

private:

/*
copies each of the elements in another Heap
into current Heap, with a deep copy, ignores 
dummy Node
pre: none
post:
*/
void copy(const Heap& other) {


   for (int i = 1; i < other.numElements; i++) {
      cout << i << endl;
      Comparable *c = new Comparable(*(other.items[i]));
      insert(c);
   }
}

/*
clears data from Heap
pre: none
post: all objects in Heap are deallocated
      and numElements is set to 0 
*/

void Heap::clear() {

   for (int i = 1; i < numElements; i++) {
      Comparable *c = items[i];

      if (c != NULL) {

         delete c;
      }
   }

   items[0] = nullptr;
   numElements = 0;
}


/*
percolateDown - used to restore the heap order property after deleteMin
Preconditions: Both subtrees of the root are heaps
Postconditions: Restores the heap order property to shifting the root
                down until it reaches an appropriate node
*/
   void Heap::percolateDown(int position) {
      int child = position * 2;
      if (child > numElements) 
         return;
      if (child != numElements && *items[child] > *items[child + 1]) child++;
      if (*items[child] < *items[position]) 
      {
         swap(items[child], items[position]);
         percolateDown(child);
      }
   }
  
   // Number of elements in the heapvector  
   int numElements; 
 
   //first element is a dummy element        
   vector <Comparable *> items{nullptr}; 
  
};