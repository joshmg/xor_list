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

        const xor_node* _first_node;
        const xor_node* _last_node;

    public:
        xor_list() {
            _first_node = 0;
            _last_node = 0;
        }

        void print() const {
            std::cout << "List:" << std::endl;
            if (_first_node != 0) {
                _first_node->print();

                const xor_node* previous_node = 0;
                const xor_node* current_node = _first_node;
                do {
                    const xor_node* next_node = xor_list::get_next(previous_node, current_node);

                    previous_node = current_node;
                    current_node = next_node;

                    current_node->print();
                } while (current_node != _last_node);
            }

            std::cout << std::endl;
        }

        void push(T item) {
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
            return T();
        }
        T shift() {
            return T();
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
    }

    return 0;
}
