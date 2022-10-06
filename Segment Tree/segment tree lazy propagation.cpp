#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
const int limit=1e5+5;

int a[limit];

struct Node{
    int prop;
    int sum;
}st[limit << 2];


void segment_tree(int node,int b,int e){

    if(b==e){
        st[node].sum = a[b];
        st[node].prop=0;
        return;
    }

    int mid=(b+e)/2;

    segment_tree(node << 1 , b, mid);
    segment_tree(node << 1 | 1, mid+1, e);

    st[node].sum=st[node << 1].sum + st[node << 1 | 1].sum;

    st[node].prop=0;
}

void update(int node,int b,int e,int l,int r,int val){

    if(e<l || b>r) return;

    if(b>=l && e<=r){

        st[node].sum += ((e-b+1)*val);
        st[node].prop += val;
        return;

    }

    int mid=(b+e)/2;

    update(node << 1, b, mid, l, r, val);
    update(node << 1 | 1, mid+1, e, l, r, val);

    st[node].sum = st[node << 1].sum + st[node << 1 | 1].sum + (e-b+1 )*st[node].prop;

}
int query(int node,int b,int e,int l,int r,int carry){

    if(e<l || b>r) return 0;

    if(b>=l && e<=r){
        return st[node].sum + carry*(e-b+1);
    }

    int mid=(b+e)/2;

    int q1 = query(node << 1 , b, mid, l, r, carry+st[node].prop);

    int q2 = query(node << 1 | 1, mid+1, b, l, r, carry+st[node].prop);

    return q1+q2;
}

int main(){

    fast;
    int q , n;
    cin>> n >> q;
    for(int i=1;i<=n;i++) cin>>a[i];

    segment_tree(1,1,n); ///built the segment tree

    while(q--){
        int l,r,val;

        cin>>l>>r>>val;

        update(1,1,n,l,r,val);  ///update the range

        cout<<query(1,1,n,l,r,0)<<endl; ///return the sum of the range

    }
    return 0;
}

