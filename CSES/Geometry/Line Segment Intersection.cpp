
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

using namespace __gnu_pbds;
template<typename T>
using ordered_set=tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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
#define pyes         cout<<"YES"<<endl
#define pno          cout<<"NO"<<endl
#define pfp(x,y)     cout<<fixed<<setprecision(y)<<x<<endl;
#define pf(a)         cout<<a<<endl;
#define ppf(a,b)      cout<<a<<" "<<b<<endl;
#define pppf(a,b,c)   cout<<a<<" "<<b<<" "<<c<<endl;
#define nl           endl;
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define mpr make_pair
#define pi acos(-1.0)
//cin.get();
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
constexpr ll imax=1e9;
constexpr ll imin=-1e9;
constexpr ll MOD=998244353;
const int limit=100005;

void init_code(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif
}


int orientation(ll x1,ll y1,ll x2,ll y2,ll x3,ll y3){

    ll val=(y2-y1)*(x3-x2)-(x2-x1)*(y3-y2);

    if(val>0) return 1;
    else if(val<0) return -1;
    else return val;
}

bool projection(ll a,ll b,ll c,ll d){
    if(a>b) swap(a,b);
    if(c>d) swap(c,d);

    return max(a,c)<=min(b,d);
}

void run_case(){


    ll x1,y1, x2,y2, x3,y3, x4,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

    int p1=orientation(x1,y1,x2,y2,x3,y3);
    int p2=orientation(x1,y1,x2,y2,x4,y4);
    int p3=orientation(x3,y3,x4,y4,x1,y1);
    int p4=orientation(x3,y3,x4,y4,x2,y2);

    if((p1!=p2) && (p3!=p4)){
        pyes;
    }
    else if(p1==0 && p4==0){


        if(projection(x1,x2,x3,x4) && projection(y1,y2,y3,y4)){
            pyes;
        }
        else pno;

    }
    else pno;

    return;
}

int main(){
    fast;
    //init_code();
    int tc=1;
    cin>>tc;
    while(tc--) run_case();
    return 0;
}



