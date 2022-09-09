#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
typedef unsigned long long int llu;

constexpr ll MOD=1e9+7;
const int limit=2e5+5;

ll Mod(ll x){
    return ((x%MOD + MOD)%MOD);
}


ll mulmod(ll a,ll b){
    return Mod(Mod(a)*Mod(b));
}

ll Binary_expo(ll a,ll b){
	ll res=1;
	while(b){

		if(b&1)
		res=mulmod(res,a);

		b/=2;
		a=mulmod(a,a);
	}
	return res%MOD;
}

int main(){
    fast;
    int tc;
    cin>>tc;
    while(tc--){
        ll a,b;
        cin>>a>>b;
        cout<<Binary_expo(a,b)<<endl;
    }
    return 0;
}


