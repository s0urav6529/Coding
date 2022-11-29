


#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Fin freopen ("in.txt","r",stdin);
#define Fout freopen ("out1.txt","w",stdout);
typedef long long int ll;
constexpr ll MOD=1000000007;
const int limit=2e5+5;

int main(){
    fast;
    int tc=1;
    cin>>tc;
    while(tc--){

        ll n;
        cin>>n;
        ll a[n+3];

        for(int i=1;i<=n;i++) cin>>a[i];

        ll ans=0;

        for(ll i=1;i<=n;i++){

            ll ct1=0,ct2=0;
            for(ll j=1;j<i;j++) {
                if(a[i]>=a[j]) ct1++;
            }
            for(int j=i+1;j<=n;j++){
                if(a[i]<a[j]) ct2++;
            }

            ans=(ans+(ct1*ct2)%MOD)%MOD;

        }
        cout<<ans<<endl;

    }

    return 0;
}






