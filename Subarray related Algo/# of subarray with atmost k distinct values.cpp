
 # Subarray Distinct Values
 # Problem link : https://cses.fi/problemset/task/2428



#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e2+5;

int main(){
    fast;
    ll n,k; cin>>n>>k;
    vector<ll>a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    ll ans=0,j=0;

    map<ll,ll>oc;

    for(ll i=0;i<n;i++){

        while(j<n && ((int)oc.size()<k || oc.count(a[j])>0)){

            oc[a[j]]++;
            j++;
        }

        ans+=j-i;

        oc[a[i]]--;

        if(oc[a[i]]==0)
            oc.erase(a[i]);

    }
    cout<<ans<<endl;
    return 0;
}



