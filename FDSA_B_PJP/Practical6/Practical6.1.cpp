#include<iostream>
using namespace std;

class Stack{
    private:
    int arr[100];
    int capacity;
    int top;

    public:
    Stack(int n)
    {
        capacity=n;
        top=-1;
    }

    void push(int value)
    {
        if(top==capacity-1)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }

        top++;
        arr[top]=value;
        cout<<"Top array:"<<arr[top]<<endl;

    }

    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack Underflow"<<endl;
            return;
        }

        cout<<"Top array: "<<arr[top]<<endl;
        top--;

    }

};

int main()
{
    int n,operations;

    cout<<"Enter the capacity of books "<<endl;
    cin>>n;

    Stack s(n);

    cout<<"Enter the operations:";
    cin>>operations;

    for(int i=0;i<operations;i++)
    {
        char operation;
        cin>>operation;

        if(operation=='P')
        {
            int tray;
            cin>>tray;
            s.push(tray);
        }else if(operation=='O')
        {
            s.pop();
        }else
        cout<<"Invalid Operation"<<endl;

    }
}