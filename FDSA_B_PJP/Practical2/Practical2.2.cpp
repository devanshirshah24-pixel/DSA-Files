#include<iostream>
#include<string>
using namespace std;


int iterativeBinary(string code[],int n,string t)
{
    int low=0;
    int high=n-1;

    while(low<= high)
    {
        int mid=(low+high)/2;

        if(code[mid]==t)
        {
            return mid;
        }
        else if(code[mid]<t)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}

int recursiveBinary(string code[],string t,int low,int high)
{
    if(low>high)
    {
        return -1;
    }
     
    int mid=(low+high)/2;

    if(code[mid]==t)
    {
        return mid;
    }
    else if (code[mid]<t)
    {
        return recursiveBinary( code, t,mid+1, high);
    }
    else
    {
        return recursiveBinary( code, t,low, mid-1);
    }
    
}
int main()
{
    int n;
    cout<<"Enter the number of book codes:"<<endl;
    cin>>n;

    string code[n];
    cout<<"Enter the sorted book codes:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>code[i];
    }
     
    string t;
    cout<<"Enter the target code:"<<endl;
    cin>>t;

    int iter = iterativeBinary(code,n,t);

    if(iter!=-1)
    {
        cout<<"Itereative Binary Search found at position "<<iter+1<<endl;
    }
    else
    {
        cout<<"Iterative Binary Search not found"<<endl;
    }

    int index=0;

    int recur = recursiveBinary(code,t,index,n-1);
     if(recur!=-1)
    {
        cout<<"Recursive Binary Search found at position "<<recur+1<<endl;
    }
    else
    {
        cout<<"Recursive Binary Search not found "<<endl;
    }

}