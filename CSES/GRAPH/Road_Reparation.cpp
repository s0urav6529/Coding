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

vector<int>Parent(limit);
vector<int>Rank(limit,1);
ll ans , edges;

int Find(int a){

    if(Parent[a] == a) return a;

    return Parent[a]=Find(Parent[a]);

}

void Union(int a,int b , int c){

    a=Find(a);
    b=Find(b);

    if(a!=b){
    	ans += c;
    	edges++;
        if(Rank[b]>Rank[a]) swap(a,b);
        Parent[b]=a;
        Rank[a]+=Rank[b];
    }
}



void an1nd1ta(int tc){
    
    int n , m;
    cin >> n >> m;


    vector<pair<int,pair<int,int>>>adj(m);

    for(int i=0;i<m;i++){

        cin >> adj[i].ss.ff >> adj[i].ss.ss >> adj[i].ff;

    }
    sort(adj.begin(),adj.end());

    for(int i=1;i<=n;i++) Parent[i] = i;
 
    for(int i=0;i<m;i++){

        Union(adj[i].ss.ff, adj[i].ss.ss, adj[i].ff);

    }

    if(edges+1 == n) cout << ans << endl;
    else cout<<"IMPOSSIBLE"<<endl;

    return;
}

int main(){
    fast;
    int testcase=1;
    //cin >> testcase;
    for(int T=1;T<=testcase;T++) an1nd1ta(T);
    return 0;
}