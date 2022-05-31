
///count the number of ways to tile a (4*N) grid with (4*1) grid tile by replacing horizontally or virtically.

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);

int n;
ll dp[1005];

ll solution(int n)
{
    if(n<1) return 0;
    if(n<4) return 1;
    if(n==4) return 2;
    if(dp[n]!=-1) return dp[n];

    ///if i place (4*1) grid tile as horizontally then my problem reduce to (i-1)
    ///and if i place (4*1) grid tile as virtically then my problem reduce to (i-4)

    return dp[n]=solution(n-1)+solution(n-4);
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
        cout<<solution(n)<<endl;
    }
    return 0;
}




