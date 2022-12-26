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

ll dp1[limit][2] , dp2[limit][2];

ll dfs1(int node,int par ,int col){


    ll &ans = dp1[node][col];

    if(ans != -1LL) return ans;

    ans  = 1;

    for(int child : adj[node]){

        if(child != par){

            if(col == 0){

                ans = (ans * (dfs1(child,node,0) + dfs1(child,node,1)) % MOD ) % MOD;

            }
            else {
                ans = (ans * dfs1(child,node,0)) % MOD;
            }

        }

    }

    return ans;

}

ll dfs2(int node,int par ,int col){

    ll &ans = dp2[node][col];

    if(ans != -1LL) return ans;

    ans  = 1;

    for(int child : adj[node]){

        if(child != par){

            if(col == 0){

                ans = (ans * (dfs2(child,node,0) + dfs2(child,node,1)) % MOD ) % MOD;

            }
            else {
                ans = (ans * dfs2(child,node,0)) % MOD;
            }

        }

    }

    return ans;

}

void an1nd1ta(int tc){

    int n;
    cin >> n;

    memset(dp1,-1,sizeof dp1);
    memset(dp2,-1,sizeof dp2);

    for(int i=1;i<n;i++){
        int x , y;
        cin >> x  >> y;

        adj[x].pb(y);
        adj[y].pb(x);

    }

    ll ans1 = dfs1(1,-1,0); /// root node as a white node
    ll ans2 = dfs2(1,-1,1); /// root node as a black node

    cout << (ans1 + ans2) % MOD <<endl;

    return;
}

int main(){
    fast;
    int testcase=1;
    //cin >> testcase;
    for(int T=1;T<=testcase;T++) an1nd1ta(T);
    return 0;
}
