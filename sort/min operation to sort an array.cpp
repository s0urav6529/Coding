
/// Using no of coonected component we can find no of opearion to sort an array.

#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

vector<int>adj[limit];
bool vis[limit]={false};

int cycle;

void dfs(int node){

    vis[node] = true;

    for(int child : adj[node]){

        if(vis[child] == false){

            dfs(child);
        }

    }

}

void an1nd1ta(int tc){
    
    int n;
    cin >> n;

    int a[n+5];

    for(int i=1;i<=n;i++){

        adj[i].clear();
        vis[i] = false;
    }

    for(int i=1;i<=n;i++) {

        cin >> a[i];
        adj[i].pb(a[i]);

    }

    cycle = 0;
    for(int i=1;i<=n;i++){

        if(vis[i] == false){
            cycle++;
            dfs(i);
        }

    }

    int ans = n -cycle;
    
    cout<<ans<<endl;
    return;
}
