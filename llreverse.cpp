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
        next= NULL;
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
Node*revers(Node*head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    Node*smallinput=revers(head->next);
    Node*temp=smallinput;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head;
    head->next=NULL;
    return smallinput;
}
void print(Node*head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    Node*head=takeinput();
    head=revers(head);
    print(head);

}
