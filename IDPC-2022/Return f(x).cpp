///God is Almighty
///Author:SMU_coder

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen("in.txt","r",stdin);
#define pb push_back
#define pi acos(-1.0)
#define ff fast
#define ss second
#define sortv(k) sort(k.begin(),k.end())
#define rev(k) reverse(k.begin(),k.end())
constexpr ll MOD=1e9+7;
const int limit=1000006;

ll dp[limit];

int rec(int n){
    //cout<<n<<endl;
    if(n==1) return 1;

    if(dp[n]!=-1) return dp[n];

    ll ans=n+1;

    for(int i=2;i*i<=n;i++){

        if(n%i==0){
           if((n/i)!=i) ans+=rec(n/i);
           ans+=rec(i);
        }

    }
    return dp[n]=ans;
}

void run_case(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));

    cout<<rec(n)<<endl;

    return;
}

int  main(){
    fast;
    //read;
    int tc=1;
    //cin>>tc;
    while(tc--) run_case();
    return 0;
}
