#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
#define reset(a,b)   memset(a, (b), sizeof(a))
#define sortv(k)     sort(k.begin(),k.end())
#define sortg(k)     sort(k.begin(),k.end(),greater<int>())
#define uniq(vec)    vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())))
#define rev(k)       reverse(k.begin(),k.end())
#define umin(a,b)    a=min(a,b)
#define umax(a,b)    a=max(a,b)
#define min3(a,b,c)  min(a, min(b,c))
#define pyes         cout<<"YES"<<endl
#define pno          cout<<"NO"<<endl
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

vector<int>adj[limit];
ll dp[limit];
ll deg[limit];

ll dfs(int node,int par){


    if(adj[node].size()==0){
        return dp[node]=0;
    }

    if(dp[node]!=0) return dp[node];

    ll res = 0;
    for(auto child:adj[node]){

        if(child!=par){

            res  = max(res,1+dfs(child,node));

        }

    }
    return dp[node]=res;

}

void run_case(){

    int n , m;
    cin >> n >> m;

    for(int i=0;i<m;i++){

        int x,y;
        cin >> x >> y;

        adj[x].pb(y);

        deg[y]++;

    }

    ll ans = 0;
    for(int i=1;i<=n;i++){

        if(deg[i]==0){
            ans = max(ans, dfs(i,-1));
        }
    }
    cout<<ans<<endl;

    return;
}

int main(){
    fast;
    int tc=1;
    //cin>>tc;
    while(tc--) run_case();
    return 0;
}

