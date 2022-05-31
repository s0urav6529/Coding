
///count the number of ways to reach nth stair when the required jumps are 2 and 1;

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);

int n;
int dp[1005];

int solution(int i)
{
    if(i<0) return 0;
    if(i==0) return 1;
    if(dp[i]!=-1) return dp[i];

    return dp[i]=solution(i-1)+solution(i-2);
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





