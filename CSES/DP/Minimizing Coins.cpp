#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
using ll=long long;
using dd=double;


int main()
{
    fast;
    int n,x;
    cin>>n>>x;
    int a[n+1];
    for(int i=0;i<n;i++)cin>>a[i];

    int dp[n+2][x+2];

    memset(dp,-1,sizeof dp);

    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){

            if(i==0)dp[i][j]=1e9;

            if(j==0&&i>0)dp[i][j]=0;

            if(i==1&&j>0){
                if(j%a[i-1]==0)dp[i][j]=j/a[i-1];
                else dp[i][j]=1e9;
            }
        }
    }

    for(int i=2;i<=n;i++){
        for(int j=1;j<=x;j++){

            if(a[i-1]<=j)dp[i][j]=min(dp[i][j-a[i-1]]+1,dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    (dp[n][x]==1e9)?cout<<-1<<endl:cout<<dp[n][x]<<endl;
    return 0;
}

