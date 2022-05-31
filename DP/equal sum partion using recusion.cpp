
///make two set of an array such that their sum is equal;

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);

int n;
int dp[1005][1005];
int a[1005];
int solution(int i,int sum)
{
    if(sum==0) return 1;
    if(i>n && sum!=0) return 0;

    if(dp[i][sum]!=-1) return dp[i][sum];

    if(a[i]>sum) return dp[i][sum]=solution(i+1,sum);

    else return dp[i][sum]=solution(i+1,sum-a[i]) || solution(i+1,sum);
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
        int sum=0;
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%2==0)  ///if the total elements sum is positive then we have a chance to make equal sum partion and the rest is like sumset sum problem
        {
            sum/=2;
            if(solution(1,sum)) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}




