#include<bits/stdc++.h>
using namespace std;

const int limit=5005;

int dp[limit][limit];
string a,b;

int rec(int i,int j){

    if(i<0|| j<0) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    if(a[i]==b[j]){
        return dp[i][j]=1+rec(i-1,j-1);
    }
    else
        return dp[i][j]=max(rec(i-1,j),rec(i,j-1));
}

int main(){


    cin>>a>>b;
    memset(dp,-1,sizeof dp);
    int mx=max((int)a.size(),(int)b.size());

    cout<<rec(a.size()-1,b.size()-1)<<endl;

    return 0;
}
