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

    list.pop_back();
    list.print();
    list.pop_back();
    list.print();
    list.pop_back();
    list.print();
    list.pop_back();
    list.print();
    list.pop_back();
    list.print();
    list.pop_back();
    list.print();

    list.push_back(120);
    list.push_back(121);
    list.push_back(122);
    list.push_back(123);
    list.push_back(124);
    list.push_back(125);

    list.print();

    list.pop_front();
    list.print();
    list.pop_front();
    list.print();
    list.pop_front();
    list.print();
    list.pop_front();
    list.print();
    list.pop_front();
    list.print();
    list.pop_front();
    list.print();



    // Get Test:
    for (unsigned int i=0; i<100; ++i) {
        list.push_back(i);
    }
    cout << "Testing get (even length; length = " << list.length() << "):" << endl;
    for (unsigned int i=0; i<100; ++i) {
        const unsigned int z = list[i];
        cout << z << " ";
    }
    cout << endl << endl;

    list.get(50) = 999;

    list.push_back(100);
    cout << "Testing get (odd length; length = " << list.length() << "):" << endl;
    for (unsigned int i=0; i<=100; ++i) {
        cout << list[i] << " ";
    }
    cout << endl << endl;



    // push_front Test:
    for (unsigned int i=1; i<100; ++i) {
        list.push_front(-i);
    }
    cout << "Testing get (even length; length = " << list.length() << "):" << endl;
    for (unsigned int i=0; i<list.length(); ++i) {
        cout << list[i] << " ";
    }
    cout << endl << endl;

    list.push_front(-101);
    cout << "Testing get (odd length; length = " << list.length() << "):" << endl;
    for (unsigned int i=0; i<list.length(); ++i) {
        cout << list[i] << " ";
    }
    cout << endl << endl;



    cout << "Testing Const ++Iterator:" << endl;
    xor_list<int>::const_iterator it = list.cbegin();
    while (it != list.cend()) {
        cout << *it << " ";
        ++it;
    }
    cout << endl << endl;

    cout << "Testing Const Iterator++:" << endl;
    it = list.cbegin();
    while (it != list.cend()) {
        cout << *it << " ";
        it++;
    }
    cout << endl << endl;


    cout << "Testing front():" << endl;
    cout << list.front() << endl;
    cout << endl << endl;


    cout << "Testing NonConst Iterator:" << endl;
    xor_list<int>::iterator vit = list.begin();
    while (vit != list.end()) {
        xor_list<int>::iterator tmp_it = vit++;
        (*tmp_it) = 0;
        cout << ".";
        ++tmp_it; // Just to be sure the ++operator is compiled.
    }
    cout << endl << endl;

    cout << "Testing Const Iterator++:" << endl;
    it = list.cbegin();
    while (it != list.cend()) {
        cout << *it << " ";
        it++;
    }
    cout << endl << endl;

    return 0;
}

