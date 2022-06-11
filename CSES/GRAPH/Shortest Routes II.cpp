#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define mod 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);


int main()
{
    fast;
    int n,m,q;
    cin>>n>>m>>q;

    ll dp[n+5][n+5];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) {
            if(i==j) dp[i][j]=0;
            else dp[i][j]=1e18;
        }
    }

    for(int i=0;i<m;i++){

        int a,b;
        ll c;
        cin>>a>>b>>c;


        dp[a][b]=min(dp[a][b],c);
        dp[b][a]=min(dp[b][a],c);

    }

    for(int mid=1;mid<=n;mid++){

        for(int i=1;i<=n;i++){

            for(int j=1;j<=n;j++)
                dp[i][j]=min(dp[i][j],dp[i][mid]+dp[mid][j]);

        }
    }

    while(q--){

        int a,b;
        cin>>a>>b;
        if(dp[a][b]==1e18) cout<<-1<<endl;
        else cout<<dp[a][b]<<endl;

    }

    return 0;
}



