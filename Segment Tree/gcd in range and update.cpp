

/// for building tree nlogn
/// for each query(Q) logn
///Time comlexity = (nlogn+(Q*logn))


#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n,q;
ll a[100005];
ll tree[100005*4];

void segment_tree(int node,int b,int e)
{
    if(b==e){
        tree[node]=a[b];
        return;
    }

    int left=node*2;
    int right=node*2+1;

    int mid=(b+e)/2;

    segment_tree(left,b,mid);
    segment_tree(right,mid+1,e);

    tree[node]=__gcd(tree[left],tree[right]);
}

ll find_gcd(int node,int b,int e,int l,int r)
{
    if(e<l || b>r)   ///invalid range
        return 0;

    if(b>=l && e<=r)   ///Relavent range
        return tree[node];

    int left=node*2;
    int right=node*2+1;

    int mid=(b+e)/2;

    ll GCD=__gcd(find_gcd(left,b,mid,l,r),find_gcd(right,mid+1,e,l,r));

    return GCD;
}

void update_node(int node,int b,int e,int in)
{
    if(b==e){
        tree[node]=a[in];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    if(in<=mid) update_node(left,b,mid,in);
    else update_node(right,mid+1,e,in);

    tree[node]=__gcd(tree[left],tree[right]);
}

int main()
{
    fast;
    cin>>n>>q;
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
