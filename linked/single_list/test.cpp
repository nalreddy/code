#include<iostream>
#include<assert.h>
#include "list.hpp"

using namespace std;

int main()
{
#if 0
    List<int> list;
    //unit test on empty list
    assert(("List must be empty now ", list.isEmpty()));
    cout << " Length of empty list " << list.getLen() << endl;
    cout << "Delete on empty list " << list.pop_Front() << endl;
    cout << "Delete on empty list " << list.pop_Back() << endl;
    list.print();
    list.reverse();
    list.print();

    //test 2
    list.push_Front(1);
    list.print();
    cout << " Length of empty list " << list.getLen() << endl;
    list.reverse();
    list.print();
    list.pop_Front();
    list.print();
    assert(("List must be empty now ", list.isEmpty()));
    // test3
    if (list.search(3))
        cout << " found val " << endl;
    else 
        cout << " not found val " << endl;

 
    list.push_Front(2);
    list.push_Front(3);
    if (list.search(3))
        cout << " found val " << endl;
    list.print();
    cout << " Length of empty list " << list.getLen() << endl;
    list.print();
    list.pop_Back();
    cout << " Length of empty list " << list.getLen() << endl;
    list.print();
    list.pop_Front();
    list.print();
//    assert(("List must be empty now ", list.isEmpty()));
    if (list.isEmpty()) {
        cout << "List is empty " << endl;
    } else {
        cout << " List not empty " << endl;
    }
    for (int i = 0; i < 10; i++) {
       list.push_Front(i);
    }
    list.print();
    list.makeCycle();
    list.print();
    if (list.detectCycle())
        cout << "cycle found " << endl;
    else 
        cout << "Not cycle found " << endl;
    list.removeCycle();

    if (list.detectCycle())
        cout << "cycle found " << endl;
    else 
        cout << "Not cycle found " << endl;

    list.print();


#endif
    List<int> l1;
    List<int> l2;
    List<int> l3;

    l1.push_Front(2);
    l1.push_Front(3);
    l2.push_Front(9);
    l2.push_Front(9);
    l2.push_Front(-3);

    l3.addListLsb(l1, l2);
    l3.print();
}
