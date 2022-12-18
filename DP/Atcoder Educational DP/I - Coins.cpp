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
const int limit=3005;

void an1nd1ta(int t){

    int n;
    cin >> n;

    double p[n+5];

    for(int i=1;i<=n;i++) cin >> p[i];

    /// no of coins & no of heads
    double dp[n+5][n+5];

    memset(dp,0,sizeof dp);

    dp[0][0] = 1.00;

    for(int i=1;i<=n;i++){  /// No of coins

        for(int j=0;j<=i;j++){ ///No of heads

            if(j==0){ /// no heads that means tails

                dp[i][j] = dp[i-1][j]*(1 - p[i]);

            }
            else{
                dp[i][j] = dp[i-1][j-1] * p[i] + dp[i-1][j] * (1-p[i]);
            }

        }
    }

    double ans = 0.0;

    for(int i=n/2+1;i<=n;i++){

        ans += dp[n][i];

    }
    cout<<fixed<<setprecision(10)<<ans<<endl;


    return;
}

int main(){
    fast;
    int tc=1;
    //cin >> tc;
    for(int t=1;t<=tc;t++) an1nd1ta(t);
    return 0;
}
