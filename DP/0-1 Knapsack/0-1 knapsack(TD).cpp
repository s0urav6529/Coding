#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define el endl
#define push_back pb
#define make_pair mp
#define mod 1000000007
#define pi acos(-1.0)
#define mx 0
#define mn 10000000000000
#define first ft;
#define second snd;
#define inf 1e9
#define linf 1e18
#define eps 1e-9
using namespace std;
typedef vector<int> vi;
typedef vector<long> vl;
typedef map<int,int>mi;
typedef map<long,long>ml;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<long,long>pll;
using ll=long long;
using ld=long double;
ll val[10005];
ll wt[10005];
ll dp[1005][1005];
int main()
{
    fast;
    ll n,tw,v,w;
    cin>>n>>tw;
    for(int i=0;i<n;i++)
    {
        cin>>v>>w;
        val[i]=v,wt[i]=w;
    }
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=n;i++)for(int j=0;j<=tw;j++) if(i==0||j==0)dp[i][j]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=tw;j++)
        {
            if(i==0||j==0)dp[i][j]=0;
            if(wt[i-1]<=j) dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][tw]<<el;
    return 0;
}


