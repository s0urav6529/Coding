#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int limit=505;


int dp[limit][limit];

int rec(int a,int b){

    if(a==b) return 0;

    if(dp[a][b]!=-1) return dp[a][b];

    int ans=1e9;

    for(int i=1;i<a;i++){

        ans=min(ans,1+rec(a-i,b)+rec(i,b));
    }

    for(int i=1;i<b;i++){
        ans=min(ans,1+rec(a,b-i)+rec(a,i));
    }
    return dp[a][b]=ans;
}


int main(){
    fast;
    int a,b;
    cin>>a>>b;
    memset(dp,-1,sizeof dp);
    cout<<rec(a,b)<<endl;
    return 0;
}


