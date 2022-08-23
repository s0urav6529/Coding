#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e2+5;

int main(){
    fast;
    ll n,k,sum=0;
    cin>>n>>k;

    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }

    ll l=1,r=sum,ans=sum;

    while(l<=r){

        ll mid=l+(r-l)/2;
        ll part=1,sum=0;
        for(int i=0;i<n;i++){

            if(a[i]>mid) {
                part=k+1;
                break;
            }
            if(sum+a[i]<=mid) sum+=a[i];
            else{
                sum=a[i];
                part++;
            }
        }
        //cout<<mid<<" "<<part<<endl;
        if(part<=k){
            ans=min(ans,mid);
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans<<endl;



    return 0;
}


