#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
ll dp[100005];
ll a[100005];
ll n;
ll solution(int i)
{
    if(i>n) return INT_MAX;
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    return dp[i]=min(abs(a[i]-a[i+1])+solution(i+1),abs(a[i]-a[i+2])+solution(i+2));
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
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        cout<<solution(1)<<endl;

        //cout<<"Case "<<z<<": "<<ans<<endl;
    }
    return 0;
}


