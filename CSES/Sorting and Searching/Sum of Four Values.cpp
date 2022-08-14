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

    map<ll,pair<int,int>>mp;
    ll a[n+3];

    for(int i=1;i<=n;i++) cin>>a[i];


    for(int i=1;i<=n;i++){

        for(int j=i+1;j<=n;j++){

            ll z=x-(a[i]+a[j]);
            if(mp.count(z)){
                cout<<i<<" "<<j<<" "<<mp[z].first<<" "<<mp[z].second<<endl;
                return 0;
            }

        }

        for(int j=1;j<i;j++){
            mp[(a[i]+a[j])]={i,j};
        }

    }
    cout<<"IMPOSSIBLE"<<endl;

    return 0;
}

