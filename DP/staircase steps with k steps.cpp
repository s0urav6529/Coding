
///count the number of ways to reach nth stair when the required jumps are 2 and 1;

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);

int n,k=3;
int dp[1005];

int solution(int i)
{
    if(i<0) return 0;
    if(i==0) return dp[i]=1;
    if(dp[i]!=-1) return dp[i];
    int ans=0;
    for(int j=1;j<=k;j++) ans+=solution(i-j);
    return dp[i]=ans;
}
int main()
{
    fast;
    //read;
    //out;
    int tc=1;
    cin>>tc;
    while(tc--)
    {
        memset(dp,-1,sizeof(dp));
        cin>>n;
        solution(n);
        cout<<dp[n]<<endl;
    }
    return 0;
}




