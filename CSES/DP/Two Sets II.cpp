#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int limit=200005;
constexpr int mod=1e9+7;

int main(){

    int n;
    cin>>n;
    int sum=(n*(n+1));
    if(sum%4) {
        cout<<0<<endl;
        return 0;
    }
    sum/=4;
    int dp[n+1][sum+1];

    memset(dp,0,sizeof dp);

    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++) {
            if(j==0) dp[i][j]=1;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++) {

            if(i>j) dp[i][j]=dp[i-1][j]%mod;
            else{
                dp[i][j]=((dp[i-1][j-i])%mod+(dp[i-1][j])%mod)%mod;

                dp[i][j]=dp[i][j]%mod;
            }
        }
    }

    ll x=dp[n][sum];
    ll z=500000004;
    cout<<(x*z)%mod<<endl;

    return 0;
}

