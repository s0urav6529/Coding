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
#define pyes         cout<<"YES"<<endl
#define pno          cout<<"NO"<<endl
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define mpr make_pair
#define pi acos(-1.0)
//cin.get();
//getline(cin,s);
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
constexpr ll imax=1e9;
constexpr ll imin=-1e9;
constexpr ll MOD=1e9+7;
const int limit=1000005;

bool vis[limit];
vector<int>prime;
vector<ll>prefix;

void sieve()
{
	vis[0]=vis[1]=1;
    for(int i=4; i<limit; i+=2) vis[i] = 1;
    for(int i=3; i*i<limit; i+=2)
    {
        if(vis[i]) continue;
        for(int j=i*i; j<limit; j+=2*i)
        {
            vis[j] = 1;
        }
    }
    prefix.pb(0);
    prime.pb(0);
    prime.pb(2);
    prefix.pb(2);

	for(int j=3; j<limit; j+=2)
    if(vis[j]==0){
        prime.pb(j);
        prefix.pb(j);
    }

	for(int i=1;i<prefix.size();i++){

        prefix[i]+=prefix[i-1];
	}
}


void solution(int t){

    int a,b;
    cin>>a>>b;
    int x=lower_bound(prime.begin(),prime.end(),a)-prime.begin();
    int y=upper_bound(prime.begin(),prime.end(),b)-prime.begin();
    --y;
    --x;

    //cout<<x<<" "<<y<<endl;
    cout<<prefix[y]-prefix[x]<<endl;
    return;
}
int main()
{
    fast;
    //read;
    //out;
    sieve();
    int tc=1;
    cin>>tc;
    //cin.get();
    for(int t=1;t<=tc;t++) {
        solution(t);
    }
    return 0;
}
