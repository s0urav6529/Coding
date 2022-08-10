#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
typedef unsigned long long int llu;

constexpr ll mod=1e9+7;
const int limit=2e5+5;


int main(){
    fast;

    ll n,t;
    cin>>n>>t;
    vector<ll>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll l=1,r=1e18,ans=1e18;

    while(l<=r){

        ll mid=l+(r-l)/2;

        ll can=0;
        bool ok=false;
        for(int i=0;i<n;i++){

            can+=(mid/a[i]);
            if(can>=t) ok=true;

        }
        if(ok){
            ans=min(ans,mid);
            r=mid-1;
        }
        else l=mid+1;

    }
    cout<<ans<<endl;


    return 0;
}





