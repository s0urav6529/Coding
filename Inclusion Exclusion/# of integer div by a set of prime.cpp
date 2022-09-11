
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=21;


int main(){
    fast;

    ll n , k;
    cin >> n >> k;

    vector<ll>a(k);

    for(int i=0;i<k;i++) cin >> a[i];

    vector<ll>divisors_contribution(k+1,0);

    for(int mask=1;mask<(1<<k);mask++){

        ll N=n,nod=0;   ///nod->number of divisors

        for(int bit=0;bit<k;bit++){

            if((mask & ( 1 << bit ))){

                N/=a[bit];
                nod++;
            }
        }
        divisors_contribution[nod]+=N;
    }

    ll ans=0;

    for(int i=1;i<=k;i++){

        if(i&1) ans+=divisors_contribution[i];

        else ans-=divisors_contribution[i];

    }

    cout<<ans<<endl;

    return 0;
}


