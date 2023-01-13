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
const int limit=2e5+5;

vector<int>adj[limit] , transpose[limit] , condense[limit];
vector<int>outtime , con_group(limit);
bool self_loop[limit]={false} , vis[limit]={false};
vector<int> total_edges(limit,0);
int ans[limit];
int n , c;

/// for out time of node
void dfs_out(int node){
 
    vis[node]=true;
 
    for(int ch:adj[node]){
 
        if(vis[ch]==false)
            dfs_out(ch);
 
    }
    outtime.push_back(node);
 
}

/// finding the condense group of a node
void dfs(int node){
 
    vis[node] = true;
 
    for(int ch:transpose[node]){
 
        if(vis[ch] == false){
            dfs(ch);
        }
    }
    con_group[node] = c;
}

/// finding how many edges in a particular condense group
void dfs2(int node){
 
    vis[node] = true;

    int edges = 0;

    if(self_loop[node] == true) edges++;
 
    for(int ch:adj[node]){
 
        if(vis[ch] == false){
            dfs2(ch);
        }
        edges++;
    }
    total_edges[con_group[node]] += edges;
}


/// finding total how many edges can visit by any particular condese group node
void dfs3(int node,int par){

	vis[node] = true;

	int temp = total_edges[node];

	for(int child : condense[node]){


		if(child != par){

			dfs3(child,node);

			temp += ans[child];
		}

	}

	ans[node] = temp;

}

void an1nd1ta(int tc){
    
    cin >> n;

    for(int i=1;i<=n;i++){

    	int t;
    	cin >> t;

    	if(i == t) self_loop[i] = true;
    	else {
    		adj[i].pb(t);
    		transpose[t].pb(i);
    	}

    }

    for(int i=1;i<=n;i++){

    	if(vis[i] == false){
    		dfs_out(i);
    	}

    }

    for(int i=1;i<=n;i++){
        vis[i] = false;
    }

    c=1;
    for(int i=1;i<=n;i++){
 
        if(vis[outtime[n-i]] == false){
            dfs(outtime[n-i]);
            c++;
        }
    }

    for(int i=1;i<=n;i++){
        vis[i] = false;
    }

    for(int i=1;i<=n;i++){
 
        if(vis[i] == false){
            dfs2(i);
        }
    }

    /// making condense graph
    map<pair<int,int>,bool>mp;
 
    for(int i=1;i<=n;i++){
 
        for(int ch:adj[i]){
 
            int par = i,child = ch;
 
            if(par<child) swap(par,child); /// only for avoid overhead in graph
 
            if(con_group[par] != con_group[child] && mp.find({par,child}) == mp.end()) {
 
                condense[con_group[i]].push_back(con_group[ch]);
                mp[{par,child}]=true;
            }
        }
    }
    
    for(int i=1;i<=n;i++) {
    	vis[i] = false;
    }

    for(int i=1;i<c;i++){

    	if(vis[i] == false){
    		dfs3(i,-1);
    	}

    }

    // for(int i=1;i<c;i++) cout<<ans[i]<<" ";
    // 	cout<<endl;

    for(int i=1;i<=n;i++){
    	cout<<ans[con_group[i]]<<" ";
    }
    cout<<endl;
 
    return;
}

int main(){
    fast;
    int testcase=1;
    //cin >> testcase;
    for(int T=1;T<=testcase;T++) an1nd1ta(T);
    return 0;
}