
///Is it possible to make a number using this array's number sum ;like given 1,2,5,6,7 and you have to make 10.is it possible

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);

int n,sum;
int dp[1005][1005];
int a[1005];
int solution(int i,int sum)
{
    if(sum==0) return 1;
    if(i>n && sum!=0) return 0;
    if(dp[i][sum]!=-1) return dp[i][sum];

    if(a[i]>sum) return dp[i][sum]=solution(i+1,sum);

    else return dp[i][sum]=solution(i+1,sum-a[i])+solution(i+1,sum);
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
        cin>>n>>sum;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(solution(1,sum))
            cout<<dp[1][sum]<<endl;
        else cout<<0<<endl;
    }
    return 0;
}





