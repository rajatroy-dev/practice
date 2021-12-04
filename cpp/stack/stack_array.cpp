#include <iostream>

using namespace std;

class Stack
{
    int size;
    int top;
    unsigned capacity;
    int *array;

public:
    Stack(unsigned capacity)
    {
        this->size = this->top = 0;
        this->capacity = capacity;
        this->array = new int[capacity];
    }

    int is_full()
    {
        return (this->size == this->capacity);
    }

    int is_empty()
    {
        return (this->size == 0);
    }

    void push(int data)
    {
        if (this->is_full())
            return;

        this->array[(this->top)++] = data;
        (this->size)++;
    }

    int peek()
    {
        if (this->is_empty())
            return INT_MIN;

        return this->array[this->top - 1];
    }

    int pop()
    {
        if (this->is_empty())
            return INT_MIN;

        (this->size)--;
        return (this->array[--(this->top)]);
    }

    void display_stack()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << this->array[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack *stack = new Stack(5);
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