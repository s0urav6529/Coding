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
#define setprecision(y,x)     cout<<fixed<<setprecision(y)<<x<<endl   ///kotoghor , value
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
typedef long double ld;
typedef unsigned long long int llu;
//constexpr llu Mx=18446744073709551615;
constexpr ll MOD=998244353;
const int limit=1e6+5;

int vis[limit];
void seive(){

    vis[0]=vis[1]=vis[2]=0;

    for(ll i=4; i<limit; i+=2) vis[i] = 2;

    for(ll i=3; i*i<limit; i+=2){

        if(vis[i]>0) continue;
        for(ll j=i*i; j<limit; j+=2*i){
            if(vis[j]==0) vis[j] = i;
        }
        vis[i]=0;
    }

}

int _gcd(int x,int y){

    if(x%y==0) return y;
    return _gcd(y,x%y);
}

void run_case(int t){

    int x,y;
    cin>>x>>y;
    int gcd=_gcd(x,y);

    if(gcd==1) {
        cout<<"Case "<<t<<": "<<-1<<endl;
        return;
    }

    ll ans=1;

    if(vis[gcd]>0) ans=gcd/vis[gcd];

    cout<<"Case "<<t<<": "<<ans<<endl;

    return;
}

int main(){
    fast;
    seive();
    int tc=1;
    cin>>tc;
    for(int t=1;t<=tc;t++) run_case(t);
    return 0;
}

