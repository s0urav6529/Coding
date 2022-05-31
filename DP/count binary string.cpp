
///your friends want to go a birthday party.
///They can go alon or a pair.
///How many number of ways they can go.

///f(n)=(1*f(n-1)) + (1*(n-1)C1) * f(n-2) ; //

///You are given 'N' and you have to make a Binary String with '0' and '1' and you are not allowed to place consecutive 1 .
///How many ways such string possible??

///like n=1 then '1' and '0' =2 ways
///n=2 then '00','10','01' =3 ways
///n=3 then '000','100','010','001' and '101' =5 ways

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);

int n;
ll dp[1005];

ll solution(int n)
{
   if(n<1) return 0;
   if(n==1) return 2;
   if(n==2) return 3;
   if(dp[n]!=-1) return dp[n];

   return dp[n]=solution(n-1) + solution(n-2);  ///(n-2) when we place 1 here and (n-1) when we place 0 here

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
        memset(dp,-1,sizeof(dp));
        cin>>n;
        cout<<solution(n)<<endl;
    }
    return 0;
}

