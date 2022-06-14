#include<bits/stdc++.h>
using namespace std;

const int limit=5005;

int dp[limit][limit];
string a,b;
int rec(int i,int j,int as,int bs){


    if(i>=as || j>=bs) return max(bs-j,as-i);

    if(dp[i][j]!=-1) return dp[i][j];

    if(a[i]==b[j]){
        return dp[i][j]=rec(i+1,j+1,as,bs);
    }
    else{
        int ans=1e7;
        ans=min(ans,1+rec(i+1,j+1,as,bs)); /// replace
        ans=min(ans,1+rec(i+1,j,as,bs)); ///delete
        ans=min(ans,1+rec(i,j+1,as,bs)); ///add
        return dp[i][j]=ans;
    }
}

int main(){

    cin>>a>>b;
    memset(dp,-1,sizeof dp);
    int as=a.size();
    int bs=b.size();
    cout<<rec(0,0,as,bs)<<endl;
    return 0;
}
