
///EKTA ARRAY DEOYA THAKBE KOTOGULU QUARY CHALIE INCREMENT K KORE FINAL STATE ANS DITE HBE;
///complexity O(n)


#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a[100],b[100];
    memset(b,0,sizeof(b));
    b[0]=0;
    int n,k,q;
    cin>>n>>k>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        b[l]+=k;
        if(r+1<=n) b[r+1]-=k;
    }
    for(int i=1;i<=n;i++)
    {
        b[i]+=b[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        a[i]+=b[i];
    }
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
