#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define mod 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
#define mxx 100005
int n;
int a[mxx];
int tree[mxx*4];
void segment_tree(int node,int b,int e)
{
    if(b==e){
        tree[node]=a[b];
        return;
    }
    int left_c=node*2;
    int right_c=node*2+1;
    int mid=(b+e)/2;

    segment_tree(left_c,b,mid);
    segment_tree(right_c,mid+1,e);

    tree[node]=max(tree[left_c],tree[right_c]);
}
int mx(int node,int b,int e,int l,int r)
{
    if(e<l || b>r)
        return -1000;

    if(b>=l && e<=r)
        return tree[node];

    int left_c=node*2;
    int right_c=node*2+1;
    int mid=(b+e)/2;

    return max(mx(left_c,b,mid,l,r),mx(right_c,mid+1,e,l,r));
}

int main()
{
    fast;
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) //entering the array
        cin>>a[i];
    segment_tree(1,1,n);  ///build the segment tree

    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<mx(1,1,n,l,r)<<endl;
    }
    return 0;
}






