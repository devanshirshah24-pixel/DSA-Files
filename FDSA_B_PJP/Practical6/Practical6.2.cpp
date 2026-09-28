#include<iostream>
#include<string>
using namespace std;

class Node
{
    public:
    string page;
    Node* next;

    Node(string p)
    {
        page=p;
        next=nullptr;
    }
};

class Browserhistory
{
    private:
    Node* top;

    public:
    Browserhistory(string fpage)
    {
        top=new Node(fpage);
    }

    void visit(string page)
    {
        Node* newNode=new Node(page);
        newNode->next=top;
        top=newNode;

        cout<<"Current Page"<<top->page<<endl;
    }

    void back()
    {
        if(top->next==nullptr)
        {
            cout<<"No history record is there"<<endl;
            cout<<"Current Page: "<<top->page<<endl;
            return;
        }

        Node* temp=top;
        top= top->next;
        delete temp;

        cout<<"Current Page: "<<top->page<<endl;
    }
     ~Browserhistory()
        {
           while(top!= nullptr)
           {
            Node* temp=top;
            top = top->next;
            delete temp;
           }
        }
};


int main()
{
    string fpage;
    int operations;

    cout<<"Enter the first Page:"<<endl;
    cin>>fpage;

    Browserhistory browser(fpage);

    cout<<"Enter the number of operations"<<endl;
    cin>>operations;

    for(int i=0;i<operations;i++)
    {
        char operation;
        cin>>operation;

        if(operation== 'V')
        {
            string page;
            cin>>page;
            browser.visit(page);
        }else if(operation=='B')
        {
            browser.back();
        }else
        cout<<"Invalid operation"<<endl;
    }
    return 0;
}