#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define el endl;
//#define push_back pb;
#define make_pair mp;
#define mod 1000000007;
#define pi acos(-1.0);
#define mx 0;
#define mn 10000000000000;
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
ll a[100005];
ll dp[1005][1005];
vl v;
ll solve(ll n,ll s1)
{
    if(n==0&&s1>0)return 0;
    if(s1==0)return 1;
    if(dp[n][s1]!=-1)return dp[n][s1];
    if(a[n-1]<=s1)return dp[n][s1]=dp[n-1][s1-a[n-1]]+dp[n-1][s1];
    else return dp[n][s1]=dp[n-1][s1];
}
int main()
{
    fast;
    ll n,totalsum=0,dif;
    cin>>n>>dif;
    for(ll i=0;i<n;i++)cin>>a[i],totalsum+=a[i];
    ll s1=(dif+totalsum)/2;
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<=n;i++)
    for(ll j=0;j<=s1;j++){if(i==0&&j>0)dp[i][j]=0;if(j==0)dp[i][j]=1;}
    for(ll i=1;i<=n;i++)
    for(ll j=1;j<=s1;j++)
    {
        if(a[i-1]<=j)dp[i][j]=dp[i-1][j-a[i-1]]+dp[i-1][j];
        else dp[i][j]=dp[i-1][j];
    }
    //cout<<solve(n,s1)<<endl;
    cout<<dp[n][s1]<<endl;
    return 0;
}

