#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void init_code(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

}

ll dp[12][2];

ll cnt(string num,int len,int tight){

    if(tight==0) {

        ll ans=1;
        for(int i=1;i<=len;i++) ans*=10;

        return ans;

    }

    if(len==0) return 1;

    ll ans=0;

    int upper_digit=num[num.size()-len]-'0';

    for(int digit=0;digit<=upper_digit;digit++)
        ans+= cnt(num , len-1 , (tight&(digit==upper_digit)));

    return ans;

}


ll rec(string num,int len,int tight){

    if(len==0)
        return 0;

    if(dp[len][tight]!=-1)
        return dp[len][tight];

    int upper_digit=9;

    if(tight) upper_digit=(num[num.size()-len]-'0');


    ll ans=0;

    for(int digit=0;digit<=upper_digit;digit++) {

        ans+=(digit * cnt(num, len-1, (tight&(digit==upper_digit) )));  ///contribution of this digit

        ans+=rec(num, len-1, (tight&(digit==upper_digit)));
    }
    return dp[len][tight]=ans;

}

int main(){
    fast;

    while(1){
        ll l,r;
        cin>>l>>r;

        if(l==-1 && r==-1) break;

        if(l) l--;
        string LL=to_string(l),RR=to_string(r);

        memset(dp,-1,sizeof dp);

        ll R=rec(RR,RR.size(),1);

        memset(dp,-1,sizeof dp);

        ll L=rec(LL,LL.size(),1);

        cout<<R-L<<endl;
    }
    return 0;
}



