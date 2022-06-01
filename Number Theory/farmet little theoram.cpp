#include<bits/stdc++.h>
using namespace std;
int fun(int a,int n,int m)
{
    int result=1;
    while(n)
    {
        if(n%2)result=(result*a)%m;
        n/=2;
        a=(a*a)%m;
    }
    return result;
}
int main()
{
    int a,m;
    cin>>a>>m;
    cout<<fun(a,m-2,m)<<endl;
    return 0;
}
