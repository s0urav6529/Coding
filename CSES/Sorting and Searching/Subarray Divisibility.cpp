#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
typedef unsigned long long int llu;

constexpr ll mod=1e9+7;
const int limit=2e5+5;


int main(){
    fast;
    ll n,ans=0,sum=0;
    cin>>n;
    map<ll,ll>mp;


    mp[0]=1;

    for(int i=0;i<n;i++){

        ll x;
        cin>>x;

        sum+=x;

        ll rem=sum%n;

        if(rem<0) rem+=n;

        ans+=mp[rem];

        mp[rem]++;

    }
    cout<<ans<<endl;

    return 0;
}


