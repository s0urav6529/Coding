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
const int limit=1e3+5;

ll orientation(ll x1 , ll y1 , ll x2 , ll y2 , ll x3 , ll y3){

    ll val = (x3-x2)*(y2-y1) - (x2-x1)*(y3-y2);

    if(val > 0) return 1 ; /// clock wise
    else if(val < 0) return -1; ///counter clock wise
    else return 0; ///collinear

}

bool on_segmant(ll x1 , ll y1 , ll x2 , ll y2 , ll x3 , ll y3){

    return (x3<=max(x1,x2) && x3>=min(x1,x2) && y3<=max(y1,y2) && y3>=min(y1,y2));
}

bool intersection(pair<ll,ll>a,pair<ll,ll>b,pair<ll,ll>c,pair<ll,ll>d){

    ll x1 = a.first , y1 = a.second;
    ll x2 = b.first , y2 = b.second;
    ll x3 = c.first , y3 = c.second;
    ll x4 = d.first , y4 = d.second;

    ll o1 = orientation(x1,y1,x2,y2,x3,y3);
    ll o2 = orientation(x1,y1,x2,y2,x4,y4);
    ll o3 = orientation(x3,y3,x4,y4,x1,y1);
    ll o4 = orientation(x3,y3,x4,y4,x2,y2);

    if((o1 != o2) && (o3 != o4) ){
        return true;
    }
    return false;

}

void an1nd1ta(int tc){

    int n , m;
    cin >> n >> m;

    vector<pair<ll,ll>>poly(n) , points(m);

    for(int i=0;i<n;i++){
        cin >> poly[i].first >> poly[i].second;
    }

    for(int i=0;i<m;i++){
        cin >> points[i].first >> points[i].second;
    }


    for(int i=0;i<m;i++){

        pair<ll,ll>inf_point = {(ll)INT_MAX , (ll)INT_MAX+1};
        pair<ll,ll>c = points[i];
        ll intersect = 0;

        bool  boundary = false;

        for(int j=0;j<n;j++){

            pair<ll,ll>a = poly[j];
            pair<ll,ll>b = poly[(j+1)%n];

            if(orientation(a.first , a.second , b.first , b.second , c.first , c.second) == 0 && on_segmant(a.first , a.second , b.first , b.second , c.first , c.second)){
                boundary = true;
                break;
            }
            if(intersection(a,b,c,inf_point)){
                intersect++;
            }

        }

        if(boundary) cout<<"BOUNDARY"<<endl;
        else if(intersect&1) cout<<"INSIDE"<<endl;
        else cout<<"OUTSIDE"<<endl;
    }
    return;
}

int main(){
    fast;
    int testcase=1;
    //cin >> testcase;
    for(int T=1;T<=testcase;T++) an1nd1ta(T);
    return 0;
}

