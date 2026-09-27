#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string song;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertAtBeginning(string song)
{
    Node* newNode = new Node;

    newNode->song = song;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;
}


void insertAtEnd(string song)
{
    Node* newNode = new Node;

    newNode->song = song;
    newNode->next = NULL;

    
    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;


    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}


void insertAfter(string givenSong, string newSong)
{
    Node* temp = head;


    while (temp != NULL && temp->song != givenSong)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Song \"" << givenSong << "\" not found." << endl;
        return;
    }

    Node* newNode = new Node;

    newNode->song = newSong;

    newNode->next = temp->next;

    newNode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void deleteFirst()
{
    if (head == NULL)
    {
        cout << "Playlist is empty." << endl;
        return;
    }

    Node* temp = head;

    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    delete temp;
}

int countSongs()
{
    int count = 0;

    Node* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

void display()
{
    Node* temp = head;

    if (head == NULL)
    {
        cout << "Playlist is empty." << endl;
        return;
    }

    cout << "Playlist: ";

    while (temp != NULL)
    {
        cout << temp->song;

        if (temp->next != NULL)
        {
            cout << " <-> ";
        }

        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    cout << "MUSIC PLAYLIST" << endl;

    cout << "\n1. Insert at Beginning: SongA" << endl;
    insertAtBeginning("SongA");
    display();

    cout << "\n2. Insert at End: SongC" << endl;
    insertAtEnd("SongC");
    display();

    cout << "\n3. Insert SongB after SongA" << endl;
    insertAfter("SongA", "SongB");
    display();

    cout << "\n4. Count Songs" << endl;
    cout << "Number of songs = " << countSongs() << endl;

    cout << "\n5. Insert SongD at Beginning" << endl;
    insertAtBeginning("SongD");
    display();

    cout << "\n6. Insert SongE at End" << endl;
    insertAtEnd("SongE");
    display();

    cout << "\n7. Delete First Song" << endl;
    deleteFirst();
    display();

    cout << "\n8. Insert SongF after SongC" << endl;
    insertAfter("SongC", "SongF");
    display();

    cout << "\n9. Insert SongG after SongX" << endl;
    insertAfter("SongX", "SongG");
    display();

    cout << "\n10. Final Count" << endl;
    cout << "Number of songs = " << countSongs() << endl;

    return 0;
}