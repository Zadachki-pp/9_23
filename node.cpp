#include <iostream>


namespace node {
    struct Node {
        int data;
        Node *next;
        Node *last;
        bool is_fictitious;
    };

    Node* init() {
        Node* new_node = new Node;
        new_node->next = new_node;
        new_node->last = new_node;
        new_node->is_fictitious = true;
        return new_node;
    }

    void add(Node *root, int data) {
        Node* new_node = new Node;
        Node* first_node = root->next;

        new_node->data = data;
        new_node->is_fictitious = false;

        new_node->next = first_node;
        first_node->last = new_node;
        new_node->last = root;
        root->next = new_node;
    }

    void add_back(Node *root, int data) {
        node::add(root->last, data);
    }

    void print(Node *root) {
        for(Node* current = root->next; !(current->is_fictitious); current = current->next) {
            std::cout << current->data << " ";
        }
        std::cout << std::endl;
    }

    void remove_by_value(Node *root, int value){
        Node* current = root;
        Node* next = root->next;
        while (!(next->is_fictitious)) {
            if (next->data == value) {
                Node* tmp = next;
                next = next->next;
                delete tmp;

                current->next = next;
                next->last = current;
                break;
            } else {
                current = next;
                next = next->next;
            }
        }
    }

    void duplicate_by_value(Node *root, int value){
        Node* current = root->next;
        while (!(current->is_fictitious)) {
            if (current->data == value) {
                Node* new_node = new Node;
                new_node->data = value;
                new_node->next = current->next;
                current->next->last = new_node;

                current->next = new_node;
                new_node->last = current;
                break;
            } else {
                current = current->next;
            }
        }
    }

    unsigned len(Node *root) {
        auto result = 0u;

        Node* current = root->next;
        while (!(current->is_fictitious)) {
            result++;
            current = current->next;
        }

        return result;
    }

    void sort(Node *root) {
        unsigned len = node::len(root);
        for (auto i = 0u; i < len - 1; i++) {
            Node *current = root->next;
            Node *next = current->next;
            while (!(next->is_fictitious)) {
                if (current->data > next->data) {
                    int tmp = next->data;
                    next->data = current->data;
                    current->data = tmp;
                }
                current = next;
                next = next->next;
            }
        }
    }

    void clear(Node* root) {
        Node* current = root->next;
        while (!(current->is_fictitious)) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
}