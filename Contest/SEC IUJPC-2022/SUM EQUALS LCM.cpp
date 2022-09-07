#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e2+5;



int main(){
    fast;

    int tc; cin >> tc;

    while(tc--){

        ll n; cin >> n;

        if(n==1){
            cout<< 1 <<endl;
            continue;
        }
        if(n==2){
            cout<< -1 <<endl;
            continue;
        }

        vector<ll>ans(n+1);

        ans[n]=n;
        ans[n-1]=n-1;
        ans[1]=1;

        for(int i=2;i<n-1;i++) ans[i]=n;

        for(int i=1;i<=n;i++) cout<< ans[i] <<" ";

        cout<<endl;

    }
    return 0;
}



