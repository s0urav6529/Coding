#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);


void solution()
{
    int n,ans=1;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    int dp[n+1][1005];  ///1005 because differnce canbe +/-

    for(int i=1;i<=n;i++)
        for(int j=1;j<=500;j++) dp[i][j]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int dif=a[i]-a[j];
            if(dp[i][dif]>1)
            {
                dp[j][dif]=dp[i][dif]+1;
            }
            else dp[j][dif]=2; ///cause 2  always possible if n>1
            ans=max(ans,dp[j][dif]);
        }
    }
    cout<<ans<<endl;

    return;
}
int main()
{
    fast;
    //read;
    //out;
    int tc=1;
    //cin>>tc;
    while(tc--)
        solution();
    return 0;
}



