#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e2+5;

int main(){
    fast;
    ll n,m;
    cin>>n>>m;

    n=min(n,m);

    ll ans=((n-1)*3)+n;
    cout<<ans<<endl;


    return 0;
}


