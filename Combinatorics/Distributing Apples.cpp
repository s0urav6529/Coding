#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=2e6+5;

ll fact[limit];

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

ll nCr(ll n,ll r){

    ll numerator= fact[n];
    ll denominator = mulmod(fact[r],fact[n-r]);
    return mulmod(numerator, Binary_expo(denominator,MOD-2));
}


int main(){
    fast;
    ll n , m;
    cin >> n >> m;


    fact[0] = 1;
    for(ll i=1;i<limit;i++){
         fact[i]=mulmod(fact[i-1],i);
    }

    cout<< nCr(m+n-1,n-1) <<endl;


    return 0;
}



