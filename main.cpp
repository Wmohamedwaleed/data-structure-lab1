#include <iostream>
using namespace std;
#include "LinkedList.h"

int main() {
     int x=0;
     int y=0;
   LinkedList mylist;
   mylist.add(5);
   mylist.add(2);
   mylist.add(6);
   mylist.add(3);
   mylist.removeNode(3);
   mylist.display();
   mylist.insert_after(3, 5);
   mylist.insert_before(3, 5);
   mylist.display();
    x= mylist.counter();
   cout<<x<<endl;
   y=mylist.getdatabyindex(0);
   cout<<y<<endl;

    return 0;
}
