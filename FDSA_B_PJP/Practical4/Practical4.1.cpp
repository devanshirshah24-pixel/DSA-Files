#include <iostream>
using namespace std;

struct Node
{
    int token;
    Node* next;
};

Node* head = NULL;

// Insert at front
void insertAtFront(int value)
{
    Node* newNode = new Node;

    newNode->token = value;
    newNode->next = head;

    head = newNode;
}

// Insert at end
void insertAtEnd(int value)
{
    Node* newNode = new Node;

    newNode->token = value;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert at specific position
void insertAtPosition(int value, int position)
{
    // Invalid position
    if (position < 1)
    {
        cout << "Invalid position." << endl;
        return;
    }

    // Position 1 means insertion at front
    if (position == 1)
    {
        insertAtFront(value);
        return;
    }

    Node* temp = head;

    // Move to node before required position
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    // Position is out of range
    if (temp == NULL)
    {
        cout << "Position " << position << " is out of range." << endl;
        return;
    }

    Node* newNode = new Node;

    newNode->token = value;

    newNode->next = temp->next;
    temp->next = newNode;
}

// Display list
void display()
{
    Node* temp = head;

    if (head == NULL)
    {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Queue: ";

    while (temp != NULL)
    {
        cout << temp->token << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    cout << "===== HOSPITAL PATIENT QUEUE =====" << endl;

    cout << "\n1. Critical patient 101 added at front" << endl;
    insertAtFront(101);
    display();

    cout << "\n2. Routine patient 102 added at end" << endl;
    insertAtEnd(102);
    display();

    cout << "\n3. Routine patient 103 added at end" << endl;
    insertAtEnd(103);
    display();

    cout << "\n4. Priority patient 105 inserted at position 2" << endl;
    insertAtPosition(105, 2);
    display();

    cout << "\n5. Critical patient 100 added at front" << endl;
    insertAtFront(100);
    display();

    cout << "\n6. Priority patient 104 inserted at position 5" << endl;
    insertAtPosition(104, 5);
    display();

    cout << "\n7. Trying to insert 999 at position 20" << endl;
    insertAtPosition(999, 20);
    display();

    return 0;
}