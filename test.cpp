#include "h/xor_list.h"
#include <iostream>

int main() {
    for (unsigned int i=0; i<1000; ++i) {
        xor_list<int> list;

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
    }

    return 0;
}

