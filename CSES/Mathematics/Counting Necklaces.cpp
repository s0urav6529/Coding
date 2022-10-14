

/// Using Burnside's lemma or orbit counting theorem 

/// Blog : https://cp-algorithms.com/combinatorics/burnside.html#application-coloring-necklaces

#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=1e6+5;

ll Mod(ll x){
    return ((x%MOD + MOD)%MOD);
}

ll mulmod(ll a,ll b){
    return Mod(Mod(a)*Mod(b));
}

ll Binary_expo(ll a,ll p){

	ll res=1;
	while(p){

		if(p & 1)
		res=mulmod(res,a);
		p/=2;
		a=mulmod(a,a);
	}
	return res%MOD;
}


int main(){
    fast;

    ll n , m;
    cin >> n >> m;

    ll ans =0;

    for(ll i=0;i<n;i++){

        ll gcd = __gcd(i,n);

        ll help  =  Binary_expo(m,gcd);

        ans = (ans+help)%MOD;
    }

    ll Mod_inv = Binary_expo(n,MOD-2);

    ans = mulmod(ans,Mod_inv);

    cout<<ans<<endl;





    return 0;
}



