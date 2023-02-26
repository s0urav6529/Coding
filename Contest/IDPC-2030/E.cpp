#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen  ("out.txt","w",stdout);
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
#define p3f(a,b,c)   cout<<a<<" "<<b<<" "<<c<<endl
#define p4f(a,b,c)   cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define ff first
#define ss second
#define pb push_back
#define pi acos(-1.0)
//cin.get();
typedef long long int ll;
//typedef unsigned long long int llu;
//constexpr llu Mx=18446744073709551615;
constexpr ll MOD=1e9+7;
const int limit=1e5+5;

void an1nd1ta(int tc){
    int n ;
    ll m;
    cin >> n >>m;
    vector<ll>a(n),b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    sortv(a);
    sortv(b);

    ll l = a[0] + b[0] , r = a[n-1] + b[n-1] , ans = 0;

    while(l<=r){

        ll mid = l + (r-l) / 2ll;

        ll cnt = 0;

        for(int i=0;i<n;i++){

            ll lagbe = mid - a[i];
            lagbe--;

            ll idx = upper_bound(b.begin(),b.end(),lagbe) - b.begin();

            //cout << mid <<" "<<lagbe <<" "<<idx <<endl;

            cnt += idx;

        }
        if(cnt < m){

            ans = max(ans,mid);
            l = mid+1;
        }
        else r = mid-1;
    }
    if(ans & 1) cout <<"ODD"<<endl;
    else cout <<"EVEN"<<endl;
    return;
}

int main(){
    fast;
    int testcase=1;
    cin >> testcase;
    for(int T=1;T<=testcase;T++) an1nd1ta(T);
    return 0;
}
