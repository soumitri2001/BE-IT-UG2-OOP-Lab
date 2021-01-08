/*
Complete the class with all function definitions for a circular queue
Now, create a queue with size 10 add 2, 3, 4 and 5 in that order and finally delete two elements. Display
elements present in the stack.
*/

#include <iostream>
using namespace std;

class Queue
{
    int *data;
    int front, rear;
    int size;

public:
    Queue(int);    //create queue with specified size
    void add(int); //add specified element to the queue
    int remove();  //delete element from the queue
    void disp();   //displays all elements in the queue(front to rear order)
};

Queue::Queue(int sz)
{
    size = sz;
    data = (int *)malloc(size * sizeof(int));
    front = rear = -1;
}

void Queue::add(int x)
{
    if (rear == front - 1 || (front == 0 && rear == size - 1))
    {
        cout << "queue overflow\n";
        return;
    }
    if (front == -1) // empty queue
        front = rear = 0, data[rear] = x;
    else if (front != 0 && rear == size - 1) // queue is from front -> size-1
        rear = 0, data[rear] = x;
    else
        data[++rear] = x;
}

int Queue::remove()
{
    if (front == -1) // empty queue
        return -99999;
    int top;           // element to be deleted
    if (front == rear) // one element only in queue
        top = data[front], front = rear = -1;
    else if (front == size - 1)
        top = data[front], front = 0;
    else
        top = data[front++];
    return top;
}

void Queue::disp()
{
    cout << "Contents of queue:\n";
    if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
            cout << data[i] << " ";
    }
    else
    {
        for (int i = front; i < size; i++)
            cout << data[i] << " ";
        for (int i = 0; i <= rear; i++)
            cout << data[i] << " ";
    }
    cout << "\n";
}

int main()
{
    Queue q(10);
    q.add(2);
    q.add(3);
    q.add(4);
    q.add(5);
    int d = q.remove();
    d = q.remove();
    q.disp();
}