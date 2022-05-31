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
int tree[mx*4];
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

    tree[node]=tree[left]+tree[right];
}
void update(int node,int b,int e,int uin)
{
    if(b==e){
        tree[node]=a[uin];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    if(uin<=mid) update(left,b,mid,uin); ///calling left of right child which belongs this update index
    else update(right,mid+1,e,uin);

    tree[node]=tree[left]+tree[right]; ///update parent i because we update an child index of i
}

int main()
{
    fast;
    int uin,val;
    cin>>n;
    for(int i=1;i<=n;i++)  cin>>a[i];

    segment_tree(1,1,n);  ///build the segment tree

    cin>>uin>>val;
    a[uin]=val; ///updating the array value first
    update(1,1,n,uin); ///root index,left,right,update index

    return 0;
}






