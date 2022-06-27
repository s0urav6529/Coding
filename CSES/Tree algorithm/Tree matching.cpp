
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define mod 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);

const int limit=200005;

vector<int>adj[limit];
int dp[limit][2];

void solve(int node,int parent){

    vector<int>suffix,prefix;

    bool leaf=1;

    for(int child:adj[node]){

        if(child!=parent){
            leaf=0;
            solve(child,node);

            prefix.push_back(max(dp[child][0],dp[child][1]));

            suffix.push_back(max(dp[child][0],dp[child][1]));
        }
    }

    if(leaf) return;


    for(int i=1;i<prefix.size();i++) prefix[i]+=prefix[i-1];

    for(int i=suffix.size()-2;i>=0;i--) suffix[i]+=suffix[i+1];

    ///not choose this node,so answer will be maximum of it's childs
    ///which are suffix[0] or prefix[childsize]
    dp[node][0]=suffix[0];

    int child_no=0;

    for(int child:adj[node]){

        if(child!=parent){

            int leftchild=(child_no==0)? 0:prefix[child_no-1];

            int rightchild=(child_no==suffix.size()-1)? 0:suffix[child_no+1];

            ///we can take any node and take maximum of it's shibling leftchild,right child
            ///adding dp[child][0] because next we cannot take it.

            dp[node][1]=max(dp[node][1],1+dp[child][0]+leftchild+rightchild);

            child_no++;
        }
    }
}
void solution()
{
    int n,x,y;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    solve(1,-1);
    cout<<max(dp[1][0],dp[1][1]);
    return;
}
int main()
{
    fast;
    int tc=1;
    while(tc--) solution();
    return 0;
}





