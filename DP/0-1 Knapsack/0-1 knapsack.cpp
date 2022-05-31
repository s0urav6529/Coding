#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll=long long;
using dd=double;
ll wt[1005];
ll val[1005];
ll dp[1005][1005];
ll knapsack(ll n,ll KW)
{
    if(n==0||KW==0)return 0;
    if(dp[n][KW]!=-1)return dp[n][KW];
    if(wt[n-1]<=KW)
    {
        return dp[n][KW]=max(val[n-1]+knapsack(n-1,KW-wt[n-1]),knapsack(n-1,KW));
    }
    else return dp[n][KW]=knapsack(n-1,KW);
}
int main()
{
    fast;
    ll n,KW;
    cin>>n;
    for(ll i=0;i<n;i++)cin>>wt[i];
    for(ll i=0;i<n;i++)cin>>val[i];
    cin>>KW;
    memset(dp,-1,sizeof(dp));
    cout<<knapsack(n,KW)<<endl;
    return 0;
}

