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
void segment_tree(int node,int b,int e){
    if(b==e){

        tree[node]=a[b];
        return;
    }

    int left_c=node*2;
    int right_c=node*2+1;

    int mid=(b+e)/2;

    segment_tree(left_c,b,mid);

    segment_tree(right_c,mid+1,e);

    tree[node]=tree[left_c]+tree[right_c];
}

int main(){
    fast;
    cin>>n;
    for(int i=1;i<=n;i++) //entering the array
        cin>>a[i];
    segment_tree(1,1,n);  ///bulid the segment tree
    for(int i=1;i<=20;i++) cout<<tree[i]<<" ";
    return 0;
}





