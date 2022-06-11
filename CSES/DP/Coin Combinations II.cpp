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
constexpr ll MOD=1e9+7;
const int limit=100005;
#include<vector>

int main(){
    fast;
    int n,x;
    cin>>n>>x;
    vector<int>a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];

    int dp[n+1][x+1];

    for(int coin=0;coin<=n;coin++){


        for(int sum=0;sum<=x;sum++){

            if((coin==0 && sum==0) || sum==0) dp[coin][sum]=1;
            else if(coin==0 && sum>0) dp[coin][sum]=0;
            else{

                 ll op1=(sum<a[coin])?0:dp[coin][sum-a[coin]];
                 ll op2=dp[coin-1][sum];

                 dp[coin][sum]=(op1+op2)%MOD;

            }

        }

    }

    cout<<dp[n][x]<<endl;
    return 0;
}

