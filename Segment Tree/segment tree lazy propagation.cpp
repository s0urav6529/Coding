#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define mod 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
#define mx 100005
int n;
int a[mx];
struct info{
    int prop,sum;
}tree[mx*4];

void segment_tree(int node,int b,int e){

    if(b==e){
        tree[node].sum=a[b];
        tree[node].prop=0;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    segment_tree(left,b,mid);
    segment_tree(right,mid+1,e);

    tree[node].sum=tree[left].sum+tree[right].sum;
    tree[node].prop=0;
}

void update(int node,int b,int e,int l,int r,int x){

    if(e<l || b>r) return;

    if(b>=l && e<=r){
        tree[node].sum+=((e-b+1)*x);
        tree[node].prop+=x;
        return;
    }

    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    update(left,b,mid,l,r,x);
    update(right,mid+1,e,l,r,x);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;

}
int query(int node,int b,int e,int l,int r,int carry){

    if(e<l || b>r) return 0;

    if(b>=l && e<=r){
        return tree[node].sum+carry*(e-b+1);
    }

    int left_c=node*2;
    int right_c=node*2+1;
    int mid=(b+e)/2;

    int q1=query(left_c,b,mid,l,r,carry+tree[node].prop);
    int q2=query(right_c,mid+1,b,l,r,carry+tree[node].prop);
    return q1+q2;
}

int main()
{
    fast;
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    segment_tree(1,1,n); ///built the segment tree
    while(q--){
        int l,r,val;
        cin>>l>>r>>val;
        update(1,1,n,l,r,val);  ///update the range
        cout<<query(1,1,n,l,r,0)<<endl; ///return the sum of the range
    }
    return 0;
}






