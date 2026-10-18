#include <iostream>
using namespace std;

#define SIZE 10

class HashTable
{
    int table[SIZE];

public:

    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = -1;
        }
    }

    int hash1(int key)
    {
        return key % SIZE;
    }

    int hash2(int key)
    {
        return 7 - (key % 7);
    }

    void insert(int key)
    {
        int index1 = hash1(key);
        int jump = hash2(key);

        for (int i = 0; i < SIZE; i++)
        {
            int index = (index1 + i * jump) % SIZE;

            if (table[index] == -1)
            {
                table[index] = key;
                return;
            }
        }

        cout << "Hash table is full. Cannot insert "
             << key << endl;
    }

    void display()
    {
        cout << "Final Hash Table:" << endl;

        for (int i = 0; i < SIZE; i++)
        {
            cout << "Slot " << i << ": ";

            if (table[i] == -1)
                cout << "Empty";
            else
                cout << table[i];

            cout << endl;
        }
    }
};

int main()
{
    HashTable h;

    int ids[] = {101, 111, 121, 131, 141, 151};

    int n = 6;

    for (int i = 0; i < n; i++)
    {
        h.insert(ids[i]);
    }

    h.display();

    return 0;
}