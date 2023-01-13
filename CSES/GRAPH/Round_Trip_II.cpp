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
constexpr ll MOD=1e9+7;
const int limit=2e5+5;

vector<int>adj[limit];
bool vis[limit]={false} , cycle_vis[limit]={false};
int parent[limit];

int n,m;
int startnode , endnode;

bool dfs(int node,int par){
    
    vis[node] = true;
    cycle_vis[node] = true;
    parent[node] = par;


    for(int child:adj[node]){

        if(vis[child] == false)
        {	
            if(dfs(child,node) == true) {
            	return true;
            }
        }
        else if(cycle_vis[child] == true) {
        	startnode = child;
        	endnode = node;
        	return true;
        }
    }
    cycle_vis[node] = false;
    return false;
}

void makepath(){
 
    vector<int>path;
    int x=endnode;

    path.push_back(x);

    while(x != startnode){
        path.push_back(parent[x]);
        x=parent[x];
    }
    path.push_back(endnode);

    rev(path);

    cout<<path.size()<<endl;
    for(auto i:path) cout<<i<<" ";
    cout<<endl;
}

void an1nd1ta(int tc){
    
    cin>> n >> m;
 	
 	map<pair<int,int>,int>mp;

    for(int i=1;i<=m;i++){
        
        int u,v;
        cin>> u >> v;

        if(mp[{u,v}] == 0 && u!=v ){
        	
        	adj[u].push_back(v);

        	mp[{u,v}] = 1;
        }

    }

    for(int i=1;i<=n;i++){

        if(vis[i] == false){
            if(dfs(i,-1)){
                makepath();
                return;
            }
        }
 
    }

    cout<<"IMPOSSIBLE"<<endl;
    return;
}

int main(){
    fast;
    int testcase=1;
    //cin >> testcase;
    for(int T=1;T<=testcase;T++) an1nd1ta(T);
    return 0;
}