#include<bits/stdc++.h>
#include<math.h>
using namespace std;
bool isprime[1000005];
int prime[1000005];
void seive(int n)
{
    isprime[1]=true;
    int k=0;
    for(int i=2;i*i<=n;i++)
    {
        if(isprime[i]==0)
        {
            for(int j=i*i;j<=n;j+=i)isprime[j]=true;

            prime[k++]=i;
        }
    }
}
int summation(int n)
{
    int total=1;

    for(int i=0;prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {
            int cnt=1;
            while(n%prime[i]==0)cnt++,n/=prime[i];

            total*=((pow(prime[i],cnt)-1)/(prime[i]-1));
        }
    }
    if(n>1)  total*=(pow(n,2)-1)/(n-1);

    return total;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    seive(1000001);
    int tc=1;
    cin>>tc;
    while(tc--)
    {
        cin>>n;
        cout<<summation(n)+1<<endl;
    }
    return 0;
}


