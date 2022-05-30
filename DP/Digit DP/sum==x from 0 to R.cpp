#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);



/// Count all the number that has summation of digit equal to sum from 0 to R.


ll dp[20][175][2];

ll rec(string num,int len,int sum,int tight){

    if(sum<0) return 0;

    if(len==0){
        if(sum==0) return 1;
        else return 0;
    }

    if(dp[len][sum][tight]!=-1)
        return dp[len][sum][tight];

    int upper_digit=9;

    if(tight) upper_digit=(num[num.size()-len]-'0');

    ll ans=0;
    for(int digit=0; digit<=upper_digit; digit++){

        ans+= rec(num, len-1, sum-digit , (tight&(digit==upper_digit)) );

    }
    return dp[len][sum][tight]= ans;

}

int main(){
    fast;
    ll R; /// right range
    int sum;
    cin>>R>>sum;

    string num=to_string(R);

    memset(dp,-1,sizeof(dp));

    cout<<rec(num,num.size(),sum,1)<<endl;

    return 0;
}


