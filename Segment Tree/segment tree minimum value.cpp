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
    segment_tree(node << 1 |1 , mid+1, e);

    st[node]=min(st[node << 1],st[node << 1 |1]);

}

int Minimum_value(int node,int b,int e,int l,int r){

    if(e<l || b>r)
        return 1000;///invalid return

    if(b>=l && e<=r)
        return st[node];

    int mid=(b+e)/2;

    return min(Minimum_value(node << 1 , b, mid, l, r) , Minimum_value(node << 1 | 1, mid+1, e, l ,r));
}

int main(){

    int q , n;
    cin>>n >> q;

    for(int i=1;i<=n;i++)  cin>>a[i];

    segment_tree(1,1,n); ///Bulid segment tree

    while(q--) {
        int l,r;
        cin>>l >> r; ///range
        cout<<Minimum_value(1,1,n,l,r)<<endl;
    }
    return 0;
}



