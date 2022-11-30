
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
const int limit=25;

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

int dp[limit][limit];
int a[limit][limit];
bool vis[limit][limit];
int n , m;

bool isvalid(int x,int y)
{
    if(x<1 || x>n || y<1 || y>m || vis[x][y] == true) return false;
    return true;
}


void run_case(int t){


    cin >> n >>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) {
            cin >> a[i][j];
            dp[i][j] =  1e9;
            vis[i][j] =false;
        }
    }
    dp[1][1] = a[1][1];

    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

    pq.push({a[1][1],{1,1}});

    while(pq.size()>0){

        int val = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;

        pq.pop();

        if(vis[x][y] == true) continue;

        vis[x][y] =true;

        for(int i=0;i<4;i++){

            int nx = x+dx[i];
            int ny = y+dy[i];

            if(isvalid(nx,ny) && (dp[nx][ny]>dp[x][y]+a[nx][ny])){

                dp[nx][ny] = dp[x][y]+a[nx][ny];
                pq.push({dp[nx][ny],{nx,ny}});
            }
        }

    }

    cout<<"Case "<<t<<": Penalty = "<<dp[n][m]<<endl;



    return;
}

int main(){
    fast;
    int tc=1;
    cin>>tc;
    for(int t=1;t<=tc;t++) run_case(t);
    return 0;
}
