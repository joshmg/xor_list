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
    cout << "Testing get (even length; length = " << list.length() << "; operator[]):" << endl;
    for (unsigned int i=0; i<100; ++i) {
        const unsigned int z = list[i];
        cout << z << " ";
    }
    cout << endl << endl;

    list.get(50) = 999;

    list.push_back(100);
    cout << "Testing get (odd length; length = " << list.length() << "; get()):" << endl;
    for (unsigned int i=0; i<=100; ++i) {
        cout << list.get(i) << " ";
    }
    cout << endl << endl;



    // push_front Test:
    for (unsigned int i=1; i<100; ++i) {
        list.push_front(-i);
    }
    cout << "Testing get (even length; length = " << list.length() << "; get()):" << endl;
    for (unsigned int i=0; i<list.length(); ++i) {
        cout << list.get(i) << " ";
    }
    cout << endl << endl;

    list.push_front(-100);
    cout << "Testing get (odd length; length = " << list.length() << "; operator[]):" << endl;
    for (unsigned int i=0; i<list.length(); ++i) {
        cout << list[i] << " ";
    }
    cout << endl << endl;

    cout << "Testing front():" << endl;
    cout << list.front() << endl;
    list.front() = -999;
    cout << list.front() << endl;
    cout << endl << endl;
    cout << "Testing back():" << endl;
    cout << list.back() << endl;
    list.back() = 999;
    cout << list.back() << endl;
    cout << endl << endl;


    cout << "Testing Const ++Iterator:" << endl;
    xor_list<int>::const_iterator const_it = list.cbegin();
    while (const_it != list.cend()) {
        cout << *const_it << " ";
        ++const_it;
    }
    cout << endl << endl;

    cout << "Testing Const Iterator++:" << endl;
    const_it = list.cbegin();
    while (const_it != list.cend()) {
        cout << *const_it << " ";
        const_it++;
    }
    cout << endl << endl;

    cout << "Testing Const Iterator has_next():" << endl;
    if (list.length() > 0) {
        const_it = list.cbegin();
        do {
            cout << *const_it << " ";
        } while ((const_it++).has_next());
    }
    cout << endl << endl;

    cout << "Testing Iterator-- (has_prev()):" << endl;
    xor_list<int>::iterator it = list.end();
    if (list.length() > 0) {
        while ((it--).has_prev()) {
            cout << *it << " ";
            xor_list<int>::iterator tmp_it = it;
            --tmp_it;
        };
    }
    cout << endl << endl;

    cout << "Testing Const Iterator-- (has_prev()):" << endl;
    const_it = list.cend();
    if (list.length() > 0) {
        while ((const_it--).has_prev()) {
            cout << *const_it << " ";
            xor_list<int>::const_iterator tmp_it = const_it;
            --tmp_it;
        };
    }
    cout << endl << endl;

    cout << "Testing Iterator (it==end compare) and dereferenced assigment:" << endl;
    it  = list.begin();
    while (it != list.end()) {
        xor_list<int>::iterator tmp_it = it++;
        (*tmp_it) = 0;
        cout << *tmp_it << " ";
        ++tmp_it; // Just to be sure the ++operator is compiled.
    }
    cout << endl << endl;

    cout << "Testing Const Iterator (dereferenced assignment continued...):" << endl;
    const_it = list.cbegin();
    while (const_it != list.cend()) {
        cout << *const_it << " ";
        const_it++;
    }
    cout << endl << endl;

    cout << "Re-Assigning Values... (Length: " << list.length() << ":" << endl;
    unsigned int i = 0;
    it = list.begin();
    while (it != list.end()) {
        *it = i++;
        cout << ".";
        ++it;
    }
    cout << endl << endl;

    cout << "Testing Iterator Const Cast:" << endl;
    const_it = list.begin(); // iterator cast to const_iterator
    while (const_it != list.end()) {
        cout << *const_it << " ";
        const_it++;
    }
    cout << endl << endl;

    cout << "Testing Flip:" << endl;
    list.flip();
    const_it = list.begin();
    while (const_it != list.end()) {
        cout << *const_it << " ";
        const_it++;
    }
    cout << endl << endl;

    cout << "Testing Split:" << endl;
    it = list.begin();
    for (unsigned int i=0; i<list.length()/2; ++i) {
        ++it;
    }
    xor_list<int>* t = list.split(it);

    cout << "Original List: " << list.length() << endl;
    const_it = list.begin();
    while (const_it != list.end()) {
        cout << *const_it << " ";
        const_it++;
    }
    cout << endl << endl;

    cout << "Original List (Flipped): " << list.length() << endl;
    list.flip();
    const_it = list.begin();
    while (const_it != list.end()) {
        cout << *const_it << " ";
        const_it++;
    }
    cout << endl << endl;

    cout << "New List: " << t->length() << endl;
    const_it = t->begin();
    while (const_it != t->end()) {
        cout << *const_it << " ";
        const_it++;
    }
    cout << endl << endl;

    cout << "New List (Flipped): " << t->length() << endl;
    t->flip();
    const_it = t->begin();
    while (const_it != t->end()) {
        cout << *const_it << " ";
        const_it++;
    }
    cout << endl << endl;

    cout << "Testing join(): " << endl;
    list.flip();
    t->flip();
    list.join(t);
    const_it = list.begin();
    while (const_it != list.end()) {
        cout << *const_it << " ";
        ++const_it;
    }
    cout << endl << endl;

    delete t;
    t = 0;

    return 0;
}

