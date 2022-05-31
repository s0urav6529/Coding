
///  1+2+3+3-3+4-1+...........+n ///n<10r3
/// 1*A[b1] + 2*A[b2] + 3*A[b3] + 4*A[b4] + ............... k*A[bk] = ?

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
int dp[1005][1005];
int n;
int a[1005];
int solution(int i,int ith)
{
    if(i>n) return 0;

    if(dp[i][ith]!=-1) return dp[i][ith];

    return dp[i][ith]=max(solution(i+1,ith),(ith*a[i])+solution(i+1,ith+1)); ///we can take or not
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

