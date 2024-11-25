#include <bits/stdc++.h>
using namespace std;
// implementing a queue using array
class Queue
{
    int *arr, f, r, size;

public:
    Queue(int x)
    {
        arr = new int[x];
        size = x;
        f = r = -1;
    }
    void enqueue(int);
    void display();
    int dequeue();
};
void Queue::enqueue(int data)
{
    if (r == size - 1)
    {
        cout << "Queue is empty\n";
    }
    else
    {
        if (f == -1)
        {
            f++;
        }
        r++;
        arr[r] = data;
    }
}
int Queue::dequeue()
{
    if (f == -1)
    {
        cout << "Queue is empty\n";
        return -1;
    }
    else
    {
        int data = arr[f];
        if (f == r)
        {
            f = r = -1;
        }
        else
        {
            f++;
            return data;
        }
    }
}

class Cqueue
{
    int *arr, f, r, size;

public:
    Cqueue(int x)
    {
        size = x;
        arr = new int[size];
        f = r = -1;
    }
    void enqueue(int);
    void display();
    int dequeue();
};
void Cqueue::enqueue(int data)
{
    if ((r == size - 1 and f == 0) or ((r + 1) % size == f))
    {
        cout << "Queue is full\n";
    }
    else
    {
        r = (r + 1) % size;
        arr[r] = data;
        if (f == -1)
        {
            f = 0;
        }
    }
}
int Cqueue::dequeue()
{
    if (f == -1)
    {
        cout << "Queue is empty\n";
        return -1;
    }
    else
    {
        int data = arr[f];
        if (f == r)
        {
            f = r = -1;
        }
        else
        {
            f = (f + 1) % size;
        }
        return data;
    }
}
void Cqueue::display()
{
    if (f <= r)
    {
        for (int i = f; i <= r; i++)
        {
            cout << arr[i] << "\t";
        }
    }
    else
    {
        for (int i = 0; i <= r; i++)
        {
            cout << arr[i] << "\t";
        }
        for (int i = f; i < size; i++)
        {
            cout << arr[i] << "\t";
        }
    }
}

struct elem{
    int data,priority;
    elem(int x,int y):priority(y),data(x){};
};
class Pqueue
{
    
public:
    Pqueue(int x)
    {
    }
    void enqueue(int);
    void display();
    int dequeue();
};

int main()
{
    
    return 0;
}