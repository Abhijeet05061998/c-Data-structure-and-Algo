#include<iostream>
#include<vector>
#include<queue>
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
  ~BinaryTree()
  {
      delete left;
      delete right;
  }
};
BinaryTree<int>*takeinput()
{
    int rootdata;
    cout<<"Enter the root data:"<<endl;
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
        cout<<"Enter the left child of "<<frontelement->data<<endl;
        int leftchild;
        cin>>leftchild;
        if(leftchild!=-1)
        {
            BinaryTree<int>*child=new BinaryTree<int>(leftchild);
            frontelement->left=child;
            pendingnode.push(child);
        }
        cout<<"Enter the right child of "<<frontelement->data<<endl;
        int rightchild;
        cin>>rightchild;
        if(rightchild!=-1)
        {
            BinaryTree<int>*child=new BinaryTree<int>(rightchild);
            frontelement->right=child;
            pendingnode.push(child);
        }
    }
    return root;
}
void print(BinaryTree<int>*root)
{
    if(root==NULL)
    {
        return ;
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
}
