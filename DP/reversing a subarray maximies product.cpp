//#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
using ll=long long;
using ld=long double;
#define mod 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);

int n;
ll ans=0;
ll a[5005],b[5005];
ll dp[5005][5005];
ll solve(int l,int r){
    if(l>=r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];

    ll bef=a[l]*b[l]+a[r]*b[r];
    ll aft=a[l]*b[r]+a[r]*b[l];

    return dp[l][r]=(aft-bef)+solve(l+1,r-1);

}
void solution()
{
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        cin>>b[i];
        ans+=(a[i]*b[i]);
    }
    //cout<<ans<<endl;
    ll temp=0;
    for(int i=1;i<=n;i++){
        for(int j=n;j>i;j--){
            temp=max(temp,solve(i,j));
        }
    }
    cout<<ans+temp;
    return ;
}
int main()
{
    fast;
    //read;
    //out;
    int tc=1;
    //cin>>tc;
    while(tc--) solution();
    return 0;
}





