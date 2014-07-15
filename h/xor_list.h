#ifndef XOR_LIST_H
#define XOR_LIST_H

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
        mutable unsigned long _length;
        mutable bool _is_length_set;
        xor_node* _first_node;
        xor_node* _last_node;

        void _count_length() const;

    public:
        class iterator;
        class const_iterator;

        xor_list();
        ~xor_list();

        T& front();
        const T& front() const;
        T& back();
        const T& back() const;

        T& get(const unsigned int index);
        T& operator[](const unsigned int index);
        const T& get(const unsigned int index) const;
        const T& operator[](const unsigned int index) const;

        T pop_back();
        T pop_front();
        void push_back(T item);
        void push_front(T item);

        unsigned long length() const;

        // Splits the current list into two lists at the iterator.
        // The item pointed to by iterator is the first element added to the new list. (It's inclusive to the new list)
        // This function modifies the current list.
        xor_list<T>* split(iterator it);
        void join(xor_list<T>*& list);

        void flip();

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
                iterator& operator--();
                iterator operator--(int);
                bool operator==(const iterator& rhs) const;
                bool operator!=(const iterator& rhs) const;
                bool operator==(const const_iterator& rhs) const;
                bool operator!=(const const_iterator& rhs) const;
                T& operator*();

                bool has_next() const;
                bool has_prev() const;

                operator const_iterator() const;
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
                const_iterator& operator--();
                const_iterator operator--(int);
                bool operator==(const const_iterator& rhs) const;
                bool operator!=(const const_iterator& rhs) const;
                const T& operator*() const;

                bool has_next() const;
                bool has_prev() const;
        };

        iterator begin();
        iterator end();

        const_iterator cbegin() const;
        const_iterator cend() const;
};

#include "../xor_list.cpp"

#endif
