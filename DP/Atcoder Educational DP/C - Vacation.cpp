#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
int n;
ll a[300005];
ll dp[300005];
int main()
{
    fast;
    //read;
    //out;
    int tc=1;
    //cin>>tc;
    for(int z=1;z<=tc;z++)
    {
        cin>>n;
        for(int i=1;i<=n*3;i++) cin>>a[i];
        dp[1]=a[1],dp[2]=a[2],dp[3]=a[3];
        for(int i=4;i<=n*3;i++)
        {
            if(i%3==1) dp[i]=a[i]+max(dp[i-1],dp[i-2]);
            else if(i%3==2) dp[i]=a[i]+max(dp[i-2],dp[i-4]);
            else if(i%3==0) dp[i]=a[i]+max(dp[i-4],dp[i-5]);
        }
        cout<<max(dp[n*3],max(dp[n*3-1],dp[n*3-2]));
    }
    return 0;
}


