#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define mod 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
int main()
{
    fast;
    //read;
    //out;
    int tc=1;
    //cin>>tc;
    for(int z=1;z<=tc;z++)
    {
        int h,w;
        cin>>h>>w;
        char a[h+5][w+5];
        int dp[h+5][w+5];
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++) cin>>a[i][j],dp[i][j]=0;
        }
        dp[1][1]=1;
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++)
            {
                if(a[i][j]=='#') continue;
                else if(i==1 && j==1) continue;
                else if(i==1) dp[i][j]=(dp[i][j]%mod + dp[i][j-1]%mod)%mod;
                else if(j==1) dp[i][j]=(dp[i][j]%mod + dp[i-1][j]%mod)%mod;
                else dp[i][j]=(dp[i-1][j]%mod + dp[i][j-1]%mod)%mod;
            }
        }
        cout<<dp[h][w];
        //cout<<"Case "<<z<<": "<<ans<<endl;
    }
    return 0;
}


