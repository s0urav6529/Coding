#include<bits/stdc++.h>
using namespace std;
double fun(int a,int b,int m)
{
    double result=a*(1/b);cout<<result<<endl;
    result=((a%m)*(result%m))%m;
    return result;
}
int main()
{
    int a,m,b;
    cin>>a>>b>>m;
    cout<<fun(a,b,m)<<endl;
    return 0;
}

