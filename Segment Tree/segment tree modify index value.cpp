#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
typedef long double ld;
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

    st[node]= st[node << 1] | st[node << 1 | 1];

}

void update(int node,int b,int e,int id){

    if(b==e){
        st[node]=a[id];
        return;
    }

    int mid=(b+e)/2;

    if(id<=mid) update(node << 1, b, mid, id);
    else update(node << 1 | 1 ,mid+1, e, id);

    st[node]= st[node << 1] | st[node << 1 | 1];
}


void run_case(){

    int n,m;
    cin >> n >> m;

    for(int i=1;i<=n;i++) cin>>a[i];

    segment_tree(1,1,n);


    while(m--){   ///update index with value

        int id,v;
        cin >> id >> v;

        a[id]=v;

        update(1,1,n,id);

        cout<<st[1]<<endl;   ///result after changes
    }


    return;
}

int main(){
    fast;
    int tc=1;
    //cin>>tc;
    while(tc--) run_case();
    return 0;
}

