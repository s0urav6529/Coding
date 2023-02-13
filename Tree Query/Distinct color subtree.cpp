
Problem link : Distinct Colors : https://cses.fi/problemset/task/1139

#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;

const int MAX_N = 2e5+5;

int N,M;

vector<int> adj[MAX_N];
int color[MAX_N];


vector<int> children[MAX_N];
void dfs(int node, int par){

    for(int ch:adj[node]){
        if(ch!=par){
            dfs(ch,node);
            children[node].push_back(ch);
        }
    }
}

vector<int> inorder;
void order(int node){

    for(int ch:children[node])
        order(ch);

    inorder.push_back(node);
}

int distinct[MAX_N];
int idx[MAX_N];
set<int> subtree[MAX_N];


void countElements(int node){

    int mxChild=0,big=node;

    for(int ch:children[node]){

        int k=subtree[idx[ch]].size();

        if(k>mxChild){

            mxChild=k;
            big=idx[ch];
        }
    }

    for(int ch:children[node]){

        if(idx[ch]!=big){

            for(set<int>::const_iterator it=subtree[idx[ch]].begin();it!=subtree[idx[ch]].end();it++)
                subtree[big].insert(*it);

            subtree[idx[ch]].clear();
        }
    }

    subtree[big].insert(color[node]);

    distinct[node]=subtree[big].size();

    idx[node]=big;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);


    cin>>N>>M;

    for(int i=1;i<N;i++){
        int u,v;
        cin>>u>>v;
        --u;--v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0;i<N;i++) cin>>color[i];

    dfs(0,-1);
    order(0);

    for(int i=0;i<(int)inorder.size();i++)
        countElements(inorder[i]);


    for(int i=0;i<M;i++){
        int s;
        cin>>s;
        --s;
        cout<<distinct[s]<<endl;
    }

    return 0;
}
