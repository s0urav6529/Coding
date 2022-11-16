
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=1e6+5;

int main(){
    fast;
    ll n, k;
    cin >> n >> k;

    vector<ll>p(k);
    for(int i=0;i<k;i++) cin >> p[i];

    sort(p.begin(),p.end());

    ll dp[n+5];
    dp[0] = 0;

    string s="";
    for(int i=1;i<=n;i++){

        dp[i] = 0;
        for(int j=0;j<k;j++){

            if(i-p[j] < 0) break;

            if(dp[i-p[j]] == 0) {
                s+="W" , dp[i] = 1;
                break;
            }

        }
        if(dp[i] == 0) s+="L";
    }

    cout<<s<<endl;

    return 0;
}


