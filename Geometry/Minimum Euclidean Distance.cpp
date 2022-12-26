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

ll Euclidean_Distance(pair<ll,ll> a, pair<ll,ll> b) {
    return (b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second);
}

int main(){

    int n;
    cin>>n;
    vector<pair<ll,ll>> a(n);

    ll Min_dist = LLONG_MAX;

    for(int i=0; i<n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    set<pair<ll,ll>>s;
    s.insert({a[0].second, a[0].first});

    for(int i=1,j=0; i< n; i++) {

        auto it = s.begin();
        ll dd = ceil(sqrt(Min_dist));

        while(j<i && a[j].first < a[i].first - dd) {
            s.erase({a[j].second, a[j].first});
            j++;
        }

        auto l = s.lower_bound({a[i].second - dd, 0LL});
        auto r = s.upper_bound({a[i].second + dd, 0LL});

        for (auto it=l; it != r; it++) {
            Min_dist = min(Min_dist, Euclidean_Distance({it->second, it->first}, a[i]));
        }

        s.insert({a[i].second, a[i].first});
    }
    cout << Min_dist <<endl;
}
