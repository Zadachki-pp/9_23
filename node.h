

namespace node {
    struct Node {
        int data;
        Node *next;
        Node *last;
        bool is_fictitious;
    };
    Node* init();
    void add_back(Node *root, int data);
    void add(Node *root, int data);
    void print(Node *root);
    void remove_by_value(Node *root, int value);
    void duplicate_by_value(Node *root, int value);
    unsigned len(Node *root);
    void sort(Node *root);
}