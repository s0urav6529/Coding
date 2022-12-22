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

vector<int>adj[limit];
ll dp[limit][2];

ll dfs(int node,int par,int col){

    if(dp[node][col] != -1) return dp[node][col];

    ll ans = 0;
    for(int child:adj[node]){

        if(child != par){

            if(par == -1){
                ans = ( ans % MOD + dfs(child,node,0) % MOD + dfs(child,node,1) % MOD ) % MOD;
                ans = (ans % MOD + dfs(child,node,0)) % MOD;
            }
            else{

                if(col == 0) ans = ( ans % MOD + dfs(child,node,0) % MOD + dfs(child,node,1) % MOD ) % MOD;
                else ans = (ans % MOD + dfs(child,node,0) % MOD) % MOD;
            }

        }
    }
    if(ans == 0) ans = 1;
    return dp[node][col] = ans;
}


void an1nd1ta(int t){

    int n;
    cin >> n;

    memset(dp,-1,sizeof dp);

    for(int i=1;i<n;i++){

        int x,y;

        cin >> x >> y;

        adj[x].pb(y);
        adj[y].pb(x);

    }

    cout << dfs(1,-1,0) <<endl;

    //cout <<dp[1][0]<<endl

    return;
}

int main(){
    fast;
    int tc=1;
   //cin >> tc;
    for(int t=1;t<=tc;t++) an1nd1ta(t);
    return 0;
}
