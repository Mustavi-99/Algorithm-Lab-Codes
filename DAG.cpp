#include<bits/stdc++.h>
using namespace std;
int node,edge,i,so,des,w,t,v,j,k;
vector<vector<int>> graph;
vector<char> c(1000);
vector<int> orig;
stack<int> sorted;
void DFS_visit(vector<vector<int>> g,int u,int n)
{

    c[u]='g';
    for(v=0;v<n;v++)
    {

        if(c[v]=='w'&&g[u][v]!=INT_MIN)
        {
            cout<<u<<"---";
            orig[v]=u;
            DFS_visit(g,v,n);
        }
    }
    c[u]='b';
    sorted.push(u);
}
void DFS(vector<vector<int>> g,int n)
{

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(g[i][j]!=INT_MIN)
            {
                c[i]='w';
                orig.push_back(NULL);
            }
        }
    }

    for(i=0;i<n;i++)
    {
        if(c[i]=='w')
            DFS_visit(g,i,n);
    }
}
int main()
{
    cout<<"Enter number of nodes= ";
    cin>>node;
    cout<<"Enter number of edges= ";
    cin>>edge;
    graph.resize(node);
    for(i=0;i<node;i++)
    {
        graph[i].resize(node);
    }
    for(i=0;i<node;i++)
        for(j=0;j<node;j++)
    {
        graph[i][j]=INT_MIN;
    }
    for(i=0;i<edge;i++)
    {
        cin>>so;
        cin>>des;
        //cin>>w;
        graph[so][des]=1;
    }
    DFS(graph,node);
    cout<<"Sorted :"<<endl;
    while(!sorted.empty())
    {
        cout<<sorted.top()<<" ";
        sorted.pop();
    }
    return 0;
}
/**
0 1 5
1 2 3
0 3 2
1 3 1
2 3 5
2 4 6
3 4 3
*/
