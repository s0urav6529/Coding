#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
const int limit=2e5+5;


int main(){
    fast;

    int n;
    cin>>n;
    vector<ll>a(n);

    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());

    ll sum=0;

    for(int i=0;i<n-1;i++) sum+=a[i];

    if(sum<a[n-1]) {
        cout<<2ll*a[n-1]<<endl;
    }
    else cout<<sum+a[n-1]<<endl;


    return 0;
}



