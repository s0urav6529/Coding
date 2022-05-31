
/// if extreme(1st and last) are equal then cnt(p)=cnt(suffix)+cnt(prefix)+1 /// dp[i][j]=dp[i][j-1]+dp[i+1][j]+1;
/// if extreme(1st and last) are not equal then c(p)=cnt(suffix)+cnt(prefix)-cnt(middle)  ///dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];

///source:::::https://www.youtube.com/watch?v=YHSjvswCXC8&list=PL-Jc9J83PIiEZvXCn-c5UIBvfT8dA-8EG&index=12

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define mod 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
int n;
void solution()
{
    string s;
    cin>>s;
    int dp[s.size()+5][s.size()+5];
    for(int gap=0;gap<s.size();gap++) ///diagonal traversal
    {
        for(int i=0,j=gap;i<s.size()  && j<s.size();i++,j++)
        {
            if(gap==0) dp[i][j]=1;
            else if(gap==1)
            {
                if(s[i]==s[j]) dp[i][j]=3;
                else dp[i][j]=2;
            }
            else
            {
                if(s[i]==s[j]) dp[i][j]=dp[i][j-1]+dp[i+1][j]+1;
                else dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
            }
        }
    }
    cout<<dp[0][s.size()-1]<<endl;
    return;
}
int main()
{
    fast;
    //read;
    //out;
    int tc=1;
    //cin>>tc;
//    for(int z=1;z<=tc;z++)
//    {
//
//    }
    while(tc--) solution();
    return 0;
}





