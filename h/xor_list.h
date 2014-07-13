#ifndef __XOR_LIST__
#define __XOR_LIST__

#include <new>
#include <iostream>
    
template <typename T>
class xor_list {
    private:
        struct xor_node {
            xor_node* address;
            T value;
            void print() const;
        };

        static xor_node* get_next(const xor_node* previous_node, const xor_node* current_node);
        static xor_node* get_prev(const xor_node* current_node, const xor_node* next_node);
        unsigned long _length;
        xor_node* _first_node;
        xor_node* _last_node;

    public:
        xor_list();
        ~xor_list();

        T& front();
        const T& front() const;

        T& get(const unsigned int index);
        T& operator[](const unsigned int index);

        const T& get(const unsigned int index) const;
        const T& operator[](const unsigned int index) const;

        T pop_back();
        T pop_front();
        unsigned long length() const;
        void push_back(T item);
        void push_front(T item);

        void print() const;

        class iterator {
            friend class xor_list;
            private:
                xor_node* _previous_node;
                xor_node* _node;

                iterator(xor_node* previous_node, xor_node* node);
            public:
                iterator& operator++();
                iterator operator++(int);
                bool operator==(const iterator& rhs) const;
                bool operator!=(const iterator& rhs) const;
                T& operator*();
        };

        class const_iterator {
            friend class xor_list;
            private:
                const xor_node* _previous_node;
                const xor_node* _node;

                const_iterator(const xor_node* previous_node, const xor_node* node);
            public:
                const_iterator& operator++();
                const_iterator operator++(int);
                bool operator==(const const_iterator& rhs) const;
                bool operator!=(const const_iterator& rhs) const;
                const T& operator*() const;
        };


        iterator begin();
        iterator end();

        const_iterator cbegin() const;
        const_iterator cend() const;
};

template <typename T>
typename xor_list<T>::iterator xor_list<T>::begin() {
    return iterator(0, _first_node);
};

template <typename T>
typename xor_list<T>::iterator xor_list<T>::end() {
    return iterator(_last_node, 0);
};

template <typename T>
typename xor_list<T>::const_iterator xor_list<T>::cbegin() const {
    return const_iterator(0, _first_node);
};

template <typename T>
typename xor_list<T>::const_iterator xor_list<T>::cend() const {
    return const_iterator(_last_node, 0);
};


// iterator definitions

template <typename T>
xor_list<T>::iterator::iterator(xor_node* previous_node, xor_node* node) {
    _previous_node = previous_node;
    _node = node;
}

template <typename T>
typename xor_list<T>::iterator& xor_list<T>::iterator::operator++() {
    xor_node* next_node = xor_list::get_next(_previous_node, _node);
    _previous_node = _node;
    _node = next_node;

    return (*this);
}
template <typename T>
typename xor_list<T>::iterator xor_list<T>::iterator::operator++(int) {
    xor_node* previous_node = _previous_node;
    xor_node* node = _node;

    xor_node* next_node = xor_list::get_next(_previous_node, _node);
    _previous_node = _node;
    _node = next_node;

    return iterator(previous_node, node);
}

template <typename T>
bool xor_list<T>::iterator::operator==(const iterator& rhs) const {
    return (_node == rhs._node);
}

template <typename T>
bool xor_list<T>::iterator::operator!=(const iterator& rhs) const {
    return (_node != rhs._node);
}

template <typename T>
T& xor_list<T>::iterator::operator*() {
    return (_node->value);
}

// end iterator definitions


// const_iterator definitions

template <typename T>
xor_list<T>::const_iterator::const_iterator(const xor_node* previous_node, const xor_node* node) {
    _previous_node = previous_node;
    _node = node;
}

template <typename T>
typename xor_list<T>::const_iterator& xor_list<T>::const_iterator::operator++() {
    const xor_node* next_node = xor_list::get_next(_previous_node, _node);
    _previous_node = _node;
    _node = next_node;

    return (*this);
}
template <typename T>
typename xor_list<T>::const_iterator xor_list<T>::const_iterator::operator++(int) {
    const xor_node* previous_node = _previous_node;
    const xor_node* node = _node;

    const xor_node* next_node = xor_list::get_next(_previous_node, _node);
    _previous_node = _node;
    _node = next_node;

    return const_iterator(previous_node, node);
}

template <typename T>
bool xor_list<T>::const_iterator::operator==(const const_iterator& rhs) const {
    return (_node == rhs._node);
}

template <typename T>
bool xor_list<T>::const_iterator::operator!=(const const_iterator& rhs) const {
    return (_node != rhs._node);
}

template <typename T>
const T& xor_list<T>::const_iterator::operator*() const {
    return (_node->value);
}

// end const_iterator definitions

template <typename T>
void xor_list<T>::xor_node::print() const {
    std::cout << "(" << (unsigned long) this << ")\t" << value << "\t(" << (unsigned long) address << ")" << std::endl;
}

template <typename T>
typename xor_list<T>::xor_node* xor_list<T>::get_next(const xor_node* previous_node, const xor_node* current_node) {
    if (current_node->address == 0) return 0;
    else return (xor_node*) ((unsigned long) previous_node ^ (unsigned long) current_node->address);
}

template <typename T>
typename xor_list<T>::xor_node* xor_list<T>::get_prev(const xor_node* current_node, const xor_node* next_node) {
    return (xor_node*) ((unsigned long) current_node->address ^ (unsigned long) next_node);
}

template <typename T>
xor_list<T>::xor_list() {
    _first_node = 0;
    _last_node = 0;
    _length = 0;
}

template <typename T>
xor_list<T>::~xor_list() {
    if (_first_node != 0) {
        const xor_node* previous_node = 0;
        const xor_node* current_node = _first_node;
        do {
            const xor_node* next_node = xor_list::get_next(previous_node, current_node);

            previous_node = current_node;
            current_node = next_node;

            delete previous_node;
        } while (current_node != _last_node);
    }
}

template <typename T>
unsigned long xor_list<T>::length() const {
    return _length;
}

template <typename T>
void xor_list<T>::print() const {
    std::cout << "List:\t\t\t(Length: " << this->length() << ")" << std::endl;
    std::cout << "(Address)\t(Value)\t(XOR Addr)" << std::endl;
    if (_first_node != 0) {
        _first_node->print();

        const xor_node* previous_node = 0;
        const xor_node* current_node = _first_node;
        while (current_node != _last_node) {
            const xor_node* next_node = xor_list::get_next(previous_node, current_node);

            previous_node = current_node;
            current_node = next_node;

            current_node->print();
        }
    }

    std::cout << std::endl;
}

template <typename T>
void xor_list<T>::push_back(T item) {
    ++_length;
    xor_node* new_node = new xor_node();
    new_node->value = item;
    new_node->address = 0;

    if (_last_node != 0) {
        const xor_node* previous_node = xor_list::get_prev(_last_node, 0);

        _last_node->address = (xor_node*) ((unsigned long) previous_node ^ (unsigned long) new_node);
        new_node->address = _last_node;
        _last_node = new_node;
    }
    else {
        _first_node = new_node;
        _last_node = _first_node;
    }
}

template <typename T>
void xor_list<T>::push_front(T item) {
    ++_length;
    xor_node* new_node = new xor_node();
    new_node->value = item;
    new_node->address = 0;

    if (_first_node != 0) {
        _first_node->address = (xor_node*) (((unsigned long) new_node) ^ ((unsigned long) (_first_node->address)));
        new_node->address = _first_node;

        _first_node = new_node;
    }
    else {
        _first_node = new_node;
        _last_node = _first_node;
    }
}

template <typename T>
T& xor_list<T>::front() {
    return _first_node->value;
}

template <typename T>
const T& xor_list<T>::front() const {
    return _first_node->value;
}

template <typename T>
T& xor_list<T>::get(const unsigned int index) {
    const bool from_front = index < ((unsigned long) _length/2.0);
    const xor_node* previous_node = 0;
    xor_node* current_node = (from_front ? _first_node : _last_node);
    const unsigned int iterations = (from_front ? index : _length-index-1);
    for (unsigned int i=0; i<iterations; ++i) {

        xor_node* next_node =
            (
                from_front ?
                    xor_list::get_next(previous_node, current_node)
                :
                    xor_list::get_prev(current_node, previous_node)
            );

        previous_node = current_node;
        current_node = next_node;
    }
    return current_node->value;
}

template <typename T>
T& xor_list<T>::operator[](const unsigned int index) {
    return this->get(index);
}

template <typename T>
const T& xor_list<T>::get(const unsigned int index) const {
    const bool from_front = index < ((unsigned long) _length/2.0);
    const xor_node* previous_node = 0;
    xor_node* current_node = (from_front ? _first_node : _last_node);
    const unsigned int iterations = (from_front ? index : _length-index-1);
    for (unsigned int i=0; i<iterations; ++i) {

        xor_node* next_node =
            (
                from_front ?
                    xor_list::get_next(previous_node, current_node)
                :
                    xor_list::get_prev(current_node, previous_node)
            );

        previous_node = current_node;
        current_node = next_node;
    }
    return current_node->value;
}

template <typename T>
const T& xor_list<T>::operator[](const unsigned int index) const {
    return this->get(index);
}

template <typename T>
T xor_list<T>::pop_back() {
    // List is empty
    if (_length == 0) return T(); // _last_node->value;
    // Removing last item from the list
    else if (_length == 1) {
        T value = _last_node->value;
        delete _last_node;
        _last_node = 0;
        _first_node = 0;
        --_length;
        return value;
    }
    // Removing an item from the list
    else {
        const xor_node* popped = _last_node;
        xor_node* previous = xor_list::get_prev(popped, 0);
        previous->address = (xor_node*) ((unsigned long) previous->address ^ (unsigned long) popped);
        _last_node = previous;
        --_length;

        T value = popped->value;
        delete popped;
        return value;
    }
}

template <typename T>
T xor_list<T>::pop_front() {
    if (_length == 0) {
        return T();
    }
    else if (_length == 1) {
        --_length;

        T value = _first_node->value;
        delete _first_node;
        _first_node = 0;
        _last_node = 0;
        return value;
    }
    else {
        const xor_node* shifted = _first_node;
        xor_node* next = xor_list::get_next(0, shifted);
        next->address = (xor_node*) ((unsigned long) next->address ^ (unsigned long) shifted);
        _first_node = next;
        --_length;

        T value = shifted->value;
        delete shifted;
        return value;
    }
}

#endif
