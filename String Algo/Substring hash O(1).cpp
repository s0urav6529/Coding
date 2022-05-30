
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
constexpr ll mod = 1e9+7;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
ll inv[100005]; ///storing every indexed modulu inverse
ll dp[100005]; ///storing every indexed hash value;

ll moduleInv(ll base,ll Pow)
{
    ll res=1;
    while(Pow)
    {
        if(Pow&1) res=(res*base)%mod;
        Pow/=2;
        base=(base*base)%mod;
    }
    return res;
}
void hashit(string s)
{
    ll hash_value=0;
    ll Prime=31;
    ll Prime_power=1;/// initially p^0=1
    dp[-1]=0;
    for(int i=0;i<s.size();i++)
    {
        dp[i]=(dp[i-1]+((s[i]-'a'+1)*Prime_power))%mod;  ///storing hash value for every index

        inv[i]=moduleInv(Prime_power,mod-2)%mod; ///storing every indexed modulu inverse

        Prime_power=(Prime_power*Prime)%mod;  ///increasing prime power after every iteration
    }

}
ll hashvalue(int LL,int RR)
{
    ll res=dp[RR];

    res=(res-dp[LL-1]+mod)%mod;

    res=(res*inv[LL]) % mod;   ///Hash("")= (substring(left,right)*inver(left)) % mod

    return res;
}
int main()
{
    fast;
    //read;
    //out;
    int tc=1;
    cout<<"Enter a string "<<endl;
    string s;
    cin>>s;
    hashit(s); ///Hashing all the string
    cout<<"Enter test case"<<endl;
    cin>>tc;
    for(int z=1;z<=tc;z++)
    {
        int left,right;
        cin>>left>>right;
        left--,right--; ///0 base
        cout<<"Hashing value is = "<<hashvalue(left,right)<<endl; ///Returnig hash value of left from right
    }
    return 0;
}





