

///O(nr2)

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
int n;
string s;
int dp[1005][1005];
int solution(int B,int E)
{
    if(B >= E) return 1;
    if(dp[B][E]!=-1) return dp[B][E];

    if(s[B]==s[E])
    {
        ///There is a probaility that this could be a palindrom
        return dp[B][E]=solution(B+1,E-1);
    }

    ///There is not any probability
    else return dp[B][E]=0;
}
int main()
{
    fast;
    //read;
    //out;
    int tc=1;
    //cin>>tc;
    for(int z=1;z<=tc;z++)
    {
        cin>>n>>s;
        int ans=0;
        memset(dp,-1,sizeof(dp));

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                ///if the solution return 1 then the substring is palindrom
                ///otherwise not
                if(solution(i,j))
                {
                    ///storing the maximum lenght
                    ans=max(ans,j-i+1);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


