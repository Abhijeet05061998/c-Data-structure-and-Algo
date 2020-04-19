#include<iostream>
#include<queue>
#include<vector>
using namespace std;
template<typename T>
class BinaryTree
{
public:
    T data;
    BinaryTree*left;
    BinaryTree*right;
    BinaryTree(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
BinaryTree<int>*takeinput()
{
    cout<<"Enter the root data:"<<endl;
    int rootdata;
    cin>>rootdata;
    if(rootdata==-1)
    {
        return NULL;
    }
    BinaryTree<int>*root=new BinaryTree<int>(rootdata);
    queue<BinaryTree<int>*>pendingnode;
    pendingnode.push(root);
    while(pendingnode.size()!=0)
    {
        BinaryTree<int>*frontelement=pendingnode.front();
        pendingnode.pop();

        cout<<"Enter the left node of "<<frontelement->data<<endl;
        int leftnode;
        cin>>leftnode;
        if(leftnode!=-1)
        {
            BinaryTree<int>*child=new BinaryTree<int>(leftnode);
            frontelement->left=child;
            pendingnode.push(child);
        }
        cout<<"Enter the right node of "<<frontelement->data<<endl;
        int rightnode;
        cin>>rightnode;
        if(rightnode!=-1)
        {
            BinaryTree<int>*child=new BinaryTree<int>(rightnode);
            frontelement->right=child;
            pendingnode.push(child);
        }
    }
    return root;
}

int findLeaf(BinaryTree<int>*root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        return 1;
    }
    return findLeaf(root->left)+findLeaf(root->right);
}
void print(BinaryTree<int>*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<":";
    if(root->left!=NULL)
    {
        cout<<"L"<<root->left->data;
    }
    if(root->right!=NULL)
    {
        cout<<"R"<<root->right->data;
    }
    cout<<endl;

    print(root->left);
    print(root->right);
}
int main()
{
    BinaryTree<int>*root=takeinput();
    print(root);
    cout<<"Total leaf of Binary Tree:"<<findLeaf(root);
}
