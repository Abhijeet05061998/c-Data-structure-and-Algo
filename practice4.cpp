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
    cout<<"Enter the element in linked list:"<<endl;
    cin>>data;
    Node*head=NULL;
    Node*tail=NULL;
    while(data!=0)
    {
        Node*newNode=new Node(data);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else{
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
Node *insertNode(Node *head,int i,int data)
{
    Node*newNode=new Node(data);
    Node*temp=head;
    int count=0;
    if(i==0)
    {
        newNode->next=head;
        head=newNode;
        return head;

    }
    while(temp!=NULL&&count<=i-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp!=NULL)
    {
        Node*a=temp->next;
        temp->next=newNode;
        newNode->next=a;
    }
    return head;
}
int main()
{
    Node*head=takeinput();
    cout<<"Element present in linked list before inserting:"<<endl;
    print(head);
    int i,data;
    cout<<"Enter the index and element of linked list:"<<endl;
    cin>>i>>data;
    head=insertNode(head,i,data);
    cout<<"Element present in linked list after inserting new node:"<<endl;
    print(head);
}
