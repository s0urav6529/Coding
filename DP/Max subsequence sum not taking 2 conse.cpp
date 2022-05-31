
/// 10 20 30 40 55 -50 -100 20 =115

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
/*int dp[10005];
int a[10005];
int n;
int solution(int pos)
{
    if(pos>n) return 0;

    if(dp[pos]!=-1) return dp[pos];

    int Max=max(a[pos]+solution(pos+2),solution(pos+1));

    return dp[pos]=Max;
}
int main()
{
    fast;
    //read;
    //out;
    int tc=1;
    cin>>tc;
    for(int z=1;z<=tc;z++)
    {
        cin>>n;
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;i++) cin>>a[i];
        solution(1);
        cout<<dp[1]<<endl;

    }
    return 0;
}*/
///another way

int dp[10005][2]; ///(before taken =1) and ( before not taken=0)
int a[10005];
int n;
int solution(int pos,int bef)
{
    if(pos>n) return 0;

    if(dp[pos][bef]!=-1) return dp[pos][bef];

    if(bef==1)
    {
        return dp[pos][bef]=solution(pos+1,0);  ///Cause before position was taken so we cannot take this position
    }
    else
    {
        int Max=max(a[pos]+solution(pos+1,1),solution(pos+1,0));  ///we can take this position or we cannot
        return dp[pos][bef]=Max;
    }
}
int main()
{
    fast;
    //read;
    //out;
    int tc=1;
    cin>>tc;
    for(int z=1;z<=tc;z++)
    {
        cin>>n;
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;i++) cin>>a[i];
        solution(1,0);
        cout<<dp[1][0]<<endl;
    }
    return 0;
}

