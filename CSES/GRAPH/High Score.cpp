#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int limit=2500;


vector<int>link[limit];
bool vis[limit];

struct edges{
    int src,des,w;
};

void dfs(int node){
    vis[node]=true;

    for(auto i:link[node]){
        if(vis[i]==false) dfs(i);
    }

}


int main(){
    fast;
    int n,e;
    cin>>n>>e;

    vector<edges>adj(e);

    vector<long long int>dis(n+1,1e18);

    for(int i=0;i<e;i++){

        int a,b,w;
        cin>>a>>b>>w;
        adj[i].src=a;
        adj[i].des=b;
        adj[i].w=(-1)*w;
        link[a].push_back(b);

    }

    dis[1]=0;
    bool isupdated=false;

    for(int i=1;i<n;i++){  /// updating n-1 times

        isupdated=false;

        for(int j=0;j<e;j++){

            int src=adj[j].src;
            int des=adj[j].des;
            int w=adj[j].w;



            if(dis[src]!=1e18 && dis[src]+w<dis[des]){

                isupdated=true;
                dis[des]=dis[src]+w;
            }
        }
        if(isupdated==false) break;
    }


    ///one more relaxation for detect cycle

    isupdated=true;

    for(int j=0;j<e;j++){

        int src=adj[j].src;
        int des=adj[j].des;
        int w=adj[j].w;

        if(dis[src]!=1e18 && dis[src]+w<dis[des]){

            dfs(src);
            dfs(des);
            if(vis[1] || vis[n]){   ///Are source and destination updated by cycle
                cout<<-1<<endl;
                return 0;
            }
        }
    }

    cout<<(-1ll)*dis[n]<<endl;
    return 0;
}

