#include<bits/stdc++.h>
using namespace std;
#define edge pair<int,int>
vector <pair<int,edge>>graph;
vector <pair<int,edge>>mst;
vector<int> p;
void addWeight(int u,int v,int w)
{
    graph.push_back(make_pair(w,edge(u,v)));
}
void makeSet()
{
    for(int i=0; i<graph.size(); i++)
        p.push_back(i);
}
int findSet(int i)
{
    if(p[i]==i)
        return i;
    else
        return findSet(p[i]);
}
void Union(int u,int v)
{
    p[u]=p[v];
}
void kruskal()
{
    makeSet();
    int fp,sp;
    sort(graph.begin(),graph.end());
    for(int i=0; i<graph.size(); i++)
    {
        fp=findSet(graph[i].second.first);
        sp=findSet(graph[i].second.second);
        if(fp!=sp)
        {
            mst.push_back(graph[i]);
            Union(fp,sp);
        }
    }
}
void mst_print()
{
    cout<<"Edge\tWeight"<<endl;
    for(int i=0; i<mst.size(); i++)
    {
        cout<<mst[i].second.first<<"--"<<mst[i].second.second<<" :\t"<<mst[i].first<<endl;
    }
}
int main()
{
    /*int n,u,v,w;
    cout<<"Enter total number of edges:"<<endl;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>u>>v>>w;
        addWeight(u,v,w);
    }*/
    addWeight(1, 2, 3);
    addWeight(1, 3, 2);
    addWeight(2, 3, 1);
    addWeight(2, 6, 5);
    addWeight(3, 5, 4);
    addWeight(3, 4, 4);
    addWeight(1, 5, 4);
    addWeight(4, 5, 6);

    kruskal();
    mst_print();
}
