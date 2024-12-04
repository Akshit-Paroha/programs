#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:
    T arr[10];
    int f, r;

public:
    Queue() : f(-1), r(-1) {}

    void enqueue(T value)
    {

        if (r >= 9)
        {
            cout << "Queue Overflow!" << endl;
            return;
        }

        if (f == -1)
        {
            f = 0;
        }

        arr[++r] = value;
    }

    T dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!" << endl;
            exit(1);
        }
        T value = arr[f];
        if (f == r)
        {
            f = r = -1;
        }
        else
        {
            f++;
        }

        return value;
    }

    T front()
    {

        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            exit(1);
        }
        return arr[f];
    }
    bool isEmpty()
    {
        return f == -1;
    }
};

int main()
{
    Queue<int> intQueue;
    intQueue.enqueue(1);
    intQueue.enqueue(2);
    intQueue.enqueue(3);
    cout << "Front element: " << intQueue.front() << endl;
    cout << "Dequeuing elements: ";

    while (!intQueue.isEmpty())
    {
        cout << intQueue.dequeue() << " ";
    }

    cout << endl;
    Queue<char> charQueue;
    charQueue.enqueue('X');
    charQueue.enqueue('Y');
    charQueue.enqueue('Z');
    cout << "Front element: " << charQueue.front() << endl;
    cout << "Dequeuing elements: ";
    while (!charQueue.isEmpty())
    {
        cout << charQueue.dequeue() << " ";
    }
    cout << endl;
    return 0;
}