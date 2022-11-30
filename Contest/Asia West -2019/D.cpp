
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
const int limit=305;


void run_case(int t){

    int n,m,k,s,d;
    cin>>n>>m>>k>>s>>d;

    vector<ll>discount(k);

    for(int i=0;i<k;i++) cin >> discount[i];
    sortv(discount);
    rev(discount);

    vector<pair<int,int>>adj[n+1];

    vector<ll>dis(n+1,10000000000000000ll);
    vector<bool>vis(n+1,false);
    vector<int>par(n+1,-1);

    map<pair<int,int>,ll>edges;

    for(int i=1;i<=m;i++){

        int x,y;
        ll w;
        cin>>x>>y>>w;
        if(x==y) continue;
        adj[x].push_back({y,w});
        edges[{x,y}]=w;

    }
    if(s==d){
        cout<<0<<endl;
        return;
    }

    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;

    dis[s]=0;
    pq.push({0ll,s});

    while(!pq.empty()) {

        ll weight=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        if(vis[node] == true) continue;
        vis[node]=true;

        for(pair<int,ll>child:adj[node]){

            if(weight+child.second<dis[child.first]) {

                dis[child.first]=weight+child.second;
                pq.push({dis[child.first],child.first});
                par[child.first] = node;
            }
        }
    }

    if(par[d] == -1) {
        cout<<-1<<endl;
        return;
    }

    vector<ll>picked;

    while(d!=s){

        ll val = edges[{par[d],d}];
        picked.pb(val);
        d = par[d];
    }

    sortv(picked);
    rev(picked);

    int i=0,j=0;
    ll ans  = 0;
    while(i<picked.size() && j<discount.size()){

        ans += max(0ll, picked[i++]-discount[j++]);
    }

    while(i<picked.size()){
        ans += picked[i++];
    }
    cout<<ans<<endl;

    return;
}

int main(){
    fast;
    int tc=1;
    cin>>tc;
    for(int t=1;t<=tc;t++) run_case(t);
    return 0;
}

