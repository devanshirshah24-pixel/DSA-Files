#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of Book ID's you want to enter:"<<endl;
    cin>>n;

    int a[n];
    cout<<"Enter the number of Book ID's:"<<endl;
    for(int i=0;i<n ; i++)
    {
        cin>>a[i];
    }


    for(int i=0; i<n;i++)
    {
            int count=0;
        for (int j=0;j<n;j++)
        {
            if(a[j]==a[i])
            {
               count++;
            }
        }
    

    bool alreadyprinted=false;

        for(int k=0;k<i ;k++)
    {
       if(a[k]==a[i])
       {
        alreadyprinted=true;
        break;
       }
    }
    
    

    if(count > 1 && !alreadyprinted)
    {
            cout<<a[i]<<" ";
    }
    }
    
    return 0;
}