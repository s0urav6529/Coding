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
    ll a,b,c;
    cin>>a>>b>>c;

    a=(a%MOD);
    b=(b%MOD);
    c=(c%MOD);
    a=(a*b)%MOD;
    a=(a*c)%MOD;
    cout<<a<<endl;

    return;
}

int  main(){
    fast;
    //read;
    int tc=1;
    cin>>tc;
    while(tc--) run_case();
    return 0;
}
