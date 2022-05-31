
/// operations are divided by 2 or divided by 3 or substract by 1


#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
int dp[1005];
int n;
int solution(int i)
{
    if(i==1) return 0;

    if(dp[i]!=-1) return dp[i];

    int p=1e9,q=1e9,r;

    if(i%2==0) p=1+solution(i/2);

    if(i%3==0) q=1+solution(i/3);

    r=1+solution(i-1);

    return dp[i]=min(r,min(p,q));
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

        ///top-down approch
        memset(dp,-1,sizeof(dp));
        cout<<solution(n)<<endl;

        ///bottom up aproch
        /*dp[1]=0;
        for(int i=2;i<=n;i++)
        {
            int p=1e9,q=1e9,r;
            if(i%2==0) p=1+dp[i/2];
            if(i%3==0) q=1+dp[i/3];
            r=1+dp[i-1];
            dp[i]=min({p,q,r});
        }
        cout<<dp[n]<<endl;*/

    }
    return 0;
}




