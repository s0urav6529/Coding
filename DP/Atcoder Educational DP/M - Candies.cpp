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
const int limit=2e5+5;


void an1nd1ta(int t){

    int n , k;
    cin >> n >> k;

    ll dp[n+1][k+1], prefix_sum[k+1] , a[n+1];

    for(int i=1;i<=n;i++) cin >> a[i];

    dp[0][0] = 1;
    for(int j=1;j<=k;j++) {
        dp[0][j] = 0;
    }

    for(int i=1;i<=n;i++){

        prefix_sum[0] = 1;

        for(int j=1;j<=k;j++){

            prefix_sum[j] = ( prefix_sum[j-1] + dp[i-1][j] ) % MOD;

        }

        for(int j=0;j<=k;j++){

            int candy_ache = j , nibe = (candy_ache - a[i] - 1);

            dp[i][j] = prefix_sum[candy_ache];

            if(nibe >=0 ){
                dp[i][j] = (dp[i][j] - prefix_sum[nibe] + MOD) % MOD;
            }

        }

    }

    cout  << dp[n][k] <<endl;

    return;
}

int main(){
    fast;
    int tc=1;
    //cin >> tc;
    for(int t=1;t<=tc;t++) an1nd1ta(t);
    return 0;
}
