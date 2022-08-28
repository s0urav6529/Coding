#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e2+5;

int main(){
    fast;

    ll n,a,b;
    cin>>n>>a>>b;

    ll c[n+5],pref[2*n+5];

    for(int i=1;i<=n;i++) cin>>c[i];

    pref[0]=0;

    for(int i=1;i<=n;i++) pref[i]=pref[i-1]+c[i];

    for(int i=n+1;i<=2*n;i++) pref[i]=-1e14;


    set<ll>s;

    ll i=a,ans=-1e18;
    while(i<=b) s.insert(pref[i++]);


    for(ll j=a,p=0;j<=n;j++,p++){

        ll mx=*s.rbegin();

        mx-=pref[p];

        ans=max(ans,mx);

        s.erase(pref[j]);
        s.insert(pref[i]);
        i++;
    }
    cout<<ans<<endl;




    return 0;
}



