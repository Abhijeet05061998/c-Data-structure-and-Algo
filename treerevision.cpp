#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Treenode
{
public:
    T data;
    vector<Treenode<T>*>children;
    Treenode(T data)
    {
        this->data=data;
    }
};
Treenode<int>*takeinput()
{
    int rootdata;
    cout<<"Enter the root data:-"<<endl;
    cin>>rootdata;
    Treenode<int>*root=new Treenode<int>(rootdata);
    queue<Treenode<int>*>pendingnode;
    pendingnode.push(root);

    while(pendingnode.size()!=0)
    {
        Treenode<int>*frontelement=pendingnode.front();
        pendingnode.pop();
        int children;
        cout<<"Enter the no of children "<<frontelement->data<<":"<<endl;
        cin>>children;
        for(int i=0;i<children;i++)
        {
            int childnode;
            cout<<"Enter "<<i<<" th children of "<<frontelement->data<<endl;
            cin>>childnode;
            Treenode<int>*child=new Treenode<int>(childnode);
            frontelement->children.push_back(child);
            pendingnode.push(child);
        }
    }
    return root;
}
int countnode(Treenode<int>*root)
{
    int ans=1;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=countnode(root->children[i]);
    }
    return ans;
}
int sumofnodes(Treenode<int>*root)
{
    Treenode<int>*temp=root;
    int sum=root->data;
    for(int i=0;i<temp->children.size();i++)
    {
        sum+=sumofnodes(temp->children[i]);
    }
    return sum;
}
Treenode<int>*maximum(Treenode<int>*root)
{
    if(root==NULL)
    {
        return root;
    }
    Treenode<int>*maxim=root;
    for(int i=0;i<root->children.size();i++)
    {
        Treenode<int>*temp=maximum(root->children[i]);
        if(temp->data>maxim->data)
        {
          maxim=temp;
        }
    }
    return maxim;
}
void print(Treenode<int>*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++)
    {
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++)
    {
        print(root->children[i]);
    }
}
    int main()
    {
        Treenode<int>*root=takeinput();
        print(root);
        Treenode<int>*ans=maximum(root);
        if(root!=NULL)
        {
       cout<<countnode(root)<<endl;
       cout<<ans->data<<endl;
       cout<<sumofnodes(root)<<endl;
        }

    }
