#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
typedef unsigned long long int llu;

constexpr ll mod=1e9+7;
const int limit=2e5+5;


int a[limit];
struct node{
    ll pre_sum;
    ll suf_sum;
    ll tot_sum;
    ll max_subsum;
};

node tr[4*limit];


void Marge(int i){


    tr[i].pre_sum=max(tr[2*i].pre_sum,tr[2*i].tot_sum+tr[2*i+1].pre_sum);

    tr[i].suf_sum=max(tr[2*i+1].suf_sum,tr[2*i].suf_sum+tr[2*i+1].tot_sum);

    tr[i].tot_sum=tr[2*i].tot_sum+tr[2*i+1].tot_sum;

    tr[i].max_subsum=max(tr[2*i].max_subsum,max(tr[2*i+1].max_subsum,tr[2*i].suf_sum+tr[2*i+1].pre_sum));

    return;

}

void built_tree(int i,int s,int e){

    if(s==e){
        tr[i].max_subsum= tr[i].pre_sum= tr[i].suf_sum= tr[i].tot_sum=a[s];
        return;
    }

    int mid=(s+e)/2;

    built_tree(2*i,s,mid);
    built_tree(2*i+1,mid+1,e);

    Marge(i);

}

void update(int i,int s,int e,int idx,int val){

    if(idx<s || idx>e) return;

    if(s==e && s==idx){
        tr[i].max_subsum= tr[i].pre_sum= tr[i].suf_sum= tr[i].tot_sum=a[idx]=val;
        return;
    }

    int mid=(s+e)/2;
    update(2*i,s,mid,idx,val);
    update(2*i+1,mid+1,e,idx,val);

    Marge(i);
}

node answer(int i,int s,int e,int l,int r){

    if(s>=l && e<=r) return tr[i];

}
int main(){
    fast;
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];

    built_tree(1,1,n);

    while(q--){

        int idx,val;
        cin>>idx>>val;
        update(1,1,n,idx,val);
        cout<<max(0ll,answer(1,1,n,1,n).max_subsum)<<endl;


    }

    return 0;
}





