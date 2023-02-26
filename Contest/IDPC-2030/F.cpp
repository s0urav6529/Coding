#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie.(0);cout.tie(0);
#define ff first
#define ss second
#define pb push_back
#define pi acos(-1.0)
#define sort(k) sort(k.begin(0),k.end())
#define sortg(k) sort(k.begin(0),k.end(),greater<int>())
#define uniq(k) k.resize(distance(k.begin(),unique(k.begin(),k.end())))
typedef long long int ll;
constexpr ll MOD = 1e9+7;
const int limit = 1e6+5;

bool vis[limit] , vis2[limit];
vector<ll>prime;
void seive(){
    for(int i=1;i<limit;i++) vis2[i] = 0;
    vis[0] = vis[1] = 1;
    for(int i=4;i<limit;i+=2) vis[i] = 1;
    for(int i=3;i*i<limit;i+=2){
        if(vis[i]) continue;
        for(int j=i*i;j<limit;j+=2*i){
            vis[j] = 1;
        }
    }
    prime.pb(2);
    for(int j=3;j<limit;j+=2){
        if(vis[j] == 0) {
            prime.pb(j);
        }
    }
}
void solution(){
    int n;
    cin >> n;
    vector<ll>ans;
    ll a[n+5] , mx = 0;
    vector<ll> divi;
    set<ll>s;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        for(int j=0;prime[j]*prime[j] <= a[i];j++){

            ll num = prime[j] *prime[j];
            //cout << num <<endl;

            if(num == a[i]){
                //divi.pb(a[i]);
                s.insert(a[i]);
            }
        }
        mx = max(mx,a[i]);
    }
    while(s.size()>0){
        divi.pb(*s.begin());
        s.erase(*s.begin());
    }
    //cout << mx <<endl;
    for(int i=0;i<divi.size();i++){
        ll x = divi[i] , y = x;
        ll  j = 1;
        //cout << divi[i]<<endl;
        while(y <= limit){
            vis2[y] = 1;
            j++;
            y = x*j;
            //cout << x<<endl;
        }

    }

     for(int i=1;i<=n;i++) {

        if(vis2[a[i]] == 0){
            ans.pb(a[i]);
        }
     }


   cout << ans.size() <<endl;
   for(int i=0;i<ans.size();i++) cout << ans[i] <<" ";
   cout <<endl;


    return;
}
int main(){
    seive();
    int tc = 1;
   // cin >> tc;
    while(tc--){
        solution();
    }
    return 0;
}
