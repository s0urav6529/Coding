
///ekta string e koita distinct subsequence ache ta ber kora.


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
    ll dp[s.size()+5];
    map<char,int>last_oc;
    dp[0]=1;
    for(int i=1;i<=s.size();i++)
    {
        dp[i]=2*dp[i-1];
        if(last_oc.find(s[i-1])!=last_oc.end())
        {
            int loc=last_oc[s[i-1]];
            dp[i]-=loc;
        }
        last_oc[s[i-1]]=i;
    }
    cout<<dp[s.size()]-1<<endl;
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




