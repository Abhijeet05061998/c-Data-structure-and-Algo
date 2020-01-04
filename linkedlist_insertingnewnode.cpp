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
Node*takeinput()
{
    int data;
    cout<<"Enter the data in linked list:"<<endl;
    cin>>data;
    Node*head=NULL;
    Node*tail=NULL;
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
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
Node* insertNode(Node* head,int i,int data)
{
    Node *newNode=new Node(data);
    int count=0;
    Node*temp=head;
    if(i==0)
    {
        newNode->next=head;
        head-newNode;
        return head;
    }
    while(count<=i-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp!=NULL)
    {
        Node *a=temp->next;
        temp->next=newNode;
        newNode->next=a;
    }
    return head;
}
int length(Node *head)
{
    Node *temp=head;
  int   count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
        cout<<count;
        cout<<endl;
}
int main()
{
    Node *head=takeinput();
    cout<<"Before inserting node of linked linked list:"<<endl;
    print(head);
    cout<<"Size of linked list before inserting the new node:"<<endl;
    length(head);
    int i,data;
    cout<<"Enter the number that you want to insert:"<<endl;
    cin>>data;
    cout<<"After which node you want to insert the new node:"<<endl;
    cin>>i;
    head=insertNode(head,i,data);
    cout<<"After inserting node of linked linked list:"<<endl;
    print(head);
    cout<<"Size of linked list after inserting the new node:"<<endl;
    length(head);
}
