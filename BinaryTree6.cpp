
//count the number of nodes
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template<typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode*left;
    BinaryTreeNode*right;
    BinaryTreeNode(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};
BinaryTreeNode<int>*takeinput()
{
    int rootdata;
    cout<<"Enter the root data:"<<endl;
    cin>>rootdata;
    if(rootdata==-1)
    {
        return NULL;
    }
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*>pendingNode;
    pendingNode.push(root);
    while(pendingNode.size()!=0)
    {
        BinaryTreeNode<int>*frontelement=pendingNode.front();
        pendingNode.pop();
        int leftchild;
        cout<<"Enter the left child of "<<frontelement->data<<endl;
        cin>>leftchild;
        if(leftchild!=-1)
        {
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(leftchild);
            frontelement->left=child;
            pendingNode.push(child);
        }
        int rightchild;
        cout<<"Enter the right child of "<<frontelement->data<<endl;
        cin>>rightchild;
        if(rightchild!=-1)
        {
            BinaryTreeNode<int>*child=new BinaryTreeNode<int>(rightchild);
            frontelement->right=child;
            pendingNode.push(child);
        }
    }
    return root;
}
 int InorderTraverse(BinaryTreeNode<int>*root)
 {
     if(root==NULL)
     {
         return 0;
     }
     InorderTraverse(root->left);
     cout<<root->data<<" ";
     InorderTraverse(root->right);
 }

 int preorderTraverse(BinaryTreeNode<int>*root)
 {
     if(root==NULL)
     {
         return 0;
     }
     cout<<root->data<<" ";
     preorderTraverse(root->left);
     preorderTraverse(root->right);

 }
 int postorderTraverse(BinaryTreeNode<int>*root)
 {
     if(root==NULL)
     {
         return 0;
     }
     postorderTraverse(root->left);
     postorderTraverse(root->right);
     cout<<root->data<<" ";
 }
void print(BinaryTreeNode<int>*root)
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
    BinaryTreeNode<int>*root=takeinput();
    print(root);
    cout<<"Inordered Traverse:";InorderTraverse(root);
    cout<<endl;
    cout<<"Preordered Traverse:";preorderTraverse(root);
    cout<<endl;
    cout<<"postordered Traverse:";postorderTraverse(root);

}
//1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1


