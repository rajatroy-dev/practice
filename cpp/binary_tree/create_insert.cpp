#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node Node;

Node *create_node(int data)
{
    Node *node;
    node = new Node();
    node->data = data;
    node->left = node->right = NULL;

    return node;
}

Node *insert_node(Node *node, int data)
{
    if (node == NULL)
        return create_node(data);
    else if (data < node->data)
        node->left = insert_node(node->left, data);
    else if (data > node->data)
        node->right = insert_node(node->right, data);

    return node;
}

void print_pre_order(Node *node)
{
    if (node == NULL)
        return;

    cout << node->data << endl;
    print_pre_order(node->left);
    print_pre_order(node->right);
}

int main()
{
    Node *root = create_node(1);

    root->left = create_node(2);
    root->right = create_node(3);

    root->left->left = create_node(4);
    insert_node(root, 5);

    print_pre_order(root);
    return 0;
}