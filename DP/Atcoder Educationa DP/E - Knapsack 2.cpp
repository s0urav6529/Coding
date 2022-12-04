#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
int n,tw;
ll w[105];
ll v[105];
ll dp[105][100005];
ll solution(ll i,ll V)
{
    if(i>n) return V==0?0:INT_MAX;
    ///here we return INT_MAX because it will take (0 Wight)nothing but return the max value;
    if(dp[i][V]!=-1) return dp[i][V];
    if(v[i]<=V) ///wight store in dp[i][V]
        return dp[i][V]=min(w[i]+solution(i+1,V-v[i]),solution(i+1,V));
    else return dp[i][V]=solution(i+1,V);
}
int main()
{
    fast;
//    read;
//    out;
    int tc=1;
    //cin>>tc;
    for(int z=1;z<=tc;z++)
    {
        cin>>n>>tw;
        ll sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>w[i]>>v[i];
            sum+=v[i];
        }
        memset(dp,-1,sizeof(dp));
        for(int i=sum;i>=0;i--)///iterating maximum value we ca get;
        {
            if(solution(1,i)<=tw)
            {
                cout<<i;
                break;
            }
        }

    }
    return 0;
}
