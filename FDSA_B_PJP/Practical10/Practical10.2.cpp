#include <iostream>
using namespace std;

#define SIZE 10

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class HashTable
{
    Node* table[SIZE];

public:

    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(int bookCode)
    {
        int index = bookCode % SIZE;

        Node* newNode = new Node(bookCode);

        if (table[index] == NULL)
        {
            table[index] = newNode;
        }
        else
        {
            Node* temp = table[index];

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    void display()
    {
        cout << "Final Shelf Contents:" << endl;

        for (int i = 0; i < SIZE; i++)
        {
            cout << "Shelf " << i << ": ";

            Node* temp = table[i];

            if (temp == NULL)
            {
                cout << "Empty";
            }
            else
            {
                while (temp != NULL)
                {
                    cout << temp->data << " -> ";
                    temp = temp->next;
                }

                cout << "NULL";
            }

            cout << endl;
        }
    }
};

int main()
{
    HashTable h;

    int books[] = {101, 112, 123, 134, 145, 155, 165};

    int n = 7;

    for (int i = 0; i < n; i++)
    {
        h.insert(books[i]);
    }

    h.display();

    return 0;
}