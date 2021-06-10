#include<bits/stdc++.h>
using namespace std;

int n;
stack<int> st;

void subsetsPrint()
{
    stack<int> t;

    while(!st.empty())
    {
        t.push(st.top());
        st.pop();
    }
    while(!t.empty())
    {
        cout<<t.top()<<" ";
        st.push(t.top());
        t.pop();
    }
    cout<<endl;
}
void sumOfSubsets(int s,int lvl,int sum,int se[])
{
    if(s>sum)
        return;
    if(s==sum)
    {
        subsetsPrint();
        return;
    }
    for(int i=lvl; i<n; i++)
    {
        st.push(se[i]);
        sumOfSubsets(s+se[i],i+1,sum,se);
        st.pop();
    }
}


int main()
{
    cout<<"Enter total number of nodes= ";
    cin>>n;
    cout<<"Enter Nodes"<<endl;
    int se[n];
    for(int i=0; i<n; i++)
    {
        cin>>se[i];
    }
    int sum;
    cout<<"Enter sum= ";
    cin>>sum;
    sumOfSubsets(0,0,sum,se);
    return 0;
}
