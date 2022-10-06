

/// for building tree nlogn
/// for each query(Q) logn
///Time comlexity = (nlogn+(Q*logn))


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int limit=2e5+5;


int a[limit];
int st[limit << 2];

void segment_tree(int node,int b,int e){

    if(b==e){
        st[node] = a[b];
        return;
    }

    int mid=(b+e)/2;

    segment_tree(node << 1, b, mid);
    segment_tree(node << 1 | 1, mid+1, e);

    st[node]=st[node << 1] + st[node << 1 | 1];
}

int range_sum(int node,int b,int e,int l,int r){

    if(l>e || r<b) ///out of range
        return 0;

    if(b>=l && e<=r)  ///relevent range
        return st[node];


    int mid=(b+e)/2;

    return range_sum(node << 1 , b, mid, l, r)+range_sum(node << 1 | 1, mid+1, e, l ,r);
}

int main(){

    int q , n;
    cin>> n>> q;

    for(int i=1;i<=n;i++) cin>>a[i];

    segment_tree(1,1,n);  ///build segment tree

    while(q--){

        int l,r;
        cin>>l>>r;
        cout<<range_sum(1,1,n,l,r)<<endl;
    }

    return 0;
}


