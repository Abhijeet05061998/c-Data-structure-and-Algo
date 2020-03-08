#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node*next;

    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
Node*takeinput()
{
    int data;
    cin>>data;
    Node*head=NULL;
    Node*tail=NULL;
    while(data!=-1)
    {
        Node*newnode=new Node(data);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}
void print(Node*head)
{
    Node*temp=head;
    if(temp==NULL)
    {
        return;
    }
    print(temp->next);
    cout<<temp->data<<" ";
}
void findNode(Node*head,int i)
{
    Node*temp=head;
    int count=0;
    while(temp!=NULL)
    {
        if(temp->data==i)
        {
            cout<<count;
        }
         count++;
        temp=temp->next;
    }
}
int main()
{
    Node*head=takeinput();
    print(head);
    cout<<endl;
    int i;
    cin>>i;
    findNode(head,i);
}
