#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen  ("out.txt","w",stdout);
#define reset(a,b)   memset(a, (b), sizeof(a))
#define sortv(k)     sort(k.begin(),k.end())
#define sortg(k)     sort(k.begin(),k.end(),greater<int>())
#define uniq(vec)    vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())))
#define rev(k)       reverse(k.begin(),k.end())
#define umin(a,b)    a=min(a,b)
#define umax(a,b)    a=max(a,b)
#define min3(a,b,c)  min(a, min(b,c))
#define pyes         cout<<"Yes"<<endl
#define pno          cout<<"No"<<endl
#define pf(a)        cout<<a<<endl
#define p2f(a,b)     cout<<a<<" "<<b<<endl
#define p3f(a,b,c)   cout<<a<<" "<<b<<" "<<c<<endl
#define p4f(a,b,c)   cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define ff first
#define ss second
#define pb push_back
#define pi acos(-1.0)
//cin.get();
typedef long long int ll;
const int limit=1e6+5;

bool vis[limit];
vector<int>prime;
void seive(){

    vis[0]=vis[1]=1;

    for(int i=4; i<limit; i+=2) vis[i] = 1;

    for(int i=3; i*i<limit; i+=2){

        if(vis[i]) continue;
        for(int j=i*i; j<limit; j+=2*i) {

            vis[j] = 1;
        }
    }

    prime.push_back(2);

    for(int j=3; j<limit; j+=2){
    	if(vis[j]==0) prime.push_back(j);
    }
}


int main(){

    fast;
    seive();
    ll  tc=1;
    //cin >> tc;
    while(tc--){
        ll n,base = 10;

        cin >> n ;

        vector<pair<ll,ll>>factors;

        for(int i=0 ; prime[i]*prime[i] <= base ;i++){

            bool ok=false;
            ll cnt = 0;
            
            while(base%prime[i] == 0){

                base/=prime[i];
                cnt++;
                ok=true;
            }
            if(ok){
                factors.push_back({prime[i],cnt});
            }
        }

        if(base > 1ll) factors.push_back({base,1});

        ll Tzeros = 1e15;

        for(int i = 0; i < factors.size() ; i++){

            ll number = factors[i].first;
            ll occ = factors[i].second;
            ll zeros = 0 , denominator = number;

            while(n/denominator){

                zeros += (n/denominator);
                denominator *= number;

            }
            Tzeros = min(Tzeros , zeros/occ);
        }
        cout << Tzeros <<endl;
    }


    return 0;
}