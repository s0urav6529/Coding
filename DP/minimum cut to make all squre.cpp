
///YOU ARE GIVEN A A*B RECTANGLE YOU HAVE TO FIND MINIMU CUT TO MAKE A*B RECTANGLE A BUNCH OF SQURE
///LIKE 3*5 CAN SPLIT (3*3)\(2*2)\(1*1)\(1*1) SO WE NEED 3 CUTS

#include<bits/stdc++.h>
#include<math.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int dp[505][505];
//bool vis[505][505]={false};
int solution(int i,int j)
{
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int Min=1e8;
    for(int k=1;k<i;k++)
    {
        Min=min(Min,1+solution(i-k,j)+solution(k,j));
    }
    for(int l=1;l<j;l++)
    {
        Min=min(Min,1+solution(i,j-l)+solution(i,l));
    }
    return dp[i][j]=Min;
}
int main()
{
    int a,b;
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    cout<<solution(a,b)<<endl;
    return 0;
}



