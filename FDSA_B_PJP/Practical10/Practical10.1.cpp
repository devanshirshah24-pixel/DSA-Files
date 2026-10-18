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

    void insert(int registration)
    {
        int index = registration % SIZE;
        int start = index;

        while (table[index] != -1)
        {
            index = (index + 1) % SIZE;

            // Prevent infinite loop when table is full
            if (index == start)
            {
                cout << "Parking lot is full." << endl;
                return;
            }
        }

        table[index] = registration;
    }

    void display()
    {
        cout << "Final Parking Lot:" << endl;

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

    int vehicles[] = {101, 112, 123, 134, 145};

    int n = 5;

    for (int i = 0; i < n; i++)
    {
        h.insert(vehicles[i]);
    }

    h.display();

    return 0;
}