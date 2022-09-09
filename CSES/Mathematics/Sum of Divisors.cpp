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
    ll  n;
    cin>>n;

    ll prev=1 , ans=0 , MOD_inv=Binary_expo(2ll,MOD-2);

    while(1){

        ll next=(n / (n/prev))+1;

        ll  s1= ( mulmod(next, next-1) * MOD_inv ) % MOD;
        ll  s2= ( mulmod(prev, prev-1) * MOD_inv ) % MOD;

        ll add= mulmod(s1-s2 , n/prev);

        ans= (ans + add) % MOD;

        if(next>n) break;

        prev=next;
    }

    cout<<ans<<endl;

    return 0;
}





