
/// update k th pos with v

/// find the maxmim sum subarray from L to R

/// Problem link : https://www.spoj.com/problems/GSS3/


#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;

const int limit=5e4+5;

struct Node{

    ll tsum;
    ll pref;
    ll suff;
    ll maxsub;

    Node(){
        tsum = maxsub = pref = suff =-1e16;
    }

}st[limit << 2];

ll a[limit];


Node Marge(Node left,Node right){

    Node parentnode;

    parentnode.tsum=left.tsum+right.tsum;

    parentnode.pref=max(left.pref, left.tsum + right.pref);

    parentnode.suff=max(right.suff,right.tsum+left.suff);

    parentnode.maxsub=max(max(left.maxsub,right.maxsub),left.suff+right.pref);

    return parentnode;
}



void built_tree(int node,int b,int e){

    if(b==e){
        st[node].tsum= st[node].pref= st[node].suff= st[node].maxsub= a[b];
        return;
    }

    int mid=(b+e)/2;

    built_tree(node << 1,b,mid);
    built_tree(node << 1 | 1,mid+1,e);

    st[node] = Marge(st[node << 1] ,st[node << 1 | 1]);
}

void update(int node,int b,int e,int pos,int val){

    if(b==e){
        st[node].tsum = st[node].pref = st[node].suff = st[node].maxsub = a[b] = val;
        return;
    }

    int mid=(b+e)/2;

    if(pos<=mid)
        update(node << 1,b,mid,pos,val);

    else
        update(node << 1 | 1,mid+1,e,pos,val);

    st[node] = Marge(st[node << 1],st[node << 1 |1]);
}


Node query(int node,int b,int e,int l,int r){


    if(e<l || b>r) {
        Node emptynode;
        return emptynode;
    }

    if(b>=l && e<=r){
        return st[node];
    }

    int mid=(b+e)/2;

    Node left=query(node << 1,b,mid,l,r);
    Node right=query(node << 1 | 1,mid+1,e,l,r);

    Node ans=Marge(left,right);
    return ans;

}

int main(){
    fast;
    int n,q;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];

    built_tree(1,1,n);

    cin>>q;
    for(int i=0;i<q;i++){

        int type,pos,val,l,r;
        cin>>type;
        if(!type){

            cin>>pos>>val;
            update(1,1,n,pos,val);

        }
        else{
            cin>>l>>r;
            cout<<query(1,1,n,l,r).maxsub<<endl;
        }

    }
    return 0;
}


