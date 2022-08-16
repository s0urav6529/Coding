
///EKTA ARRAY DEOYA THAKBE JEKAN HOTE AMAKE SUB ARRRY # KORTE HBE JADER X-OR EQUAL ITS SUM
///COMPLEXITY O(n)

#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a[100],ans=0,x=0,r=1;
    a[0]=0;
    int n,k;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int l=1;l<=n;l++)
    {
        while(r<=n&&((x^a[r])==x+a[r]))
        {
            x+=a[r];
            r++;
        }
        ans+=r-l;
        if(l==r) r++;
        else x-=a[l];
    }
    cout<<ans<<endl;
    return 0;
}
