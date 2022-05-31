#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

constexpr ll MOD=998244353;
const int limit=200005;

void init_code(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

}
int n;
int a[limit];
ll dp[limit][4][4];

ll rec(int pos,int rem,int bef){

    if(pos>n){
        if(rem!=bef) return 1;
        else return 0;
    }

    if(dp[pos][rem][bef]!=-1)
        return dp[pos][rem][bef];

    ll ans=0;

    ans+=(rec(pos+1,rem^a[pos],bef))%MOD;

    if(rem!=bef)
        ans+=(rec(pos+1,a[pos],rem)%MOD);

    return dp[pos][rem][bef]=ans%MOD;

}

void run_case(){
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        a[i]%=2;
    }
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=2;j++)
            for(int k=-1;k<=2;k++) dp[i][j][k]=-1;
    cout<<rec(2,a[1],-1)<<endl;

    return;
}

int main(){
    fast;
    int tc=1;
    cin>>tc;
    while(tc--) run_case();
    return 0;
}



