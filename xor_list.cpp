#include <new>
#include <iostream>

template <class T>
class xor_list {
    private:
        struct xor_node {
            mutable const xor_node* address;
            T value;

            void print() const {
                std::cout << "(" << (unsigned long) this << ") " << value << " (" << (unsigned long) address << ")" << std::endl;
            }
        };

        static const xor_node* get_next(const xor_node* previous_node, const xor_node* current_node) {
            if (current_node->address == 0) return 0;
            else return (xor_node*) ((unsigned long) previous_node ^ (unsigned long) current_node->address);
        }
        static const xor_node* get_prev(const xor_node* current_node, const xor_node* next_node) {
            return (xor_node*) ((unsigned long) current_node->address ^ (unsigned long) next_node);
        }

        unsigned long _length;
        const xor_node* _first_node;
        const xor_node* _last_node;

    public:
        xor_list() {
            _first_node = 0;
            _last_node = 0;
            _length = 0;
        }

        unsigned long length() const {
            return _length;
        }

        void print() const {
            std::cout << "List:" << std::endl;
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

        void push(T item) {
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

        T pop() {
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
                const xor_node* previous = xor_list::get_prev(popped, 0);
                previous->address = (xor_node*) ((unsigned long) previous->address ^ (unsigned long) popped);
                _last_node = previous;
                --_length;

                T value = popped->value;
                delete popped;
                return value;
            }
        }
        T shift() {
            if (_length == 0) {
                return T();
            }
            else if (_length == 1) {
                T value = _first_node->value;
                delete _first_node;
                _first_node = 0;
                _last_node = 0;
                return value;
            }
            else {
                const xor_node* shifted = _first_node;
                const xor_node* next = xor_list::get_next(0, shifted);
                next->address = (xor_node*) ((unsigned long) next->address ^ (unsigned long) shifted);
                _first_node = next;
                --_length;

                T value = shifted->value;
                delete shifted;
                return value;
            }
        }

        ~xor_list() {
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
};

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
