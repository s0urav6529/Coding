#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int limit=1005;

struct edges{
    int src,des,w;
};

int main(){
    fast;
    int n,e;
    cin>>n>>e;

    vector<edges>adj(e);
    vector<int>Parent(n+1,-1),dis(n+1,1e9);

    for(int i=0;i<e;i++){

        int a,b,w;
        cin>>a>>b>>w;
        adj[i].src=a;
        adj[i].des=b;
        adj[i].w=w;

    }

    dis[1]=0;
    bool isupdated=false;

    for(int i=1;i<n;i++){  /// updating n-1 times

        isupdated=false;

        for(int j=0;j<e;j++){

            int src=adj[j].src;
            int des=adj[j].des;
            int w=adj[j].w;

            if(dis[src]!=1e9 && dis[src]+w<dis[des]){

                isupdated=true;
                dis[des]=dis[src]+w;
                Parent[des]=src;
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

        if(dis[src]!=1e9 && dis[src]+w<dis[des]){

            ///negative edge cycle
            cout<<"This graph has -ve edge cycle "<<src<<" "<<des<<endl;
            //return 0;

        }
    }

    for(int i=1;i<=n;i++) cout<<Parent[i]<<" ";
    cout<<endl;
    return 0;
}

