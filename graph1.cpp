#include<iostream>
#include<queue>
using namespace std;
void DFSprint(int**edge,int n,int sv,bool*visited)
{
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(edge[sv][i]==1)
        {
        if(visited[i])
        {
            continue;
        }
        print(edge,n,i,visited);
        }
     }
}
void printBFS(int**edge,int n,int sv)
{
    queue<int>pendingvertices;
    bool*visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    pendingvertices.push(sv);
    visited[sv]=true;
    while(pendingvertices.size()!=0)
    {
        int currentvertex=pendingvertices.front();
        pendingvertices.pop();
        cout<<currentvertex<<endl;
        for(int i=0;i<n;i++)
        {
            if(i==currentvertex)
            {
                continue;
            }
            if(edge[currentvertex][i]==1&&  !visited[i])
            {
                pendingvertices.push(i);
                visited[i]=true;
            }
        }
    }
}
int main()
{
    int n;
    int e;
    cin>>n>>e;
    int**edge=new int*[n];
    for(int i=0;i<n;i++)
    {
        edge[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edge[i][j]=0;
        }
    }
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin>>f>>s;
        edge[f][s]=1;
        edge[s][f]=1;
    }
    bool*visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    cout<<"DFS:"<<endl;
    print(edge,n,0,visited);

    cout<<"BFS:"<<endl;
    printBFS(edge,n,0);
}
