
///time coplexity O(log(n))

///amader kno base er power ber korar jonno binary exponentiation use korte hoi;

#include<bits/stdc++.h>
#include<math.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int binaryex(int base,int pow)
{
    int res=1;
    while(pow)
    {
        if(pow%2)
            res*=base,pow--;
        else base*=base,pow/=2;
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
        int base,pow;
        cin>>base>>pow;
        cout<<binaryex(base,pow)<<endl;
    }
    return 0;
}




