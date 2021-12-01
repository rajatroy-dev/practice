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

void print_in_order(Node *node)
{
    if (node != NULL)
    {
        if (node->left != NULL)
            print_in_order(node->left);
        cout << node->data << " ";
        if (node->right != NULL)
            print_in_order(node->right);
    }
}

Node *find_min(Node *node)
{
    Node *temp = node;

    while (temp != NULL && temp->left != NULL)
        temp = temp->left;

    return temp;
}

Node *delete_node(Node *node, int data)
{
    if (node == NULL)
        return node;
    else if (data < node->data)
    {
        node->left = delete_node(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = delete_node(node->right, data);
    }
    else
    {
        if (node->left == NULL && node->right == NULL)
        {
            free(node);
            node = NULL;
        }
        else if (node->left == NULL)
        {
            node = node->right;
        }
        else if (node->right == NULL)
        {
            node = node->left;
        }
        else
        {
            Node *temp = find_min(node->right);
            node->data = temp->data;
            node->right = delete_node(node->right, temp->data);
        }
    }

    return node;
}

int main()
{
    Node *node = NULL;
    node = insert_node(node, 50);
    node = insert_node(node, 30);
    node = insert_node(node, 20);
    node = insert_node(node, 40);
    node = insert_node(node, 70);
    node = insert_node(node, 60);
    node = insert_node(node, 80);

    cout << "Print In Order" << endl;
    print_in_order(node);
    cout << endl;

    cout << "Delete 20" << endl;
    node = delete_node(node, 20);
    cout << "Print In Order" << endl;
    print_in_order(node);
    cout << endl;

    cout << "Delete 30" << endl;
    node = delete_node(node, 30);
    cout << "Print In Order" << endl;
    print_in_order(node);
    cout << endl;

    cout << "Delete 50" << endl;
    node = delete_node(node, 50);
    cout << "Print In Order" << endl;
    print_in_order(node);
    cout << endl;

    return 0;
}