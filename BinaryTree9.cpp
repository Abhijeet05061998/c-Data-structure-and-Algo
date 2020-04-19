//count the total node from Tree
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<typename T>
class TreeNode
{
    public:
    T data;
    vector<TreeNode<T>*>children;
    TreeNode(T data)
    {
        this->data=data;
    }
};
TreeNode<int>*takeinput()
{
    cout<<"Enter the root data:"<<endl;
    int rootdata;
    cin>>rootdata;
    TreeNode<int>*root=new TreeNode<int>(rootdata);
    queue<TreeNode<int>*>pendingNode;
    pendingNode.push(root);

    while(pendingNode.size()!=0)
    {
        TreeNode<int>*frontElement=pendingNode.front();
        pendingNode.pop();
        cout<<"Enter the no of child node of "<<frontElement->data<<endl;
        int childNode;
        cin>>childNode;
        for(int i=0;i<childNode;i++)
        {
            int childdata;
            cout<<"Enter "<<i<<"th element of "<<frontElement->data<<endl;
            cin>>childdata;
            TreeNode<int>*child=new TreeNode<int>(childdata);
            frontElement->children.push_back(child);
            pendingNode.push(child);
        }
    }
    return root;

}
int height(TreeNode<int>*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ans=0;
    for(int i=0;i<root->children.size();i++)
    {
        int heightofnode=height(root->children[i]);
        {
            if(heightofnode>ans)
            {
                ans=heightofnode;
            }
        }
    }
    return ans+1;
}
int countNode(TreeNode<int>*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ans=1;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=countNode(root->children[i]);
    }
    return ans;
}

int sumofelement(TreeNode<int>*root)
{
    if(root==NULL)
    {
        return 0;
    }
    int sum=root->data;
    for(int i=0;i<root->children.size();i++)
    {
        sum+=sumofelement(root->children[i]);
    }
    return sum;
}
TreeNode<int>*maximum(TreeNode<int>*root)
{
   if(root==NULL)
   {
       return root;
   }
   TreeNode<int>*maxi=root;
   for(int i=0;i<root->children.size();i++)
   {
       TreeNode<int>*temp=maximum(root->children[i]);
       if(temp->data>maxi->data)
       {
           maxi=temp;
       }

   }
   return maxi;
}
void print(TreeNode<int>*root)
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
    TreeNode<int>*root=takeinput();
    print(root);
    TreeNode<int>*m=maximum(root);
    if(root!=NULL)
    {
    cout<<"Total height:"<<height(root)<<endl;
    cout<<"Total no of Node:"<<countNode(root)<<endl;
    cout<<"Sum of all Element:"<< sumofelement(root)<<endl;
    cout<<"Maximum value in Tree:"<<m->data<<endl;
    }
}
