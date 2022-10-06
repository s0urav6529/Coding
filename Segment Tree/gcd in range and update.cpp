

/// for building tree nlogn
/// for each query(Q) logn
///Time comlexity = (nlogn+(Q*logn))


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int limit=2e5+5;

int n,q;
ll a[limit];
ll tree[limit << 2];

void segment_tree(int node,int b,int e){

    if(b==e){
        tree[node]=a[b];
        return;
    }

    int mid=(b+e)/2;

    segment_tree(node << 1, b,  mid);
    segment_tree(node << 1 | 1, mid+1, e);

    tree[node]=__gcd(tree[node  << 1],tree[node << 1 | 1]);
}

ll find_gcd(int node,int b,int e,int l,int r){

    if(e<l || b>r)   ///invalid range
        return 0;

    if(b>=l && e<=r)   ///Relavent range
        return tree[node];

    int mid=(b+e)/2;

    ll GCD=__gcd(find_gcd(node << 1, b, mid , l , r),find_gcd(node << 1 | 1, mid+1, e, l, r));

    return GCD;
}

void update_node(int node,int b,int e,int index){

    if(b==e){
        tree[node]=a[index];
        return;
    }

    int mid=(b+e)/2;

    if(index<=mid) update_node(node << 1 ,b ,mid, index);
    else update_node(node << 1 | 1, mid+1, e, index);

    tree[node]=__gcd(tree[node << 1],tree[node << 1 | 1]);
}

int main(){

    cin>> n >> q;
    for(int i=1;i<=n;i++) cin>>a[i];

    segment_tree(1,1,n); ///build segment tree

    while(q--){
        int type;
        cin>>type;

        if(type==1){
            int l,r;
            cin>>l>>r;
            cout<<find_gcd(1,1,n,l,r)<<endl;
        }

        else{
            int in,val;
            cin>>in>>val;
            a[in]=val;
            update_node(1,1,n,in);
        }
    }
    return 0;
}


