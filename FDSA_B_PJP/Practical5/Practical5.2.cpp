#include <iostream>
#include <string>
using namespace std;

struct SNode
{
    string name;
    SNode* next;
};

SNode* shead = NULL;

void sInsertBeginning(string name)
{
    SNode* newNode = new SNode;
    newNode->name = name;

    if (shead == NULL)
    {
        shead = newNode;
        newNode->next = shead;
        return;
    }

    SNode* temp = shead;

    while (temp->next != shead)
    {
        temp = temp->next;
    }

    newNode->next = shead;
    temp->next = newNode;
    shead = newNode;
}

void sInsertEnd(string name)
{
    SNode* newNode = new SNode;
    newNode->name = name;

    if (shead == NULL)
    {
        shead = newNode;
        newNode->next = shead;
        return;
    }

    SNode* temp = shead;

    while (temp->next != shead)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = shead;
}


void sInsertAfter(string givenName, string newName)
{
    if (shead == NULL)
    {
        cout << "Circle is empty." << endl;
        return;
    }

    SNode* temp = shead;

    do
    {
        if (temp->name == givenName)
        {
            SNode* newNode = new SNode;

            newNode->name = newName;

            newNode->next = temp->next;
            temp->next = newNode;

            return;
        }

        temp = temp->next;

    } while (temp != shead);

    cout << "Student not found." << endl;
}


void sDelete(string name)
{
    if (shead == NULL)
    {
        cout << "Circle is empty." << endl;
        return;
    }

    if (shead->next == shead)
    {
        if (shead->name == name)
        {
            delete shead;
            shead = NULL;
        }
        else
        {
            cout << "Student not found." << endl;
        }

        return;
    }

    SNode* current = shead;
    SNode* previous = NULL;

    do
    {
        if (current->name == name)
        {
            if (current == shead)
            {
                SNode* last = shead;

                while (last->next != shead)
                {
                    last = last->next;
                }

                shead = shead->next;
                last->next = shead;

                delete current;
                return;
            }

            previous->next = current->next;

            delete current;
            return;
        }

        previous = current;
        current = current->next;

    } while (current != shead);

    cout << "Student not found." << endl;
}


void sDisplay()
{
    if (shead == NULL)
    {
        cout << "Singly Circle: Empty" << endl;
        return;
    }

    SNode* temp = shead;

    cout << "Singly Circle: ";

    do
    {
        cout << temp->name;

        temp = temp->next;

        if (temp != shead)
            cout << " -> ";

    } while (temp != shead);

    cout << " -> " << shead->name << endl;
}



struct DNode
{
    string name;
    DNode* prev;
    DNode* next;
};

DNode* dhead = NULL;


void dInsertBeginning(string name)
{
    DNode* newNode = new DNode;
    newNode->name = name;

    if (dhead == NULL)
    {
        dhead = newNode;

        newNode->next = dhead;
        newNode->prev = dhead;

        return;
    }

    DNode* last = dhead->prev;

    newNode->next = dhead;
    newNode->prev = last;

    last->next = newNode;
    dhead->prev = newNode;

    dhead = newNode;
}

void dInsertEnd(string name)
{
    DNode* newNode = new DNode;
    newNode->name = name;

    if (dhead == NULL)
    {
        dhead = newNode;

        newNode->next = dhead;
        newNode->prev = dhead;

        return;
    }

    DNode* last = dhead->prev;

    newNode->next = dhead;
    newNode->prev = last;

    last->next = newNode;
    dhead->prev = newNode;
}


void dInsertAfter(string givenName, string newName)
{
    if (dhead == NULL)
    {
        cout << "Circle is empty." << endl;
        return;
    }

    DNode* temp = dhead;

    do
    {
        if (temp->name == givenName)
        {
            DNode* newNode = new DNode;

            newNode->name = newName;

            newNode->next = temp->next;
            newNode->prev = temp;

            temp->next->prev = newNode;
            temp->next = newNode;

            return;
        }

        temp = temp->next;

    } while (temp != dhead);

    cout << "Student not found." << endl;
}


void dDelete(string name)
{
    if (dhead == NULL)
    {
        cout << "Circle is empty." << endl;
        return;
    }

    DNode* temp = dhead;

    do
    {
        if (temp->name == name)
        {

            if (temp->next == temp)
            {
                delete temp;
                dhead = NULL;
                return;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            if (temp == dhead)
            {
                dhead = temp->next;
            }

            delete temp;
            return;
        }

        temp = temp->next;

    } while (temp != dhead);

    cout << "Student not found." << endl;
}


void dDisplay()
{
    if (dhead == NULL)
    {
        cout << "Doubly Circle: Empty" << endl;
        return;
    }

    DNode* temp = dhead;

    cout << "Doubly Circle: ";

    do
    {
        cout << temp->name;

        temp = temp->next;

        if (temp != dhead)
            cout << " <-> ";

    } while (temp != dhead);

    cout << " <-> " << dhead->name << endl;
}


int main()
{
    cout << "========== SINGLY CIRCULAR LINKED LIST =========="
         << endl;

    cout << "\n1. Join: A at beginning" << endl;
    sInsertBeginning("A");
    sDisplay();

    cout << "\n2. Join: B at end" << endl;
    sInsertEnd("B");
    sDisplay();

    cout << "\n3. Join: C at end" << endl;
    sInsertEnd("C");
    sDisplay();

    cout << "\n4. Join: D after B" << endl;
    sInsertAfter("B", "D");
    sDisplay();

    cout << "\n5. Leave: D" << endl;
    sDelete("D");
    sDisplay();

    cout << "\n6. Leave: A" << endl;
    sDelete("A");
    sDisplay();

    cout << "\n7. Leave: X" << endl;
    sDelete("X");
    sDisplay();


    cout << "\n\nDOUBLY CIRCULAR LINKED LIST"
         << endl;

    cout << "\n1. Join: A at beginning" << endl;
    dInsertBeginning("A");
    dDisplay();

    cout << "\n2. Join: B at end" << endl;
    dInsertEnd("B");
    dDisplay();

    cout << "\n3. Join: C at end" << endl;
    dInsertEnd("C");
    dDisplay();

    cout << "\n4. Join: D after B" << endl;
    dInsertAfter("B", "D");
    dDisplay();

    cout << "\n5. Leave: D" << endl;
    dDelete("D");
    dDisplay();

    cout << "\n6. Leave: A" << endl;
    dDelete("A");
    dDisplay();

    cout << "\n7. Leave: X" << endl;
    dDelete("X");
    dDisplay();

    return 0;
}