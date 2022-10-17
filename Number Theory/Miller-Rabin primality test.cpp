

/// Miller-Rabin Primality test tells us that a number upto 1e18 is prime or no using farmet little thorem

/// https://cp-algorithms.com/algebra/primality_tests.html#miller-rabin-primality-test

/// https://cp-algorithms.com/algebra/primality_tests.html#deterministic-version

/// Time complexity = O(12*log(n))



#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
const int limit=1e6+5;

/// This 12 base gives me the 100% accuracy of this algo
ll base[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

ll Mod(ll x,ll MOD){
    return ((x%MOD + MOD)%MOD);
}

ll mulmod(ll a,ll b,ll MOD){
    return Mod(Mod(a,MOD)*Mod(b,MOD),MOD);
}

ll Binary_expo(ll a,ll p,ll MOD){

	ll res=1;
	while(p){

		if(p & 1)
		res=mulmod(res,a,MOD);
		p/=2;
		a=mulmod(a,a,MOD);
	}
	return res%MOD;
}

bool is_prime(ll n, ll a, ll s, ll d) {

    ll x = Binary_expo(a, d, n);

    if (x == 1 || x == n-1){
        return true;
    }

    for (int j = 1; j < s; j++) {
        x = (x*x) % n;

        if (x == n-1){
            return true;
        }
    }
    return false;
};

bool MillerRabin(ll n) { /// returns true if n is prime, else returns false.

    if (n < 2)
        return false;

    ll s = 0;
    ll d = n-1;

    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i=0;i<12;i++) {

        if (n == base[i]){
            return true;
        }

        if (is_prime(n, base[i], s, d)){
            return true;
        }
    }
    return false;
}

int main(){
    fast;
    ll n;
    cin >> n;
    if(MillerRabin(n)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}


