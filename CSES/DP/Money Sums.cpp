#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define el endl
#define push_back pb
#define make_pair mp
#define mod 1000000007
#define pi acos(-1.0)
#define mx 0
#define mn 10000000000000
#define first ft;
#define second snd;
#define inf 1e9
#define linf 1e18
#define eps 1e-9
using namespace std;
typedef vector<int> vi;
typedef vector<long> vl;
typedef map<int,int>mi;
typedef map<long,long>ml;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<long,long>pll;
using ll=long long;
using ld=long double;


int main()
{
    fast;
    int n,sum=0;
    cin>>n;
    int val[n+1];
    for(int i=0;i<n;i++){
        cin>>val[i];
        sum+=val[i];
    }
    sort(val,val+n);

    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++){

        for(int j=0;j<=sum;j++) dp[i][j]=false;
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {

            if(j==0 || (i==0 && j==0)) {
                dp[i][j]=true;
                continue;
            }
            if(i==0 && j>0) continue;
            if(val[i-1]<=j)
                dp[i][j]=(dp[i-1][j-val[i-1]]||dp[i-1][j]);

            else dp[i][j]=dp[i-1][j];
        }
    }

    set<int>s;
    for(int i=0;i<=n;i++){

        for(int j=1;j<=sum;j++) {
            if(dp[i][j]) s.insert(j);
        }
    }
    cout<<s.size()<<endl;
    for(auto i:s) cout<<i<<" ";
    cout<<endl;

    return 0;
}


