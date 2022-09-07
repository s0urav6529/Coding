
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=1e5+5;

ll Mod(ll x){
    return ((x%MOD + MOD)%MOD);

}


ll mulmod(ll a,ll b){
    return Mod(Mod(a)*Mod(b));

}

ll Binary_expo(ll a,ll n){

	ll res=1;
	while(n){

		if(n&1)
		res=mulmod(res,a);

		n/=2;
		a=mulmod(a,a);
	}
	return res%MOD;
}



int main(){
    fast;

    int n; cin >> n;

    vector<int>div(limit,0);

    int a[n+5];

    for(int i=1;i<=n;i++){

        cin >> a[i];

        for(int j=2;j*j<=a[i];j++){

            if(a[i]%j==0 && a[i]/j>=j) div[j]++;

        }

    }

    ll ans=0;

    for(int i=1;i<=n;i++){

        ll d;

        if(a[i]==1){
            d=n;
        }
        else d=div[a[i]];

        ll temp=Binary_expo(2ll,d);

        ans=(ans+temp-1)%MOD;

    }
    cout<<ans<<endl;


    return 0;
}


