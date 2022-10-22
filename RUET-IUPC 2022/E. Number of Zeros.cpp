#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
#define reset(a,b)   memset(a, (b), sizeof(a))
#define sortv(k)     sort(k.begin(),k.end())
#define sortg(k)     sort(k.begin(),k.end(),greater<int>())
#define rev(k)       reverse(k.begin(),k.end())
#define umin(a,b)    a=min(a,b)
#define umax(a,b)    a=max(a,b)
#define min3(a,b,c)  min(a, min(b,c))
#define pyes         cout<<"Yes"<<endl
#define pno          cout<<"No"<<endl
#define pf(a)        cout<<a<<endl
#define p2f(a,b)     cout<<a<<" "<<b<<endl
#define p3f(a,b,c)  cout<<a<<" "<<b<<" "<<c<<endl
#define p4f(a,b,c)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define ff first
#define ss second
#define pb push_back
#define pi acos(-1.0)
//cin.get();
typedef long long int ll;
//typedef unsigned long long int llu;
//constexpr llu Mx=18446744073709551615;
constexpr ll MOD=1000000007;
const int limit=1e5+5;

ll fact[limit] , inv_fact[limit];

void init(){

    inv_fact[0] = inv_fact[1] = 1;
    for(ll i=2 ; i<limit;i++){
        inv_fact[i] = MOD - 1ll * (MOD/i) * inv_fact[MOD % i] % MOD;
    }

    fact[0] = fact[1] = 1;
    for(ll i=2;i<limit;i++){
        fact[i] = (i*fact[i-1])% MOD;
        inv_fact[i] = (inv_fact[i] * inv_fact[i-1])%MOD;
    }
}

ll nCr(ll n, ll r) {
  if(r > n) return 0;
  return (((1LL * fact[n] * inv_fact[n-r]) % MOD) * inv_fact[r]) % MOD;
}




void run_case(int t){

    ll n , b;
    cin >> n >> b;

    ll occ[n+5];

    for(ll i=0;i<n;i++){
        occ[i+1] = nCr(n-1,i);
    }

    ll ans  = 0;
    for(ll i=1;i<=n;i++){

        ll temp = 0 , num = b;

        while(i/num){
            temp = (temp+(i/num)) % MOD;
            num = (num*b)%MOD;
        }
        temp = (temp*occ[i])%MOD;
        ans = (ans + temp)%MOD;
    }

    cout<<"Case "<<t<<": "<< ans <<endl;



    return;
}

int main(){
    fast;
    int tc=1;
    init();
    cin>>tc;
    for(int t=1;t<=tc;t++) run_case(t);
    return 0;
}

