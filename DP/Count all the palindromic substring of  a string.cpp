

///You have a string and you have to count how many palindrome in this string.


#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define mod 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
bool dp[5005][5005];
void solution()
{
    string s;
    cin>>s;
    int n=s.size()-1,cnt=0,Max=0;
    for(int gap=0;gap<=n;gap++) ///Diagonal traversal
    {
        for(int r=0,c=gap;r<=n,c<=n;r++,c++)
        {
            if(gap==0)
            {
                dp[r][c]=true;
            }
            else if(gap==1 && s[r]==s[c])
            {
                dp[r][c]=true;
            }
            else
            {
                if(s[r]==s[c] && dp[r+1][c-1]==true)
                    dp[r][c]=true;
            }
            if(dp[r][c]) cnt++,Max=gap+1;
        }
    }
    cout<<cnt<<endl;   ///all the palindromic substring
    cout<<Max<<endl;  ///largest palindromic substring
    return;
}
int main()
{
    fast;
    //read;
    //out;
    int tc=1;
    cin>>tc;
//    for(int z=1;z<=tc;z++)
//    {
//
//    }
    while(tc--) solution();
    return 0;
}




