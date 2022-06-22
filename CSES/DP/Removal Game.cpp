#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int limit=5005;
constexpr int mod=1e9+7;

int a[limit];
ll dp[limit][limit];

ll rec(int i,int j){

    if(i==j) return a[i];
    if(j-i==1) return max(a[i],a[j]);

    ll &ans=dp[i][j];

    if(ans!=-1) return ans;

    dp[i][j]=max(a[i]+min(rec(i+2,j),rec(i+1,j-1)),a[j]+min(rec(i,j-2),rec(i+1,j-1)));

    return ans;

}

int main(){

    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    memset(dp,-1,sizeof dp);

    cout<<rec(1,n)<<endl;

    return 0;
}


