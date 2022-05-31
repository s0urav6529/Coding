#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define el endl;
//#define push_back pb;
#define make_pair mp;
#define mod 1000000007;
#define pi acos(-1.0);
#define mx 0;
#define mn 10000000000000;
#define first ft;
#define second snd;
#define inf 1e9
#define linf 1e18
#define eps 1e-9
using namespace std;
typedef vector<int> vi;
typedef vector<long> vl;
typedef map<int,int>mi;
typedef map<long,long>ml;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<long,long>pll;
using ll=long long;
using ld=long double;
ll a[100005];
ll dp[1005][1005];
vl v;
int main()
{
    fast;
    ll n,totalsum=0,target;
    cin>>n>>target;
    for(ll i=0;i<n;i++)cin>>a[i],totalsum+=a[i];

    ll m=(target+totalsum)/2;
    memset(dp,0,sizeof(dp));

    for(int i=0;i<=n;i++){

        for(int j=0;j<=m;j++){

            if(i==0 && j>0)
                dp[i][j]=0;
            if(j==0)
                dp[i][j]=1;
        }
    }

    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){

            if(a[i-1]<=j)
                dp[i][j]=dp[i-1][j-a[i-1]]+dp[i-1][j];

            else
                dp[i][j]=dp[i-1][j];
        }
    }
    if(dp[n][m]?cout<<"YES":cout<<"NO");
    return 0;
}
