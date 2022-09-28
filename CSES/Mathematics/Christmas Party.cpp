
/// properties : Derangement permutation

#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
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



