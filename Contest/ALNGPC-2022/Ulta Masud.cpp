#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e2+5;

int main(){
    fast;
    ll n;
    cin>>n;

    ll ans=0;
    while(n--){

        ll x;
        cin>>x;

        ll base=9,p=0;
        while(x){

            ll dig=x%10;

            x/=10;

            if(dig>7) dig--;

            ans+=dig*pow(base,p);

            p++;
        }
    }
    cout<<ans<<endl;



    return 0;
}


