#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,weight,in;
    ///n=4;
    ///weight=5;
    cout<<"Enter number of elements(n) and max weight(w)\nn:: ";
    cin>>n;
    cout<<"w:: ";
    cin>>weight;
    int v[n+1][weight+1];
    int wi[n+1];
    int b[n+1];
    /***
    int wi[]={0,2,3,4,5};
    int b[]={0,3,4,5,6};
    */
    cout<<"Enter elements:"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<"Weight"<<i<<":: ";
        cin>>in;
        wi[i]=in;
        cout<<"Benefit"<<i<<":: ";
        cin>>in;
        b[i]=in;
    }
    for(int w=0; w<=weight; w++)
        v[0][w]=0;
    for(int i=0; i<=n; i++)
        v[i][0]=0;
    for(int i=1; i<=n; i++)
        for(int w=0; w<=weight; w++)
        {
            if(wi[i]<=w)
                v[i][w]=(b[i]+v[i-1][w-wi[i]]>v[i-1][w])?b[i]+v[i-1][w-wi[i]]:v[i-1][w];
            else
                v[i][w]=v[i-1][w];
        }

    /*cout<<"\nKnapsack Table:"<<endl;
    for(int i=0; i<=n; i++)
    {
        for(int w=0; w<=weight; w++)
        {
            cout<<v[i][w]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
*/
    stack <int> s;
    int i=n;
    int k=weight;
    while(i>0)
    {
        if(v[i][k]!= v[i-1][k])
        {
            s.push(i);
            k=k-wi[i];
        }
        i--;
    }
    cout<<"Items in knapsack::"<<endl;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\nTotal profit:: "<<v[n][weight]<<endl;
    return 0;
}
