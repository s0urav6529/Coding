
///  1+2+3+3-3+4-1+...........+n ///n<10r5
///  A[b1] - A[b2] + A[b3] - A[b4] + ...............A[bk] = ?

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
int dp[1005][2];  ///if even =0 and odd=1
int n;
int a[1005];
int solution(int i,int flag)
{
    if(i>n) return 0;

    if(dp[i][flag]!=-1) return dp[i][flag];

    ///we can take or not if even and if we take then we have to substracted
    if(flag==0) return dp[i][flag]=max(solution(i+1,0),solution(i+1,1)-a[i]);

    ///we can take or not if odd and if we take then we have to add
    if(flag==1) return dp[i][flag]=max(solution(i+1,1),solution(i+1,0)+a[i]);
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

        solution(1,1);
        cout<<dp[1][1]<<endl;
    }
    return 0;
}


