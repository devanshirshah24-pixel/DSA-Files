#include <iostream>
using namespace std;

class Node
{
public:
    int patient;
    Node* next;

    Node(int p)
    {
        patient = p;
        next = NULL;
    }
};

class Queue
{
    Node* front;
    Node* rear;

public:

    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void arrive(int patient)
    {
        Node* newNode = new Node(patient);

        if (rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Patient " << patient << " arrived." << endl;
        displayFront();
    }

    void attend()
    {
        if (front == NULL)
        {
            cout << "Error: No patients waiting" << endl;
            return;
        }

        Node* temp = front;

        cout << "Patient " << front->patient << " attended." << endl;

        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }

        delete temp;

        displayFront();
    }

    void displayFront()
    {
        if (front == NULL)
        {
            cout << "Current front patient: Empty" << endl;
        }
        else
        {
            cout << "Current front patient: "
                 << front->patient << endl;
        }
    }
};

int main()
{
    Queue q;

    q.arrive(201);
    q.arrive(202);
    q.arrive(203);

    q.attend();
    q.attend();

    q.arrive(204);
    q.arrive(205);

    q.attend();
    q.attend();
    q.attend();

    q.attend();

    return 0;
}