#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
constexpr ll mod = 1e9+7;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
ll hashit(string s)
{
    ll Hash_value=0;
    ll power_value=1; ///initially p^0=1;
    ll p=31; ///Taking a prime number
    for(char c:s)
    {
        Hash_value=(Hash_value+(c-'a'+1)*power_value)%mod; ///calculating hash value
        power_value=(power_value*p)%mod; ///increasing prime power after every iteration
    }
    return Hash_value;
}
int main()
{
    fast;
    //read;
    //out;
    int tc=1;
    cin>>tc;
    for(int z=1;z<=tc;z++)
    {
        string s;
        cin>>s;
        cout<<"Hashing value is = "<<hashit(s)<<endl;
    }
    return 0;
}


