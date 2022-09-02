#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define mod 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
const int limit=2e5+5;

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





