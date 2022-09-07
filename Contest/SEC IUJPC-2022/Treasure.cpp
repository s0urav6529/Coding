#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e2+5;

int main(){
    fast;
    ll n,m; cin>>n>>m;

    for(int i=0;i<m;i++){

        string s; cin>>s;

        if(s=="in") n++;
        else n--;

        if(n<4) {
            cout<<"YES"<<endl;
            return 0;
        }

    }
    cout<<"NO"<<endl;



    return 0;
}



