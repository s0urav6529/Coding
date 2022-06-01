#include<bits/stdc++.h>
using namespace std;
int ara[1000005];
int prime[1000005];
int a[10005];int SIZE=0;
void seive(int n)
{
    ara[1]=1;
    for(int i=2;i*i<=n;i++)
    {
        if(ara[i]==0)
        {
            for(int j=i*i;j<=n;j+=i)ara[j]=1;
        }
    }
    int j=0;
    for(int i=2;i<=n;i++)
        if(!ara[i])
            prime[j++]=i;
}
void primefactor(int n)
{
    int p=n,j=0;
    for(int i=0;prime[i]*prime[i]<=n;)
    {
        if(p%prime[i]==0){
            a[j++]=prime[i];
            p/=prime[i];
            SIZE++;
        }
        else i++;
    }
    if(p>1)
        a[j]=p,SIZE++;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    seive(n);
    primefactor(n);
    for(int i=0;i<SIZE;i++)cout<<a[i]<<" ";
    return 0;
}
