#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
int n,tw;
ll w[105];
ll v[105];
ll dp[105][100005];
ll solution(ll i,ll W)
{
    if(i>n) return 0;
    if(dp[i][W]!=-1) return dp[i][W];
    if(W>=w[i])
        return dp[i][W]=max(v[i]+solution(i+1,W-w[i]),solution(i+1,W));
    else return dp[i][W]=solution(i+1,W);
}
int main()
{
    fast;
    //read;
    //out;
    int tc=1;
    //cin>>tc;
    for(int z=1;z<=tc;z++)
    {
        memset(dp,-1,sizeof(dp));
        cin>>n>>tw;
        for(int i=1;i<=n;i++)
        {
            cin>>w[i]>>v[i];
        }
        cout<<solution(1,tw)<<endl;
        //cout<<"Case "<<z<<": "<<ans<<endl;
    }
    return 0;
}


