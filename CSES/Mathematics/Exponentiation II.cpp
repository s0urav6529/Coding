#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
typedef unsigned long long int llu;

const int limit=2e5+5;

ll Mod(ll x, ll MOD){
    return ((x%MOD + MOD)%MOD);
}


ll mulmod(ll a, ll b , ll MOD){
    return Mod(Mod(a,MOD)*Mod(b,MOD),MOD);
}

ll Binary_expo(ll a,ll b,ll MOD){
	ll res=1;
	while(b){

		if(b&1)
		res=mulmod(res,a,MOD);

		b/=2;
		a=mulmod(a,a,MOD);
	}
	return res%MOD;
}

int main(){
    fast;
    int tc;
    cin>>tc;
    while(tc--){
        ll a,b,c , M=1000000007;
        cin>>a>>b>>c;
        cout<<Binary_expo(a,Binary_expo(b,c,M-1),M)<<endl;
    }
    return 0;
}



