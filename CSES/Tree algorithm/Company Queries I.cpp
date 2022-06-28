#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
typedef unsigned long long int llu;

constexpr ll mod=1e9+7;
const int limit=2e5+5;
const int mx=21;

vector<int>g[limit];
int level[limit];
int LCA[limit][mx];


void dfs(int node,int p,int l) {

    level[node]=l;

    LCA[node][0]=p;

    for(int child:g[node]) {

        if(child!=p) {

            dfs(child,node,l+1);
        }
    }
}

int main(){
    fast;
    int n,q;
    cin>>n>>q;
    for(int i=2;i<=n;i++){
        int p;
        cin>>p;
        g[p].push_back(i);
        g[i].push_back(p);
    }

    memset(LCA,-1,sizeof(LCA));
    dfs(1,-1,0);

    for(int i=1;i<=mx;i++) {

        for(int j=1;j<=n;j++){

            if(LCA[j][i-1]!=-1) {

                int p=LCA[j][i-1];
                LCA[j][i]=LCA[p][i-1];
            }
        }
    }
    while(q--){

        int x,k;
        cin>>x>>k;

        while(k>0)  {
            int pos=log2(k);
            x=LCA[x][pos];
            k-=(1<<pos);
            if(x==-1) break;
        }
        cout<<x<<endl;
    }
    return 0;
}





