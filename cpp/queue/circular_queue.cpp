#include <iostream>
#define MAX_QUEUE_CAPACITY 5

using namespace std;

class Queue
{
    int rear, front, size;
    unsigned capacity;
    int *array;

public:
    Queue(unsigned capacity)
    {
        this->rear = this->front = this->size = 0;
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

        this->array[this->rear] = data;
        this->rear = (this->rear + 1) % this->capacity;
        (this->size)++;
    }

    int dequeue()
    {
        if (this->is_empty())
            return INT_MIN;

        this->front = (this->front + 1) % this->capacity;
        (this->size)--;
        return this->array[this->front - 1];
    }

    void display_queue()
    {
        cout << "size: " << this->size << endl;
        if (this->front < this->rear)
        {
            for (int i = this->front; i < this->rear; i++)
            {
                cout << this->array[i] << " ";
            }
        }
        else if (this->front >= this->rear)
        {
            for (int i = this->front; i < this->capacity; i++)
            {
                cout << this->array[i] << " ";
            }
            for (int i = 0; i < this->rear; i++)
            {
                cout << this->array[i] << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    Queue *queue = new Queue(MAX_QUEUE_CAPACITY);

    cout << "----- Enqueue -----" << endl;
    queue->enqueue(14);
    queue->enqueue(22);
    queue->enqueue(13);
    queue->enqueue(-6);

    cout << "----- Display -----" << endl;
    queue->display_queue();

    cout << "----- Dequeue -----" << endl;
    cout << queue->dequeue() << endl;
    cout << queue->dequeue() << endl;

    cout << "----- Display -----" << endl;
    queue->display_queue();

    cout << "----- Enqueue -----" << endl;
    queue->enqueue(9);
    queue->enqueue(20);
    queue->enqueue(5);

    cout << "----- Display -----" << endl;
    queue->display_queue();

    cout << "----- Enqueue -----" << endl;
    queue->enqueue(20);

    cout << "----- Display -----" << endl;
    queue->display_queue();
    
    return 0;
}