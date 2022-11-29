


#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
constexpr ll MOD=998244353;
const int limit=2e5+5;

int main(){
    fast;
    int tc=1;
    cin>>tc;
    while(tc--){

        ll x,y;
        cin>>x>>y;
        if(x>y){
            cout<<-1<<endl;
            continue;
        }
        ll dif=y-x,ans=0;

        for(ll i=0;i<=32;i++){

            if((dif&(1ll<<i))){
                ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}




