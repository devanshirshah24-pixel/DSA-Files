
#include <iostream>
using namespace std;

#define MAX 5

class Queue
{
    int arr[MAX];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    void join(int token)
    {
        if ((rear + 1) % MAX == front)
        {
            cout << "Error: Queue is Full" << endl;
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % MAX;
        arr[rear] = token;

        displayFront();
    }

    void serve()
    {
        if (front == -1)
        {
            cout << "Error: Queue is Empty" << endl;
            return;
        }

        cout << "Served Token: " << arr[front] << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }

        displayFront();
    }

    void displayFront()
    {
          if (front == -1)
        {
            cout << "Current Front: Empty" << endl;
        }
        else
        {
            cout<<"Current Front:"<< arr[front]<<endl;
        }
    }
    
};

int main()
{
   Queue q;

    q.join(101);
    q.join(102);
    q.join(103);
    q.serve();
    q.join(104);
    q.join(105);
    q.join(106);
    q.serve();

    return 0;
}