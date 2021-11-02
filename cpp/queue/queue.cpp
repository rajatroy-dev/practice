#include <iostream>
#define MAX_QUEUE_CAPACITY 5

using namespace std;

class Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;

public:
    Queue(unsigned capacity)
    {
        this->front = this->rear = -1;
        this->size = 0;
        this->capacity = capacity;
        this->array = new int[capacity];
    }

    int is_empty()
    {
        return (this->size == 0);
    }

    int is_full()
    {
        return (this->size == this->capacity);
    }

    void enqueue(int data)
    {
        if (is_full())
            return;
        this->array[this->rear] = data;
        this->rear = (this->rear + 1) % this->capacity;
        this->size = this->size + 1;
    }

    int dequeue()
    {
        if (is_empty())
            return INT_MIN;
        this->front = (this->front + 1) % this->capacity;
        this->size = this->size - 1;
        return this->array[this->front - 1];
    }

    int peek()
    {
        return this->array[this->front];
    }
};

int main()
{
    Queue *queue = new Queue(MAX_QUEUE_CAPACITY);

    cout << "Is the queue empty? " << queue->is_empty() << endl;
    cout << "Is the queue full? " << queue->is_full() << endl;

    cout << "Filling queue . . ." << endl;
    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);
    queue->enqueue(4);
    queue->enqueue(5);

    cout << "Is the queue empty? " << queue->is_empty() << endl;
    cout << "Is the queue full? " << queue->is_full() << endl;

    cout << "Peek: " << queue->peek() << endl;

    cout << "Dequeue . . . " << endl;
    cout << queue->dequeue() << endl;
    cout << queue->dequeue() << endl;

    cout << "Peek: " << queue->peek() << endl;

    cout << "Is the queue empty? " << queue->is_empty() << endl;
    cout << "Is the queue full? " << queue->is_full() << endl;
    return 0;
}