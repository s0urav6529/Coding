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
const int limit=1e7+5;
bool vis[limit];
vector<ll>prime;
void seive(){

    vis[0]=vis[1]=1;

    for(int i=4; i<limit; i+=2) vis[i] = 1;

    for(int i=3; i*i<limit; i+=2){

        if(vis[i]) continue;
        for(int j=i*i; j<limit; j+=2*i) {

            vis[j] = 1;
        }
    }

    prime.pb(2);

    for(int j=3; j<limit; j+=2){
    	if(vis[j]==0) prime.pb(j);
    }
}

void an1nd1ta(int t){

    int n;
    scanf("%d",&n);

    if(vis[n] == 0){
        printf("yes\n");
        return;
    }

    string s = to_string(n);

    for(int i=s.size()-1;i>=0;i--){

        for(char j ='0' ;j<='9' ;j++){

            if(i==0 && j=='0') continue;

            string p = s;
            p[i] = j;

            int x = stoi(p);

            if(vis[x] == 0){
                printf("yes\n");
                return;
            }

        }

    }
    printf("no\n");

    return;
}

int main(){
    fast;
    seive();
    int tc=1;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++) an1nd1ta(t);
    return 0;
}
