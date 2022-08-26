#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e6+5;

ll n,m;
vector<ll>Parent(limit);

ll Find(ll a){

    if(Parent[a]==a) return a;

    return Parent[a]=Find(Parent[a]);

}

void Union(ll a,ll b){

    Parent[a]=Parent[b];
}

int main(){
    fast;

    ll tc=1;
    cin>>tc;

    for(int t=1;t<=tc;t++){

        cin>>n>>m;

        for(int i=1;i<=n+1;i++) Parent[i]=i;

        cout<<"Case "<<t<<": "<<endl;

        while(m--){

            ll type,x;
            cin>>type>>x;

            if(type==1){
                Union(x,x+1);
            }
            else{
                cout<<Find(x)<<endl;
            }

        }

    }

    return 0;
}



