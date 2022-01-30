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
        this->front = this->rear = this->size = 0;
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
        if (this->is_full())
            return;

        if (this->rear < this->capacity)
        {

            this->array[this->rear] = data;
            this->rear = this->rear + 1;
            this->size = this->size + 1;
        }
    }

    int dequeue()
    {
        if (this->is_empty())
            return INT_MIN;

        if (this->front < this->rear)
        {
            this->front = this->front + 1;
            this->size = this->size - 1;
            return this->array[this->front - 1];
        }
        return INT_MIN;
    }

    int peek()
    {
        return this->array[this->front];
    }

    void display_queue()
    {
        for (int i = this->front; i < this->rear; i++)
        {
            cout << this->array[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    Queue *queue = new Queue(MAX_QUEUE_CAPACITY);

    cout << "Is the queue empty? " << queue->is_empty() << endl;
    cout << "Is the queue full? " << queue->is_full() << endl;

    cout << "----- Enqueue -----" << endl;
    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);
    queue->enqueue(4);
    queue->enqueue(5);

    cout << "----- Display -----" << endl;
    queue->display_queue();

    cout << "Is the queue empty? " << queue->is_empty() << endl;
    cout << "Is the queue full? " << queue->is_full() << endl;

    cout << "Peek: " << queue->peek() << endl;

    cout << "----- Dequeue ----- " << endl;
    cout << queue->dequeue() << endl;
    cout << queue->dequeue() << endl;

    cout << "Peek: " << queue->peek() << endl;

    cout << "----- Display -----" << endl;
    queue->display_queue();

    cout << "Is the queue empty? " << queue->is_empty() << endl;
    cout << "Is the queue full? " << queue->is_full() << endl;
    return 0;
}