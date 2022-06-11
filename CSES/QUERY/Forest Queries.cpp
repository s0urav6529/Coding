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
#define pno          cout<<"NO"<<endl;
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define mpr make_pair
#define pi acos(-1.0)
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
constexpr ll imax = 1e9;
constexpr ll imin =-1e9;
constexpr ll mod = 1e9+7;
const int limit=1005;

int n,q;
int f[limit][limit];

void cum_sum(){

    for(int i=1;i<=n;i++){

        for(int j=1;j<=n;j++){

            f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
        }
    }
}
void solution(){

    cin>>n>>q;

    for(int i=1;i<=n;i++){

        string s;
        cin>>s;
        for(int j=1;j<=n;j++){
            if(s[j-1]=='*'){
                f[i][j]=1;
            }
            else f[i][j]=0;
        }
    }
    cum_sum();
    while(q--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;

        int bot_right=f[c][d];
        int bot_left=f[c][b-1];
        int top_right=f[a-1][d];
        int add=f[a-1][b-1];
        int sum=bot_right-bot_left-top_right+add;
        cout<<sum<<endl;
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
