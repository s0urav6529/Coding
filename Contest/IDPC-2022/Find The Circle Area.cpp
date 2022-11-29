///God is Almighty
///Author:SMU_coder

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
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
    ll a;
    cin>>a;
    ld r=(1.0*a)/4;
    ld p=1.0;
    p=p*sqrt(2)*r;
    p-=r;
    p=pi*(p*p);
    cout<<fixed<<setprecision(10)<<p<<endl;
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
