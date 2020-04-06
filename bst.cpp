#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<typename T>
class bst
{
public:
    T data;
    bst*left;
    bst*right;

    bst(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
bst<int>*takeinput()
{
    int rootdata;
    cout<<"Enter the root data:"<<endl;
    cin>>rootdata;
    if(rootdata==-1)
    {
        return NULL;
    }
    bst<int>*root=new bst<int>(rootdata);
    queue<bst<int>*>pendingnode;
    pendingnode.push(root);
    while(pendingnode.size()!=0)
    {
        bst<int>*frontelement=pendingnode.front();
        pendingnode.pop();
        int leftchild;
        cout<<"Enter the left child of "<<frontelement->data<<endl;
        cin>>leftchild;
        if(leftchild!=-1)
        {
            bst<int>*child=new bst<int>(leftchild);
            frontelement->left=child;
            pendingnode.push(child);
        }
        cout<<"Enter the right child of "<<frontelement->data<<endl;
        int rightchild;
        cin>>rightchild;
        if(rightchild!=-1)
        {
            bst<int>*child=new bst<int>(rightchild);
            frontelement->right=child;
            pendingnode.push(child);
        }
    }
    return root;
}
int binarysearchtree(bst<int>*root,int n)
{
  if(root==NULL)
  {
      return 0;
  }
  if(root->data==n)
  {
      return root->data;
  }
  else if(n<root->data)
  {
     int a=binarysearchtree(root->left,n);
     if(a==n)
     {
         return true;
     }
  }
  else if(n>root->data)
  {
     int b =binarysearchtree(root->right,n);
     if(b==n)
     {
         return true;
     }
  }
  else
  {
    return false;
  }
}
void print(bst<int>*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data;
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
    bst<int>*root=takeinput();
    print(root);
    cout<<"Enter the element which you want to search:"<<endl;
    int n;
    cin>>n;
    cout<<binarysearchtree(root,n);
}
