#include "h/xor_list.h"
#include <iostream>

using namespace std;

int main() {
    xor_list<int> list;

    cout << "Testing Push, Pop/Shift, Print: " << endl;
    list.push_back(120);
    list.push_back(121);
    list.push_back(122);
    list.push_back(123);
    list.push_back(124);
    list.push_back(125);

    list.print();

    list.pop();
    list.print();
    list.pop();
    list.print();
    list.pop();
    list.print();
    list.pop();
    list.print();
    list.pop();
    list.print();
    list.pop();
    list.print();

    list.push_back(120);
    list.push_back(121);
    list.push_back(122);
    list.push_back(123);
    list.push_back(124);
    list.push_back(125);

    list.print();

    list.shift();
    list.print();
    list.shift();
    list.print();
    list.shift();
    list.print();
    list.shift();
    list.print();
    list.shift();
    list.print();
    list.shift();
    list.print();



    // Get Test:
    for (unsigned int i=0; i<100; ++i) {
        list.push_back(i);
    }
    cout << "Testing get (even length; length = " << list.length() << "):" << endl;
    for (unsigned int i=0; i<100; ++i) {
        cout << list.get(i) << " ";
    }
    cout << endl << endl;

    list.push_back(100);
    cout << "Testing get (odd length; length = " << list.length() << "):" << endl;
    for (unsigned int i=0; i<=100; ++i) {
        cout << list.get(i) << " ";
    }
    cout << endl << endl;



    // push_front Test:
    for (unsigned int i=1; i<100; ++i) {
        list.push_front(-i);
    }
    cout << "Testing get (even length; length = " << list.length() << "):" << endl;
    for (unsigned int i=0; i<list.length(); ++i) {
        cout << list.get(i) << " ";
    }
    cout << endl << endl;

    list.push_front(-101);
    cout << "Testing get (odd length; length = " << list.length() << "):" << endl;
    for (unsigned int i=0; i<list.length(); ++i) {
        cout << list.get(i) << " ";
    }
    cout << endl << endl;



    cout << "Testing Const Iterator:" << endl;
    xor_list<int>::const_iterator it = list.begin();
    while (it != list.end()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    return 0;
}

