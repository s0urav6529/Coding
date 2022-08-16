
///EKTA ARRAY DEOYA THAKBE JEKAN HOTE AMAKE MAXIMUM SUM ER SUBARRAY KHUJE BER KORTE HBE JA LENGHT K;
///complexity O(n)


#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a[100],ans=-1,sum=0;
    a[0]=0;
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {

        if(i>=k)
        {
            sum+=a[i]-a[i-k];
        }
        else sum+=a[i];
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}
