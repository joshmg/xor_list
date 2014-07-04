#include <new>
#include <iostream>

template <class T>
class xor_list {
    private:
        struct xor_node {
            mutable xor_node* address;
            T value;

            void print() const {
                std::cout << value << std::endl;
            }
        };

        static const xor_node* get_next(const xor_node* previous_node, const xor_node* current_node) {
            if (current_node->address == 0) return 0;
            else return (xor_node*) ((unsigned long) previous_node ^ (unsigned long) current_node->address);
        }

        xor_node* _first;

    public:
        xor_list() {
            _first = 0;
        }

        void push(T item) {
            xor_node* new_node = new xor_node();
            new_node->value = item;

            if (_first != 0) {
                _first->print();

                const xor_node* previous_node = 0;
                const xor_node* current_node = _first;
                while (current_node->address != 0) {
                    // xor_node* next_node = (xor_node*) ((unsigned long) previous_node ^ (unsigned long) current_node->address);
                    const xor_node* next_node = xor_list::get_next(previous_node, current_node);

                    previous_node = current_node;
                    current_node = next_node;

                    current_node->print();
                }
                current_node->address = (xor_node*) ((unsigned long) previous_node ^ (unsigned long) new_node);
            }
            else {
                _first = new_node;
                _first->address = 0;
            }

            new_node->print();
        }

        T pop() {
            
            return T();
        }
        T shift() {
            return T();
        }

        ~xor_list() {
            if (_first == 0) {
                return;
            }
            else {
                const xor_node* current = _first;
                const xor_node* next = xor_list::get_next(0, _first);
                while (next != 0) {
                    const xor_node* previous = current;
                    current = next;
                    next = xor_list::get_next(previous, current);
                    delete previous;
                    
                }
                delete current;
            }
        }
};

int main() {
    xor_list<int> list;

    list.push(120);
    std::cout << std::endl;
    list.push(121);
    std::cout << std::endl;
    list.push(122);
    std::cout << std::endl;
    list.push(123);
    std::cout << std::endl;
    list.push(124);
    std::cout << std::endl;
    list.push(125);
    std::cout << std::endl;

    return 0;
}
