#include<iostream>
#include<bits/stdc++.h>
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
Node *takeinput()
{
    int data;
    cout<<"Enter the element in node:"<<endl;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data!=0)
    {
        Node *newNode=new Node(data);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}
void print(Node *head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node *deleteNode(Node *head,int i)
{
    Node*temp=head;
    int count=0;
    if(i==0)
    {
        head=head->next;
        return head;
    }
    while(count<i-1&&temp!=NULL)
    {

        temp=temp->next;
        count++;
    }
    if(temp->next==NULL||temp==NULL)
        return head;
    if(count==i-1)
    {
       Node *a=temp->next;
       Node *b=a->next;
       delete a;
        temp->next = b;
        return head;
    }
}
int main()
{
    Node *head=takeinput();
    cout<<"Before deleting element present in node:"<<endl;
    print(head);
    int i;
    cout<<"Enter the index of node which you want to delete:"<<endl;
    cin>>i;
    deleteNode(head,i);
    cout<<"After deleting element present in node:"<<endl;
    print(head);
}

