#include "Comparable.h"
#include "SearchTree.h"
#include <iostream>

using namespace std;

int main(){
   SearchTree t; 

   Comparable* c = new Comparable;
   cin >> *c; 
   t.insert(c);

   Comparable* d = new Comparable;
   cin >> *d;
   t.insert(d);

   Comparable* e = new Comparable;
   cin >> *e;
   t.insert(e);


   Comparable* f = new Comparable;
   cin >> *f;
   t.insert(f);

   Comparable* g = new Comparable;
   cin >> *g;
   t.insert(g);

   Comparable* h = new Comparable;
   cin >> *h;
   t.insert(h);

   Comparable* p = new Comparable;
   cin>> *p;
   
   cout << "retrieve result: " << t.retrieve(*p) << endl;
 
   cout << endl << endl;
   cout << t;
return 0; 
}
