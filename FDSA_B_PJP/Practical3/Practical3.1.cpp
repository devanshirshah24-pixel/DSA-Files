// Bubble Sort, Selection Sort and Insertion Sort

#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter the number of elements you want to enter:" << endl;
    cin >> n;

    int a[n];

    cout << "Enter the elements:" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int bubble[n], selection[n], insertion[n];

    for(int i = 0; i < n; i++)
    {
        bubble[i] = a[i];
        selection[i] = a[i];
        insertion[i] = a[i];
    }



    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(bubble[j] > bubble[j + 1])
            {
                swap(bubble[j], bubble[j + 1]);
            }
        }
    }

    cout << "\nBubble Sorted Array:" << endl;

    for(int i = 0; i < n; i++)
    {
        cout << bubble[i] << " ";
    }



    int minimum;

    for(int i = 0; i < n - 1; i++)
    {
        minimum = i;

        for(int j = i + 1; j < n; j++)
        {
            if(selection[j] < selection[minimum])
            {
                minimum = j;
            }
        }

        swap(selection[i], selection[minimum]);
    }

    cout << "\n\nSelection Sorted Array:" << endl;

    for(int i = 0; i < n; i++)
    {
        cout << selection[i] << " ";
    }



    for(int i = 1; i < n; i++)
    {
        int key = insertion[i];
        int j = i - 1;

        while(j >= 0 && insertion[j] > key)
        {
            insertion[j + 1] = insertion[j];
            j--;
        }

        insertion[j + 1] = key;
    }

    cout << "\n\nInsertion Sorted Array:" << endl;

    for(int i = 0; i < n; i++)
    {
        cout << insertion[i] << " ";
    }

    return 0;
}