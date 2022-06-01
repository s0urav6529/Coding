
///time coplexity O(log(n))

///amader kno base er power ber korar jonno binary exponentiation use korte hoi
/// and jodi mod kore ans ber korte tokhan modular exponentiation use kora lagbe

#include<bits/stdc++.h>
#include<math.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int binaryex(int base,int pow,int mod)
{
    int res=1;
    while(pow)
    {
        if(pow%2)
            res=(res*base)%mod,pow--;
        else base=(base*base)%mod,pow/=2;
    }
    return res;
}
int main()
{
    fast;
    int tc;
    cin>>tc;
    while(tc--)
    {
        int base,pow,mod;
        cin>>base>>pow>>mod;
        cout<<binaryex(base,pow,mod)<<endl;
    }
    return 0;
}





