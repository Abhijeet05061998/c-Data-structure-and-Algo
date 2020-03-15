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
 int middle(Node*head)
{
    Node*temp=head;
    Node*slow=head->next;
    Node*fast=head->next;

    if(head==NULL||head->next==NULL)
    {
        return -1 ;
    }

    while(slow!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data;
}

int main()
{

    Node*head=takeinput();
    middle(head);
}
