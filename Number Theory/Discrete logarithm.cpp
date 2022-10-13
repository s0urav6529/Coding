
/// Given anequation a^x = b (mod m ) where a & m are coprime

/// Find the value of x where x is as minimum as possile (given a , b & m)

/// we can express x = n*p - q

/// n = sqrt(m)+1  &&  1<=p<=sqrt(m)  &&  0<=q<sqrt(m)

/// putting x = n*p-q in the equation a^(n*p-q)  = b(mod m)
/// a^(n*p) % m == ( b * a^q ) % m

/// O(sqrt(m)*log(m)) or O(sqrt(m))


#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=1e6+5;

int main(){
    fast;

    ll a,b,m;
    cin >> a >> b >> m;

    ll n = sqrt(m)+1;

    ll an = 1;


    unordered_map<ll,ll>val;

    /// calculating ( b*a^q ) % m


    for(ll q=0 , cur=b; q<n ;q++){

        val[cur] = q;  /// storing maximum q

        cur = (cur * a) % m;
    }

    /// calculating ( a^n ) % m
    for(ll i=1; i<=n; i++) {
        an = (an * n) % m;
    }

    /// calculating ( an^p ) % m
    for(ll p=1 , cur = 1 ; p<=n ;p++){

        cur = (cur * an) % m;

        if(val.count(cur)){
            cout<< n*p - val[cur] <<endl;
            return 0;
        }
    }
    cout<<-1<<endl;

    return 0;
}



