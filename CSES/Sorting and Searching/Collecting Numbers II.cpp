#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
typedef unsigned long long int llu;

constexpr ll mod=1e9+7;
const int limit=2e5+5;


int main(){
    fast;
    int tc=1;
    //cin>>tc;
    while(tc--){
        int n,q;
        cin>>n>>q;
        vector<int>pos(n+1),a(n+1);
        pos[0]=n+1;

        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            pos[x]=i;
            a[i]=x;
        }

        int round=0;
        for(int i=1;i<=n;i++){
            if(pos[i]<pos[i-1]) round++;
        }

        while(q--){

            int x,y;
            cin>>x>>y;

            set<pair<int,int>>p;

            p.insert({a[x]-1,a[x]});
            p.insert({a[y]-1,a[y]});

            if(a[x]+1<=n) p.insert({a[x],a[x]+1});
            if(a[y]+1<=n) p.insert({a[y],a[y]+1});

            for(auto i:p){

                int x=pos[i.first];
                int y=pos[i.second];

                if(x>y) round--;
            }

            swap(pos[a[x]],pos[a[y]]);
            swap(a[x],a[y]);

            for(auto i:p){

                int x=pos[i.first];
                int y=pos[i.second];

                if(x>y) round++;
            }
            cout<<round<<endl;
        }


    }
    return 0;
}






