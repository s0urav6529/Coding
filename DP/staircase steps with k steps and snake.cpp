
///count the number of ways to reach nth stair when the required jumps are k consecutive but in any stair if their is snake u cannot jump their;

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);

int n,k=3;
int dp[1005];
int a[1005];
int solution(int i)
{
    if(i<0) return 0;
    if(i==0) return 1;
    if(dp[i]!=-1) return dp[i];
    int ans=0;
    for(int j=1;j<=k;j++)
    {
        ans+=(a[i-j]*solution(i-j));
    }
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
        a[0]=1; ///Cause i have to go at ground so its value need to be 1;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        cout<<solution(n)<<endl;
    }
    return 0;
}





