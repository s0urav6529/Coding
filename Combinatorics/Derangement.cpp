
/// No of ways such that n distict items arrange that none of them occupies it's orginal position.

/// link : https://cp-algorithms.com/combinatorics/inclusion-exclusion.html#the-number-of-permutations-without-fixed-points-derangements

// Dn = n! * ( 1/0! - 1/1! + 1/2! - 1/3! ...... (-1)^n*1/n!)


#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
constexpr ll MOD=1e9+7;
const int limit=1e6+5;

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

int main(){
    fast;

    ll n;
    cin >> n;

    fact[0] = 1;

    for(ll i=1;i<=n;i++){
         fact[i]=mulmod(fact[i-1],i);
    }

    ll ans = 0;

    for(int i=0;i<=n;i++){

        ll mod_inv = Binary_expo(fact[i] , MOD-2);

        ll help = mulmod(fact[n] , mod_inv);

        if(i&1){

            ans = Mod(ans-help);

        }
        else {
            ans = Mod(ans+help);
        }

    }

    cout<< ans << endl;

    return 0;
}



