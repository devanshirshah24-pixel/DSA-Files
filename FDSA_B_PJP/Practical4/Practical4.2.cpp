#include <iostream>
using namespace std;

struct Node
{
    int token;
    Node* next;
};

Node* head = NULL;


// Insert at end
void insertAtEnd(int value)
{
    Node* newNode = new Node;

    newNode->token = value;
    newNode->next = NULL;

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


// Delete node by value
void deleteByValue(int value)
{
    if (head == NULL)
    {
        cout << "Queue is empty." << endl;
        return;
    }

    Node* temp = head;
    Node* previous = NULL;

    // Search for the value
    while (temp != NULL && temp->token != value)
    {
        previous = temp;
        temp = temp->next;
    }

    // Value not found
    if (temp == NULL)
    {
        cout << "Token " << value << " not found." << endl;
        return;
    }

    // Delete first node
    if (temp == head)
    {
        head = head->next;
        delete temp;
        return;
    }

    // Delete middle or last node
    previous->next = temp->next;

    delete temp;
}


// Forward traversal
void displayForward()
{
    if (head == NULL)
    {
        cout << "Queue is empty." << endl;
        return;
    }

    Node* temp = head;

    cout << "Front to Back: ";

    while (temp != NULL)
    {
        cout << temp->token << " ";
        temp = temp->next;
    }

    cout << endl;
}


// Reverse printing using recursion
void displayReverse(Node* temp)
{
    if (temp == NULL)
    {
        return;
    }

    // Go to the last node first
    displayReverse(temp->next);

    // Print while returning
    cout << temp->token << " ";
}


int main()
{
    cout << "===== HOSPITAL PATIENT QUEUE =====" << endl;

    // Create queue
    insertAtEnd(101);
    insertAtEnd(102);
    insertAtEnd(103);
    insertAtEnd(104);
    insertAtEnd(105);

    cout << "\nInitial Queue:" << endl;
    displayForward();

    // Reverse printing
    cout << "\nReverse Queue:" << endl;
    cout << "Back to Front: ";
    displayReverse(head);
    cout << endl;

    // Delete middle node
    cout << "\nDeleting token 103..." << endl;
    deleteByValue(103);

    displayForward();

    cout << "Back to Front: ";
    displayReverse(head);
    cout << endl;

    // Delete first node
    cout << "\nDeleting token 101..." << endl;
    deleteByValue(101);

    displayForward();

    // Delete last node
    cout << "\nDeleting token 105..." << endl;
    deleteByValue(105);

    displayForward();

    // Try deleting non-existing token
    cout << "\nDeleting token 999..." << endl;
    deleteByValue(999);

    return 0;
}