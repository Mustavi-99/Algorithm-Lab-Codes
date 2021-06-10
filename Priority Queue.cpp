#include<bits/stdc++.h>
using namespace std;
int que[100],t=-1;

int top()
{
    int m=que[0];
    for(int i=1;i<=t;i++)
        if(m<que[i])
            m=que[i];
    return m;
}

void push(int k)
{
    if(t==100)
        cout<<"Overflow"<<endl;
    else
    {
        t++;
        que[t]=k;
    }
}

void pop()
{
    if(t==-1)
        cout<<"Underflow"<<endl;
    else
    {
        int m_i=0;
        for(int i=1;i<=t;i++)
            if(que[m_i]<que[i])
                m_i=i;
        for(int i=m_i;i<t;i++)
            que[i]=que[i+1];
        t--;
    }
}
bool isEmpty()
{
    if(t==-1)
        return true;
    return false;
}
int main()
{
    push(8);
    push(3);
    push(10);
    push(1);
    push(6);
    push(4);
    push(7);
    push(14);
    push(13);
    while(!isEmpty())
    {
        cout<<top()<<" ";
        pop();
    }
    return 0;
}
