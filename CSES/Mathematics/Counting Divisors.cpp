#include<bits/stdc++.h>
using namespace std;

const int limit=1e6+5;

int ara[limit];
int prime[limit];

void seive(int n)
{
    ara[1]=1;
    for(int i=2;i*i<=n;i++)
    {
        if(ara[i]==0)
        {
            for(int j=i*i;j<=n;j+=i)ara[j]=1;
        }
    }int j=0;for(int i=2;i<=n;i++)if(!ara[i])prime[j++]=i;
}

int countdivisor(int n)
{
    int divisor=1;
    for(int i=0;prime[i]*prime[i]<=n;i++)
    {
        int cnt=1;
        while(n%prime[i]==0){
            cnt++;
            n/=prime[i];
        }
        divisor*=cnt;
    }
    if(n>1) divisor*=2;
    return divisor;

    ///including 1 and n itself
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    seive(1e6+5);
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        cout<<countdivisor(n)<<endl;
    }

    return 0;
}


