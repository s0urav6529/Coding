#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define pb push_back
const int limit=200001;

vector<int>Parent(limit,-1);
vector<int>Rank(limit,1); ///Rank means size of this cc

int Find(int a){

    if(Parent[a]<0) return a;

    return Parent[a]=Find(Parent[a]);

}

void Union(int a,int b){

    a=Find(a);
    b=Find(b);

    if(a!=b){

        if(Rank[b]>Rank[a]) swap(a,b);
        Parent[b]=a;
        Rank[a]+=Rank[b];
    }
}

void solution(){

    int n,m;
    cin>>n>>m;
//    vector<pair<int,pair<int,int>>>tree(n-1);
//
//    for(int i=0;i<n-1;i++){
//        int a,b,w;
//        cin>>tree[i].ss.ff>>tree[i].ss.ss>>tree[i].ff;
//    }
//    sort(tree.begin(),tree.end());
//
//    for(int i=0;i<n-1;i++){
//
//        Union(tree[i].ss.ff,tree[i].ss.ss,tree[i].ff);
//    }
    while(m--){
        int a,b;
        cin>>a>>b;
        Union(a,b);
    }

    return;
}
int main()
{
    fast;
    //read;
    //out;
    int tc=1;
    //cin>>tc;
    while(tc--) solution();
    return 0;
}


