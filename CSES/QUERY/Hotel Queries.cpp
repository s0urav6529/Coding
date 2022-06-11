#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int limit=200005;


struct segment{
    int val,idx;
};
segment tr[4*limit];
int a[limit],s[limit];


void built_tree(int node,int l,int r){

    if(l==r){
        tr[node].val=a[l];
        tr[node].idx=l;
        return;
    }

    int mid=(l+r)/2;
    int left=node*2;
    int right=node*2+1;

    built_tree(left,l,mid);
    built_tree(right,mid+1,r);

    if(tr[left].val>=tr[right].val)
        tr[node]=tr[left];

    else tr[node]=tr[right];

}

int query(int node,int l,int r,int num){

    if(tr[node].val<num){
        return 0;
    }

    if(l==r){
        tr[node].val-=num;
        return tr[node].idx;
    }

    int mid=(l+r)/2;
    int left=node*2;
    int right=node*2+1;

    int index=0;
    if(tr[left].val>=num){
        index=query(left,l,mid,num);
    }
    else{
        index=query(right,mid+1,r,num);
    }

    if(tr[left].val>=tr[right].val){
        tr[node]=tr[left];
    }
    else{
        tr[node]=tr[right];
    }

    return index;
}



void run_case(){

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    built_tree(1,1,n);

    for(int i=1;i<=m;i++) {
        int num;
        cin>>num;
        cout<<query(1,1,n,num)<<" ";
    }
    cout<<endl;


    return;
}

int main(){
    fast;
    int tc=1;
    //cin>>tc;
    while(tc--) run_case();
    return 0;
}


