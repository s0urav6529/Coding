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
int a[limit][limit];
bool vis[limit][limit]={false};

bool isvalid(int x,int y)
{
    if(x<1||x>r||y<1||y>c||vis[x][y]==true || a[x][y]=='#') return false;
    return true;
}

class node{
    public:
    int i;
    int j;
    string psf;
    node(int ii,int jj,string PSF)
    {
        i=ii;
        j=jj;
        psf=PSF;
    }
};

void solution(){

    cin>>r>>c;

    for(int i=1;i<=r;i++){
        string s;
        cin>>s;
        for(int j=1;j<=c;j++){
            a[i][j]=s[j-1];
            if(a[i][j]=='A') rr=i,cc=j;
        }

    }
    queue<node>q;
    q.push({rr,cc,""});

    while(q.size()){

        node n=q.front();
        q.pop();

        if(a[n.i][n.j]=='B'){
            pyes;
            cout<<n.psf.size()<<endl<<n.psf<<endl;
            return;
        }
        int cx=n.i;
        int cy=n.j;
        for(int i=0;i<4;i++)
        {
            if(isvalid(cx+dx[i],cy+dy[i]))
            {
                int nx=cx+dx[i];
                int ny=cy+dy[i];
                char c='R';
                if(cx-1==nx && cy==ny) c='U';
                if(cx==nx && cy-1==ny) c='L';
                if(cx+1==nx && cy==ny ) c='D';

                q.push({nx,ny,n.psf+c});
                vis[nx][ny]=true;
            }
        }


    }
    pno;
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



