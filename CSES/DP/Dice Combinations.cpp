#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

constexpr ll MOD=1e9+7;

int main(){
    fast;
    int n;
    cin>>n;
    ll dp[n+1];

    for(int i=0;i<=n;i++) dp[i]=0;
    dp[0]=1;

    for(int i=1;i<=n;i++){

        for(int j=1;j<=6;j++){
            if(i<j) break;
            dp[i]=(dp[i]+dp[i-j])%MOD;
        }

    }
    cout<<dp[n]<<endl;
    return 0;
}

