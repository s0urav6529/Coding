



/// solution blog : https://codeforces.com/blog/entry/14516

#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=1e6+5;

unordered_map<ll,ll>dp;

ll fibonacci(ll n){

    if(dp.count(n)) return dp[n];

    ll k = n/2;

    if(n&1){
        return dp[n] = ((fibonacci(k)*fibonacci(k+1)) % MOD + (fibonacci(k-1)*fibonacci(k))%MOD)%MOD;
    }
    else{
        return dp[n] = ((fibonacci(k)*fibonacci(k)) % MOD + (fibonacci(k-1)*fibonacci(k-1))%MOD)%MOD;
    }

}

int main(){
    fast;
    ll n;
    cin >> n;

    dp[0] = dp[1] = 1;

    cout<<(n == 0 ? 0: fibonacci(n-1)) <<endl;


    return 0;
}



