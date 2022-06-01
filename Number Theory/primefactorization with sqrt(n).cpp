
///time coplexity O(sqrt(n))

#include<bits/stdc++.h>
#include<math.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    fast;
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,N;
        cin>>n;
        N=n;
        for(int i=2;i*i<=N;i++)
        {
            if(n%i==0)
            {
                int cnt=0;
                while(n%i==0)
                {
                    cnt++;
                    n/=i;
                }
                cout<<i<<"^"<<cnt<<endl;
            }
        }
        if(n>1) cout<<n<<"^"<<1<<endl;
    }
    return 0;
}



