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
const int limit=1e5+5;


void an1nd1ta(int tc){

    int n;
    cin >> n;

    ll a[n+5] , csum[n+5] , dp[n+5][n+5];

    csum[0] = 0;

    for(int i=1;i<=n;i++){
        cin >> a[i];
        csum[i] = csum[i-1]+a[i];
    }

    for(int i=0;i<=n;i++){

        for(int j=0;j<=n;j++){

            if(i == j) dp[i][j] = 0;

            else dp[i][j] = 1e18;
        }
    }

    for(int seg_size = 1 ; seg_size <= n ; seg_size++){

        for(int l = 1 , r = seg_size ; r<=n ; l++, r++){

            for(int mid = l ; mid<r ; mid++){

                dp[l][r] = min(dp[l][r] , dp[l][mid] + dp[mid+1][r] + (csum[r]-csum[l-1]));

            }

        }

    }

    cout << dp[1][n] <<endl;



    return;
}

int main(){
    fast;
    int testcase=1;
    //cin >> testcase;
    for(int T=1;T<=testcase;T++) an1nd1ta(T);
    return 0;
}
