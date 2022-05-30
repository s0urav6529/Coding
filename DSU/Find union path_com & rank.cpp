#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
#define sz(x) int((x).size())
#define rep0(i,k) for (int i=0 ; i<k ; i++)
#define rep(i,k)  for (int i=1 ; i<=k ; i++)
#define reset(a,b)   memset(a, (b), sizeof(a))
#define sortv(k)     sort(k.begin(),k.end())
#define sortg(k)     sort(k.begin(),k.end(),greater<int>())
#define rev(k)       reverse(k.begin(),k.end())
#define umin(a,b)    a=min(a,b)
#define umax(a,b)    a=max(a,b)
#define min3(a,b,c)  min(a, min(b,c))
#define pyes         cout<<"Yes"<<endl
#define pno          cout<<"No"<<endl
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define mpr make_pair
#define pi acos(-1.0)
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
constexpr ll imax=1e9;
constexpr ll imin=-1e9;
constexpr ll MOD=1e9+7;
const int limit=200001;

vector<int>Parent(limit,-1);
vector<int>Rank(limit,1); ///Rank means size of this cc

int Find(int a){

    if(Parent[a]<0) return a;

    return Parent[a]=Find(Parent[a]);

}

void Union(int a,int b){

    a=Find(a);
    b=Find(b);

    if(a!=b){

        if(Rank[b]>Rank[a]) swap(a,b);
        Parent[b]=a;
        Rank[a]+=Rank[b];
    }
}

void solution(){

    int n,m;
    cin>>n>>m;
//    vector<pair<int,pair<int,int>>>tree(n-1);
//
//    for(int i=0;i<n-1;i++){
//        int a,b,w;
//        cin>>tree[i].ss.ff>>tree[i].ss.ss>>tree[i].ff;
//    }
//    sort(tree.begin(),tree.end());
//
//    for(int i=0;i<n-1;i++){
//
//        Union(tree[i].ss.ff,tree[i].ss.ss,tree[i].ff);
//    }
    while(m--){
        int a,b;
        cin>>a>>b;
        Union(a,b);
    }

    return;
}
int main()
{
    fast;
    //read;
    //out;
    int tc=1;
    //cin>>tc;
    while(tc--) solution();
    return 0;
}


