#include "h/xor_list.h"
#include <iostream>

using namespace std;

int main() {
    xor_list<int> list;

    cout << "Testing Push, Pop/Shift, Print: " << endl;
    list.push(120);
    list.push(121);
    list.push(122);
    list.push(123);
    list.push(124);
    list.push(125);

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

    list.push(120);
    list.push(121);
    list.push(122);
    list.push(123);
    list.push(124);
    list.push(125);

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
        list.push(i);
    }
    cout << "Testing get (even length; length = " << list.length() << "):" << endl;
    for (unsigned int i=0; i<100; ++i) {
        cout << list.get(i) << " ";
    }
    cout << endl << endl;

    list.push(100);
    cout << "Testing get (odd length; length = " << list.length() << "):" << endl;
    for (unsigned int i=0; i<=100; ++i) {
        /*
            if (i == 25) {
                list.get(i) = 0;
            }
        */
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

