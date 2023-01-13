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
 
vector<pair<int,int>>adj[limit];
ll ways[limit] , dis[limit] , min_flight[limit] , max_flight[limit];
bool vis[limit];

void dijkstra(int n){

    for(int i=1;i<=n;i++){

        vis[i] = false , dis[i] = 1e18 , min_flight[i] = 1e9 , max_flight[i] = 0;

    }

    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
 
    dis[1] = 0;
    ways[1] = 1;
    min_flight[1] = max_flight[1] = 0;
 
    pq.push({0,1});
 
    while(!pq.empty()) {
        
        ll weight=pq.top().first;
        int node=pq.top().second;
        pq.pop();
 
        if(vis[node]) continue;
        vis[node] = true;
 
        for(pair<int,ll>child:adj[node]){

            if(weight + child.second == dis[child.first]){ /// combains

                min_flight[child.first] = min(min_flight[child.first], 1 + min_flight[node]);
 
                max_flight[child.first] = max(max_flight[child.first] , 1 + max_flight[node]); 
 
                ways[child.first] = (ways[child.first] + ways[node]) % MOD;

            }
            else if(weight + child.second < dis[child.first]) {  /// Reset updated path info
 
                    
                dis[child.first] = weight + child.second;

                pq.push({dis[child.first],child.first});
 
                min_flight[child.first] = 1 + min_flight[node];
 
                max_flight[child.first] = 1 + max_flight[node]; 
 
                ways[child.first] = ways[node] % MOD;
            
            }
        }
    }



}
 
void an1nd1ta(int tc){
    
    int n , m;

    cin >> n >> m;
 
    for(int i=0;i<m;i++){
 
        int a , b, c;
        
        cin >> a >> b >> c;
 
        adj[a].pb({b,c});
 
    }
 
    dijkstra(n);
 
    cout << dis[n] <<" "<<ways[n]<<" "<<min_flight[n] <<" "<<max_flight[n]<<endl;
 
 
    return;
}
 
int main(){
    fast;
    int testcase=1;
    //cin >> testcase;
    for(int T=1;T<=testcase;T++) an1nd1ta(T);
    return 0;
}