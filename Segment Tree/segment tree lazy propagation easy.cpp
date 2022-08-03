#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
const int limit=1e5+5;


int a[limit];
int st[4*limit];
int lazy[4*limit];

void segment_tree(int node,int b,int e){

	if(b==e){
		st[node]=a[b];
		return;
	}
	int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;

    segment_tree(left,b,mid);
    segment_tree(right,mid+1,e);

    st[node]=st[left]+st[right];
}

void update(int node,int b,int e,int l,int r,int val){

    int left=node*2;
    int right=node*2+1;

	if(lazy[node]!=0){

		int up=lazy[node];
		lazy[node]=0;
		st[node]+=up*(e-b+1);

		if(b!=e)
            lazy[left]+=up,lazy[right]+=up;
	}

	if(e<l || b>r) return;

	if(b>=l && e<=r){

		int up=(e-b+1)*val;
		st[node]+=up;

		if(b!=e)
            lazy[left]+=val,lazy[right]+=val;

		return;
	}

    int mid=(b+e)/2;

    update(left,b,mid,l,r,val);
    update(right,mid+1,e,l,r,val);

    st[node]=st[left]+st[right];
}

int query(int node,int b,int e,int l,int r){

    int left=node*2;
    int right=node*2+1;

	if(lazy[node]!=0){

		int up=lazy[node];
		lazy[node]=0;
		st[node]+=up*(e-b+1);

		if(b!=e)
            lazy[left]+=up,lazy[right]+=up;
	}

	if(e<l || b>r) return 0;

    if(b>=l && e<=r) return st[node];

	int mid=(b+e)/2;

	return query(left,b,mid,l,r)+query(right,mid+1,e,l,r);
}

int main(){
    fast;
    int n,q;
    scanf("%d%d",&n,&q);
    //cin>>n>>q;

    segment_tree(1,1,n);
    //printf("Case %d:\n",t);
    while(q--){

        int type,l,r,v;
        cin>>type;
        if(!type){
            cin>>l>>r>>v;
            update(1,1,n,l,r,v);

        }
        else{
            cin>>l>>r;
            int ans=query(1,1,n,l,r);
            printf("%d\n",ans);
        }

    }
    return 0;
}


