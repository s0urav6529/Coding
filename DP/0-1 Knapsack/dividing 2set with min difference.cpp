
///another solution with binary serach dp in atcoder "cooking" problem  O(logn*n*totalsum)

///this is O(n*totalsum)

#include<bits/stdc++.h>
#define Fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Freed freopen ("0in.txt","r",stdin);
#define Fout freopen ("0out.txt","w",stdout);
#define ll long long int
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define Mod 1000000007
#define limit 102
using namespace std;

ll d[limit],total,n;
ll dp[100002][limit];

ll (ll sum, ll pos){

    if(pos>=n)
    {
        return max(sum, total-sum);
    }
    if(dp[sum][pos]!=-1) return dp[sum][pos];

    return dp[sum][pos] = min(rec(sum,pos+1),rec(sum+d[pos],pos+1));
}

void solve(ll t)
{
    ll i;
    cin >> n;

    memset(dp,-1,sizeof(dp));

    for(i=0; i<n; i++)
    {
        cin >> d[i];
        total += d[i];  ///totalsum of elements
    }
    cout << rec(0,0) << endl;
    return ;
}
int  main()
{
    ll t,tt=1;
    //cin>>tt;
    for(t=1; t<=tt; t++)
        solve(t);
    return 0;
}
