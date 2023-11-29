#include <iostream>

#include "node.h"


unsigned _get_number_first_digit(unsigned number);
unsigned _get_number_digits_count(unsigned number);
unsigned _check_all_number_digits_even(unsigned number);


namespace node {
    Node* read() {
        node::Node* root = node::init();

        unsigned n;
        std::cin >> n;
        for (unsigned i = 0; i < n; i++) {
            int value;
            std::cin >> value;
            node::add_back(root, value);
        }
        return root;
    }

    bool contains_even_three_digit(Node* root){
        auto is_contains = false;

        Node* current = root->next;
        while (!(current->is_fictitious)) {
            int& data = current->data;
            if (
                (100 <= data && data <= 999)  // Трёхзначное
                && _check_all_number_digits_even(data)  // Состоит только из четных цифр
            ) {
                is_contains = true;
            }

            current = current->next;
        }

        return is_contains;
    }

    void sort_by_first_digit(Node *root) {
        unsigned len = node::len(root);
        for (auto i = 0u; i < len - 1; i++) {
            Node *current = root->next;
            Node *next = current->next;
            while (!(next->is_fictitious)) {
                auto a = _get_number_first_digit(current->data);
                auto b = _get_number_first_digit(next->data);

                if (a > b) {
                    int tmp = next->data;
                    next->data = current->data;
                    current->data = tmp;
                }
                current = next;
                next = next->next;
            }
        }
    }

    void delete_numbers_with_even_digits_count(Node *root) {
        Node* current = root->next;
        while (!(current->is_fictitious)) {
            auto& data = current->data;
            auto next = current->next;
            if(_get_number_digits_count(data) % 2 == 0) {
                node::remove_by_value(current->last, data);
            }

            current = next;
        }
    }

    void duplicate_numbers_with_odd_digits_count(Node *root) {
        Node* current = root->next;
        while (!(current->is_fictitious)) {
            auto& data = current->data;
            if(_get_number_digits_count(data) % 2 != 0) {
                node::duplicate_by_value(current->last, data);
                current = current->next;
            }

            current = current->next;
        }
    }
}


unsigned _get_number_first_digit(unsigned number) {
    while (number >= 10){
        number /= 10;
    }
    return number;
}


unsigned _get_number_digits_count(unsigned number) {
    auto count = 0u;
    while(number != 0) {
        number /= 10;
        count++;
    }
    return count;
}


unsigned _check_all_number_digits_even(unsigned number) {
    bool result = true;

    while(number != 0) {
        auto digit = number % 10;
        if (digit % 2 != 0) {
            result = false;
        }

        number /= 10;
    }
    return result;
}
