#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define mod 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);

int ft[200];
int s[100];
int f[100];
vector<int>g[100];
int timer=1;
void dfs(int node,int par)
{
    s[node]=timer;
    ft[timer]=node;
    timer++;

    for(int c:g[node])
    {
        if(c!=par) dfs(c,node);
    }
    f[node]=timer;
    ft[timer]=node;
    timer++;
}
void solution()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,-1);

    for(int i=1;i<=n;i++)
        cout<<s[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++)
        cout<<f[i]<<" ";
    cout<<endl;
    for(int i=1;i<=2*n;i++)
        cout<<ft[i]<<" ";
    return;
}
int main()
{
    fast;
    int tc=1;
    //cin>>tc;
    while(tc--) solution();
    return 0;
}





