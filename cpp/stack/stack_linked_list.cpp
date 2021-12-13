#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;

class Stack
{
    Node *top;

public:
    Stack()
    {
        this->top = NULL;
    }

    int is_empty()
    {
        return this->top == NULL;
    }

    int is_full() // stack is full if heap is full
    {
        Node *node = new Node();

        return node == NULL;
    }

    void push(int data)
    {
        if (this->is_full())
            return;

        Node *node = new Node();
        node->data = data;
        node->next = this->top;
        this->top = node;
    }

    int pop()
    {
        if (this->is_empty())
            return INT_MIN;

        Node *temp = new Node();
        int x = 0;
        temp = this->top;
        this->top = temp->next;
        x = temp->data;
        delete temp;

        return x;
    }

    int peek()
    {
        if (this->is_empty())
            return INT_MIN;

        return this->top->data;
    }

    void display_stack()
    {
        Node *temp = this->top;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    Stack *stack = new Stack();
    cout << "----- Peek -----" << endl;
    cout << stack->peek() << endl;

    cout << "----- Push -----" << endl;
    stack->push(14);
    stack->push(22);
    stack->push(13);
    stack->push(-6);

    cout << "----- Peek -----" << endl;
    cout << stack->peek() << endl;

    cout << "----- Display -----" << endl;
    stack->display_stack();

    cout << "----- Pop -----" << endl;
    cout << stack->pop() << endl;
    cout << stack->pop() << endl;

    cout << "----- Display -----" << endl;
    stack->display_stack();

    cout << "----- Push -----" << endl;
    stack->push(9);
    stack->push(20);
    stack->push(5);

    cout << "----- Display -----" << endl;
    stack->display_stack();

    cout << "----- Push -----" << endl;
    stack->push(20);

    cout << "----- Display -----" << endl;
    stack->display_stack();

    return 0;
}