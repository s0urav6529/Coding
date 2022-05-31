#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
int n;
string s;
int dp[1005][1005];
int solution(int B,int E)
{
    if(B>E) return 0;
    if(B==E) return 1;
    if(dp[B][E]!=-1) return dp[B][E];

    /// if Begin and End char are equal that means
    /// we got a subsequence of 2 lenght and next we can reduce the B and E
    if(s[B]==s[E]) return dp[B][E]=2+solution(B+1,E-1);
    else
    {
        ///here at first we reduce Begin or End and searching our maximum solution
        return dp[B][E]=max(solution(B,E-1),solution(B+1,E));
    }
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
        memset(dp,-1,sizeof(dp));
        cin>>n>>s;
        cout<<solution(0,n-1)<<endl;
    }
    return 0;
}


