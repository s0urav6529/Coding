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

vector<int>adj[limit] , transpose[limit];
vector<int>outtime , condense_group(limit);
vector<bool>vis(limit,false);
int c;

void dfs_out(int node){   

    vis[node]=true;

    for(int ch:adj[node]){


        if(vis[ch]==false)
            dfs_out(ch);

    }

    outtime.push_back(node);

}

void dfs(int node){ 

    vis[node] = true;

    for(int ch:transpose[node]){

        if(vis[ch] == false)
            dfs(ch);

    }

    condense_group[node] = c;
}



void an1nd1ta(int tc){
    int n , m;
    cin >> n >> m;

    for(int i=1;i<=m;i++){
        int a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        transpose[b].push_back(a);
    }

    for(int i=1;i<=n;i++){

        if(vis[i] == false) 
            dfs_out(i);

    }

    for(int i=1;i<=n;i++) vis[i]=false;

	vector<int>vertex;

    for(int i=1;i<=n;i++){


        if(vis[outtime[n-i]] == false){
        	c++;
            dfs(outtime[n-i]);
        }

    }
    cout << c <<endl;
    for(int i=1;i<=n;i++) cout<<condense_group[i]<<" ";
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