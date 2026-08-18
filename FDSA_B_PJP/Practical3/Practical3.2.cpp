#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements you want to enter:" << endl;
    cin >> n;

    int arr[n];
    
     cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

   
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count0++;
        else if (arr[i] == 1)
            count1++;
        else
            count2++;
    }

    int index = 0;

    while (count0 > 0)
    {
        arr[index] = 0;
        index++;
        count0--;
    }

   
    while (count1 > 0)
    {
        arr[index] = 1;
        index++;
        count1--;
    }

  
    while (count2 > 0)
    {
        arr[index] = 2;
        index++;
        count2--;
    }

    
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}