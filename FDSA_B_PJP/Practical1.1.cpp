#include<iostream>
using namespace std;

int main()
{
    int n;
cout<<"Enter the number of items:"<<endl;
cin>>n;

string a[n];

cout<<"Enter the items:"<<endl;
for(int i=0; i<n ; i++)
{
    cin>>a[i];
}

int h;
cout<<"Enter the number of hours:"<<endl;
cin>>h;

int k=h%n;

cout<<"DIsplay the final output:"<<endl;
for (int i=0;i<n; i++)
{
cout<<a[(k+i)%n]<<" ";
}
return 0;
}