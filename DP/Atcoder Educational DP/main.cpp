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

ll a[limit];

/// L , R , Player turn
ll dp[limit][limit][3];

ll rec(int l,int r,int turn){

    if(l == r ){

        if(turn == 1) /// first player can earn score
            return a[l];
        else   /// first player can't earn score because it's second player turn
            return 0;
    }

    ll &ans = dp[l][r][turn];

    if(ans != -1) return ans;

    if(turn == 1){
        /// first player always tries to maximize his score
        return ans = max(a[l] + rec(l+1, r, 2) , a[r] + rec(l, r-1, 2));
    }
    else {
        /// second player always tries to minimize first player score
        return ans = min(rec(l+1, r, 1) , rec(l, r-1, 1));
    }


}

void an1nd1ta(int t){

    int n;
    cin >> n;

    ll total = 0;

    for(int i=1;i<=n;i++) {
        cin >> a[i];
        total += a[i];
    }

    memset(dp,-1,sizeof dp);

    ll first_player_score = rec(1,n,1); /// only for first player score

    ll second_player_score = total - first_player_score;

    cout<< first_player_score - second_player_score <<endl;

    return;
}

int main(){
    fast;
    int tc=1;
    //cin >> tc;
    for(int t=1;t<=tc;t++) an1nd1ta(t);
    return 0;
}
