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
#define mpr make_node
#define pi acos(-1.0)
//cin.get();
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
constexpr ll imax=1e9;
constexpr ll imin=-1e9;
constexpr ll MOD=1e9+7;
const int limit=1005;
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

int r,c,rr,cc;
char a[limit][limit];
bool vis[limit][limit]={false};

bool isvalid(int x,int y)
{
    if(x<1||x>r||y<1||y>c||vis[x][y]==true || a[x][y]=='#') return false;
    return true;
}

void solution(){

    cin>>r>>c;

    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            cin>>a[i][j];
        }
    }

    int cnt=0;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){

            if(vis[i][j]==false && a[i][j]=='.'){
                queue<pair<int,int>>q;
                q.push({i,j});
                while(q.size()){
                    pair<int,int> pp=q.front();
                    int cx=pp.ff;
                    int cy=pp.ss;
                    q.pop();
                    for(int i=0;i<4;i++){
                        if(isvalid(cx+dx[i],cy+dy[i])){
                            q.push({cx+dx[i],cy+dy[i]});
                            vis[cx+dx[i]][cy+dy[i]]=true;
                        }
                    }
                }
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
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




