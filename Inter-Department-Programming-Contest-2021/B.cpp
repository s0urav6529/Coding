

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
const int limit=100005;

bool check(int m,vector<int>&a,int n,ll k){


    ll op=0;

    rep0(i,n){

        if(a[i]>m){
            op+=((a[i]/m)-1)+(a[i]%m!=0);
        }
        if(op>k) return false;

    }
    return true;


}

void solution(int t){


    int n,ans=1;
    ll k;
    cin>>n>>k;
    vector<int>a(n);
    rep0(i,n) cin>>a[i],umax(ans,a[i]);

    int l=1,r=ans;

    while(l<=r){

        int mid=l+(r-l)/2;

        if(check(mid,a,n,k)) {
            umin(ans,mid);
            r=mid-1;
        }
        else l=mid+1;
    }

    cout<<"Case #"<<t<<": "<<ans<<endl;
    return;
}
int main()
{
    fast;
    //read;
    //out;
    int tc=1;
    cin>>tc;
    //cin.get();
    for(int t=1;t<=tc;t++) {
        solution(t);
    }
    return 0;
}
