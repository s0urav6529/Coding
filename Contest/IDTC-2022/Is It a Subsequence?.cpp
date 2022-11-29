#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e5+5;


int main(){
    fast;
    ll n,q;
    cin>>n>>q;

    map<int,vector<int>>mp;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x].push_back(i);
    }

    while(q--){

        int m;
        cin>>m;

        map<int,int>point;
        int prev=-1;
        bool ok=true;

        for(int i=0;i<m;i++){
            int x;
            cin>>x;

            if(ok==false) continue;

            if(mp.find(x)==mp.end()){
                ok=false;
                continue;
            }

            int pos=point[x];

            bool paisi=false;

            for(int j=pos;j<mp[x].size();j++){

                //cout<<x<<" "<<prev<<" "<<mp[x][j]<<endl;

                if(mp[x][j]>prev) {

                    prev=mp[x][j];
                    point[x]=j+1;
                    paisi=true;

                    break;
                }
            }

            if(paisi==false) ok=false;

        }

        if(ok) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
    return 0;
}


