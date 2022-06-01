#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,tc=1;
    cin>>tc;
    int maxn=100005;
    int a[maxn];
    for(int i=2;i<=maxn;i++) a[i]=i;
    for(int i=2;i*i<=maxn;i++)
    {
        if(a[i]==i)
        {
            for(int j=i*i;j<=maxn;j+=i)
            {
                if(a[j]==j) a[j]=i;
            }
        }
    }
    //for(int i=2;i<=30;i++) cout<<a[i]<<" ";
    while(tc--)
    {
        cin>>n;
        while(n>1)
        {
            cout<<a[n]<<" ";
            n=n/a[n];
        }
        cout<<endl;
    }
    return 0;
}
