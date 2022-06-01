#include<iostream>
using namespace std;
int totient(int n)
{
    int res=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n=n/i;
            }
            res-=(res/i);
        }
    }
    if(n>1)
        res-=(res/n);
    return res;
}
int main()
{
    int n,c=0;
    cin>>n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            c=1;
            break;
        }
    }
    if(c==1)
    {
        cout<<totient(n)<<endl;
    }
    else
        cout<<n-1<<endl;
    return 0;
}
