#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node node;

Node *new_node(int data)
{
    Node *node;
    node = new Node();
    node->data = data;
    node->left = node->right = NULL;

    return node;
}

void print_pre_order(Node *node)
{
    cout << node->data << " ";
    if (node->left != NULL)
        print_pre_order(node->left);
    if (node->right != NULL)
        print_pre_order(node->right);
}

int main()
{
    Node *a_node = new_node(1);
    a_node->left = new_node(2);
    a_node->right = new_node(3);
    a_node->left->left = new_node(4);
    a_node->right->right = new_node(5);

    print_pre_order(a_node);

    return 0;
}