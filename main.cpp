#include "node.h"
#include "node_utils.h"


int main() {
    node::Node* root = node::read();

    if (node::contains_even_three_digit(root)) {
        node::sort_by_first_digit(root);
    } else {
        node::delete_numbers_with_even_digits_count(root);
        node::duplicate_numbers_with_odd_digits_count(root);
    }
    node::print(root);
    node::clear(root);

    return 0;
}
