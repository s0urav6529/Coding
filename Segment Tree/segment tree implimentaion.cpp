#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int limit=2e5+5;
typedef long long int ll;

int a[limit];
int st[limit << 2];

void segment_tree(int node,int b,int e){

    if(b==e){
        st[node]=a[b];
        return;
    }

    int mid=(b+e)/2;

    segment_tree( node << 1, b, mid );
    segment_tree( node << 1 | 1, mid+1, e );

    st[node]= st[node << 1] + st[node << 1 | 1];

}

int main(){
    fast;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) //entering the array
        cin>>a[i];
    segment_tree(1,1,n);  ///bulid the segment tree
    for(int i=1;i<=20;i++) cout<<st[i]<<" ";
    return 0;
}





