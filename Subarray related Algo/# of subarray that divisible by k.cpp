

///for both pos  & negative value.

///problem link : https://cses.fi/problemset/task/1662



#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
typedef unsigned long long int llu;

constexpr ll mod=1e9+7;
const int limit=2e5+5;


int main(){
    fast;
    ll n,k,ans=0,sum=0;
    cin>>n>>k;
    map<ll,ll>mp;


    mp[0]=1;

    for(int i=0;i<n;i++){

        ll x;
        cin>>x;

        sum+=x;

        ll rem=sum%k;

        if(rem<0) rem+=k;

        ans+=mp[rem];

        mp[rem]++;

    }
    cout<<ans<<endl;

    return 0;
}


