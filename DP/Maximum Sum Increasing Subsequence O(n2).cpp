#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define mod 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
void solution()
{
    int n;
    cin>>n;
    int a[n+5],dp[n+5],path[n+5];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[i]=a[i];
        path[i]=i;
    }
    int indx=1,Max=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(a[j]<a[i] && dp[i]<a[i]+dp[j]) ///Same as LIS but ekhane sum max hole update hbe
            {
                dp[i]=a[i]+dp[j];
                path[i]=j;
                Max=max(dp[i],Max);
                if(Max==dp[i]) indx=i;
            }
        }
    }
    cout<<Max<<endl;
    cout<<indx<<" ";
    for(int i=indx;i>=1;)
    {
        cout<<path[i]<<" ";
        i=path[i];
        if(path[i]==i) break;
    }

    return;
}
int main()
{
    fast;
    //read;
    //out;
    int tc=1;
    cin>>tc;
//    for(int z=1;z<=tc;z++)
//    {
//
//    }
    while(tc--) solution();
    return 0;
}




