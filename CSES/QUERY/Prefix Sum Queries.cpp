#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;

const int limit=2e5+5;


struct node{

    ll maxprefix;
    ll totalsum;
};
node tr[4*limit];
ll a[limit];

void built_tree(int ci,int s,int e){

    if(s==e){
        tr[ci].totalsum=tr[ci].maxprefix=a[s];
        return;
    }

    int mid=(s+e)/2;
    built_tree(2*ci,s,mid);
    built_tree(2*ci+1,mid+1,e);

    tr[ci].totalsum=tr[2*ci].totalsum+tr[2*ci+1].totalsum;
    tr[ci].maxprefix=max(tr[2*ci].maxprefix,tr[2*ci].totalsum+tr[2*ci+1].maxprefix);

}

void update(int ci,int s,int e,int idx,ll val){

    if(idx<s || idx>e) return;

    if(s==e && s==idx){
        tr[ci].totalsum=tr[ci].maxprefix=a[idx]=val;
        return;
    }

    int mid=(s+e)/2;

    update(2*ci,s,mid,idx,val);
    update(2*ci+1,mid+1,e,idx,val);

    tr[ci].totalsum=tr[2*ci].totalsum+tr[2*ci+1].totalsum;
    tr[ci].maxprefix=max(tr[2*ci].maxprefix,tr[2*ci].totalsum+tr[2*ci+1].maxprefix);
}

node MaxPrefix(int ci,int s,int e,int l,int r){

    if(e<l || s>r){
        node outofrange;
        outofrange.totalsum=outofrange.maxprefix=0;
        return outofrange;
    }

    if(s>=l && e<=r) return tr[ci];

    int mid=(s+e)/2;

    node left=MaxPrefix(2*ci,s,mid,l,r);
    node right=MaxPrefix(2*ci+1,mid+1,e,l,r);

    node x;
    x.totalsum=left.totalsum+right.totalsum;
    x.maxprefix=max(left.maxprefix,left.totalsum+right.maxprefix);

    return x;

}



int main(){
    fast;
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    built_tree(1,1,n);
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            ll idx,val;
            cin>>idx>>val;
            update(1,1,n,idx,val);
        }
        else{
            int a,b;
            cin>>a>>b;
            node x=MaxPrefix(1,1,n,a,b);
            cout<<max(0ll,x.maxprefix)<<endl;
        }

    }
    return 0;
}


