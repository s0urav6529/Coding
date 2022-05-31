///God is Almighty
///Author:SMU_coder

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen("in.txt","r",stdin);
#define pb push_back
#define pi acos(-1.0)
#define ff fast
#define ss second
#define sortv(k) sort(k.begin(),k.end())
#define rev(k) reverse(k.begin(),k.end())
constexpr ll MOD=1e9+7;
const int limit=10005;

void run_case(){
    int n;
    cin>>n;
    map<ll,ll>mp;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        mp[x]++;
    }
    ll min_val=1e18,max_oc=0;
    map<ll,ll>mp2;
    for(auto i:mp){
        mp2[i.second]++;
    }

    for(auto i:mp2){
        //cout<<i.first<<" "<<i.second<<endl;
        if(i.second>max_oc){
            max_oc=i.second;
            min_val=i.first;
        }
        else if(i.second==max_oc){
            if(min_val>i.first) min_val=i.first;
        }
    }
    cout<<min_val<<endl;

    return;
}

int  main(){
    fast;
    //read;
    int tc=1;
    //cin>>tc;
    while(tc--) run_case();
    return 0;
}
