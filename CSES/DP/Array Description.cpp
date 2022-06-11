#include<bits/stdc++.h>
using namespace std;

constexpr int mod=1e9+7;
const int limit=1000005;


int main(){

    int n,m;
    cin>>n>>m;
    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int dp[n+2][m+2];

    memset(dp,0,sizeof dp);

    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){

            if(i==1){

                if(a[i]==0 || a[i]==j) dp[i][j]=1;   ///1st pos i can place here j
                else dp[i][j]=0;
            }
            else{

                if(a[i]==0 || a[i]==j){  ///ith pos i can place here j

                    int ans=dp[i-1][j]%mod;    ///is i-1 th position filled by x,x+1 or x-1
                    ans=(ans+dp[i-1][j+1])%mod;
                    ans=(ans+dp[i-1][j-1])%mod;
                    dp[i][j]=ans%mod;

                }
                else dp[i][j]=0;
            }

        }
    }

    long long int ans=0;
    for(int i=1;i<=m;i++) ans=(ans+dp[n][i])%mod;
    cout<<ans<<endl;


    return 0;
}
