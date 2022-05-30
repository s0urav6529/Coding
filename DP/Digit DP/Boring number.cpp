#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);



/// Count all the number that has summation of digit equal to sum from 0 to R.


ll dp[20][2][2][2];

ll rec(string num,int len,int pos,int lead_zero,int tight){

    if(len==0) return 1;

    if( dp[len][pos][lead_zero][tight] !=-1)
        return dp[len][pos][lead_zero][tight];

    if(pos){ ///odd position

        ll ans=0,upper_digit=9;

        if(tight) upper_digit=(num[num.size()-len]-'0');

        if(lead_zero)
            ans+=rec(num,len-1,1,1,0);

        for(int digit=1; digit <= upper_digit ;digit+=2)
            ans+= rec(num , len-1 ,0 ,0 , (tight & (digit==upper_digit)));

        return dp[len][pos][lead_zero][tight]=ans;
    }
    else{

        ll ans=0,upper_digit=9;

        if(tight) upper_digit=(num[num.size()-len]-'0');

        for(int digit=0; digit <= upper_digit ;digit+=2)
            ans+= rec(num , len-1 ,1 ,0 , (tight & (digit==upper_digit)));

        return dp[len][pos][lead_zero][tight]=ans;
    }


}

int main(){
    fast;
    int tc;
    cin>>tc;
    for(int i=1;i<=tc;i++) {


        ll L,R; ///number basically R (right range)
        cin>>L>>R; L--;

        string RR=to_string(R),LL=to_string(L);

        memset(dp,-1,sizeof(dp));

        ll r= rec(RR,RR.size(),1,1,1);  ///number , number len , odd position , has leading zeo and tight cons.

        memset(dp,-1,sizeof(dp));

        ll l= rec(LL,LL.size(),1,1,1);

        cout<<"Case #"<<i<<": "<<r-l<<endl;
    }

    return 0;
}



