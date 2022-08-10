#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
typedef unsigned long long int llu;

constexpr ll mod=1e9+7;
const int limit=2e5+5;


int main(){
    fast;
    int tc;
    int n;
    cin>>n;
    int a[n+2];
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);

    if(n&1){

        int mid=(n+1)/2;

        ll ans=0;

        for(int i=1;i<=n;i++) ans+=abs(a[mid]-a[i]);

        cout<<ans<<endl;

    }
    else{

        ll ans=0;

        int mid=n/2;

        for(int i=1;i<=n;i++) ans+=abs(a[mid]-a[i]);

        mid=mid+1;
        ll temp=0;

        for(int i=1;i<=n;i++) temp+=abs(a[mid]-a[i]);

        cout<<min(ans,temp)<<endl;
    }


    return 0;
}





