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
int length(Node*head)
{
    Node*temp=head;
    int count=0;
    while(temp!=NULL)
    {

        temp=temp->next;
        count++;
    }
    return count;
}
void sumofnode(Node*head,int n)
{
    Node*temp=head;
    int ans=0;
    int len=length(head);
    ans=len-n;
    int sum=0;
    while(ans--)
    {
        temp=temp->next;
    }
    while(n--)
    {
        sum=sum+temp->data;
        temp=temp->next;
    }
    cout<<sum;
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
    int i;
    cin>>i;
    sumofnode(head,i);
}
