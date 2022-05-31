#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
string s,p;
int n,m;
int dp[3005][3005];
int solution(int i,int j)
{
    if(i>=n || j>=m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==p[j]) return dp[i][j]=1+solution(i+1,j+1);
    else
        return dp[i][j]=max(solution(i+1,j),solution(i,j+1));
}
int main()
{
    fast;
    //read;
    //out;
    int tc=1;
    //cin>>tc;
    for(int z=1;z<=tc;z++)
    {
        memset(dp,-1,sizeof(dp));
        cin>>s>>p;
        n=s.size(),m=p.size();
        cout<<solution(0,0)<<endl;
        int i=0,j=0;
        string k="";
        while(i<n && j<m)
        {
            if(s[i]==p[j]) k+=s[i],j++,i++;
            else
            {
                if(dp[i+1][j]>dp[i][j+1]) i++; ///checking if (i+1) has maximum value or not if has then increase it otherwise increase j
                else j++;
            }
        }
        cout<<k<<endl;
        //cout<<"Case "<<z<<": "<<ans<<endl;
    }
    return 0;
}
