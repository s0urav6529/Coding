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
//typedef unsigned long long int llu;
//constexpr llu Mx=18446744073709551615;
constexpr ll MOD=1e9+7;
const int limit=1e5+5;

#define MaxN 17
int n;
vector<int>adj[limit];
int LCA[MaxN+5][limit];
int level[limit];
int dist[limit];

int get_lca(int a,int b){

    if(level[a] > level[b]) swap(a,b);

    int d = level[b]-level[a];

    while(d > 0){
      
        int j = log2(d);
        b = LCA[j][b];
        d -= (1<<j);
      
    }

    if(a == b) return a; 

    for(int j=MaxN;j>=0;j--){

        if(LCA[j][a] != -1 && (LCA[j][a] != LCA[j][b])){
            a = LCA[j][a];
            b = LCA[j][b];
        }
    }
    return LCA[0][a];

}

void dfs(int node,int par,int l){

    dist[node] = level[node] = l;
    LCA[0][node] = par;

    for(int ch : adj[node]){

        if(ch != par) {
          dfs(ch,node,l+1);
        }
    }
}

void an1nd1ta(int tc){
    cin >> n;

    for(int i=1;i<n;i++){
        
        int u,v;

        cin>>u>>v;

        adj[u].push_back(v);

        adj[v].push_back(u);
    }

    memset(LCA,-1,sizeof LCA);

    dfs(1,-1,0);

    for(int j=1;j<=MaxN;j++){

        for(int i=1;i<=n;i++){

            if(LCA[j-1][i] == -1) continue;

            int par = LCA[j-1][i];

            LCA[j][i] = LCA[j-1][par];
        }
    }

    int q;

    cin>>q;

    while(q--){

        int u,v;

        cin>>u>>v;
        
        int Lca = get_lca(u,v);
        int dis = (dist[u] + dist[v] - (2*dist[Lca])) - 1;
        if(dis & 1) pyes;
        else pno;

    }
    return;
}

int main(){
    fast;
    int testcase=1;
    //cin >> testcase;
    for(int T=1;T<=testcase;T++) an1nd1ta(T);
    return 0;
}
