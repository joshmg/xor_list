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
    cout << "Testing get (even length):" << endl;
    for (unsigned int i=0; i<100; ++i) {
        list.push(i);
    }
    for (unsigned int i=0; i<100; ++i) {
        cout << list.get(i) << " ";
    }
    cout << endl << endl;

    cout << "Testing get (odd length):" << endl;
    list.push(100);
    for (unsigned int i=0; i<=100; ++i) {
        cout << list.get(i) << " ";
    }
    cout << endl << endl;

    return 0;
}

