#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
public:

    int data;
    Node *next;

    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
Node *takeinput()
{
    int data;
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

int length(Node*head)
{
    Node *temp=head;
    if(temp==NULL)
    {
        return 0;
    }
    else
    {
        return length(temp->next)+1;
    }
}
int main()
{
    Node *head=takeinput();
    cout<<length(head);
}
