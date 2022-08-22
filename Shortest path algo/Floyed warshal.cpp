#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define mod 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);

//struct edge{
//    int a,b,c;
//};

int main()
{
    fast;
    int n,m;
    cin>>n>>m;

    ll dp[n+5][n+5];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) 
            dp[i][j]=imax;
    }

    //vector<edge>e(m);

    for(int i=0;i<m;i++){

        int u,v,w;
        cin>>u>>v>>w;

        //e[i]={u,v,w};

        dp[u][v]=w;
        dp[v][u]=w;

    }

    for(int mid=1;mid<=n;mid++){

        for(int i=1;i<=n;i++){

            for(int j=1;j<=n;j++) {
              
                dp[i][j] = min ( dp[i][j] ,dp[i][mid] + dp[mid][j] );
            
            }
        }
    }

//    int unused=0;
//
//    for(int i=0;i<m;i++){
//
//        for(int j=1;j<=n;j++){
//
//            if(dp[e[i].a][j]+dp[j][e[i].b]<=e[i].c){
//                unused++;
//                break;
//            }
//        }
//    }
//    cout<<unused<<endl;
    return 0;
}


