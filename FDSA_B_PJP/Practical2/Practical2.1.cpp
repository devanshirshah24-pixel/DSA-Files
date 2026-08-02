#include<iostream>
#include<string>
using namespace std;


int iterativesearch(string plates[],int n,string t)
    {
        for(int i=0;i<n;i++)
        {
            if(plates[i]==t)
            { 
                return i;
            }
        }
         return -1;
    }

int recursivesearch(string plates[],string t ,int index, int n)
{
    if(index==n)
    {
        return -1;
    }
    
    if(plates[index]==t)
    {
        return index;
    }

    return recursivesearch(plates, t, index+1, n);
}
int main()
{
    int n;
    cout<<"Enter the number of license plates:"<<endl;
    cin>>n;

    string plates[n];
    cout<<"Enter the license plates:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>plates[i];
    }
     
    string t;
    cout<<"Enter the target plate:"<<endl;
    cin>>t;

    int iter = iterativesearch(plates,n,t);
    if(iter!=-1)
    {
        cout<<"Itereative Search found at position "<<iter+1<<endl;
    }
    else
    {
        cout<<"Iterative Search not found"<<endl;
    }

    int index=0;
    int recur = recursivesearch(plates,t,index,n);
     if(recur!=-1)
    {
        cout<<"Recursive Search found at position "<<recur+1<<endl;
    }
    else
    {
        cout<<"Recursive Search not found "<<endl;
    }

}