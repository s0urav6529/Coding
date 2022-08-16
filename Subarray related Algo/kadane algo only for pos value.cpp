#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); ///msf=most so far meh=maximum hightest
using namespace std;
int a[100];
int main()
{
    fast;
    int n,max_here=0,max_so_far=0,Start=1,End=1,s=1;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        max_here+=a[i];
        if(max_so_far<max_here)
        {
            max_so_far=max_here;Start=s;End=i;
        }
        if(max_here<0)
        {
            max_here=0;
            s=i+1; ///Next value will contains max
        }
    }
    cout<<Start<<" "<<End<<" "<<max_so_far<<endl;
    return 0;
}


