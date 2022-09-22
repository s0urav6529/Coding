
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=1e6+5;

ll Get(char c){
    return (c-'a'+1);
}

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

    string s , p;
    cin >> s >> p;
    int n=s.size() , m=p.size();

    ll hash1[n+5] , hash2[n+5] , P = 31 ;

    /// for power & modulu invers
    ll power_val[max(n,m)+5] , invers_val[max(n,m)+5];

    power_val[0] = 1,invers_val[0]  = 1;

    for(int i=1 ; i<= max(n,m) ; i++) {

        power_val[i] = mulmod( power_val[i-1] , P);

        invers_val[i] = Binary_expo( power_val[i] , MOD-2);

    }


    /// hash for s
    hash1[-1] = 0;

    for(int i=0;i<n;i++){

        hash1[i] = mulmod( Get(s[i]), power_val[i]);

        hash1[i] = (hash1[i] + hash1[i-1]) % MOD;
    }

    ///hash of p
    hash2[-1] = 0;

    for(int i=0;i<m;i++){

        hash2[i] = mulmod( Get(p[i]), power_val[i]);

        hash2[i] = ( hash2[i] + hash2[i-1]) % MOD;
    }

    /// Binary search on length
    ll l = 1 , r = min(n,m)  , ans = 0 , id=0;

    while(l<=r){

        ll mid = l+ (r-l)/2;

        set<ll>st;

        for(int i=0 ; (i+mid-1) < n ;i++){

            ll h1 = ( hash1 [i + mid -1] - hash1 [i-1] ) % MOD ;

            if(i  > 0) h1 = mulmod(h1 , invers_val[i]);

            st.insert(h1);
        }

        bool ok=false;

        for(int i=0 ; (i+mid-1) < m ;i++){

            ll h2 = ( hash2 [i + mid -1] - hash2 [i-1] ) % MOD ;

            if(i  > 0) h2 = mulmod(h2 , invers_val[i]);

            if(st.count(h2)>0){
                ok=true;
                break;
            }
        }

        if(ok){
            ans = max(ans,mid);
            l=mid+1;
        }
        else r=mid-1;

    }
    cout << ans <<endl;

    return 0;
}



