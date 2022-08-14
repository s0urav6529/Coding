
#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
typedef unsigned long long int llu;

constexpr ll mod=1e9+7;
const int limit=2e5+5;


int main(){
    fast;
    ll n,x;
    cin>>n>>x;
    map<ll,ll>mp;

    ll sum=0,ans=0;
    mp[0]=1;
    for(int i=1;i<=n;i++){

        ll y;
        cin>>y;
        sum+=y;

        ans+=mp[sum-x];

        mp[sum]++;
    }
    cout<<ans<<endl;


    return 0;
}

