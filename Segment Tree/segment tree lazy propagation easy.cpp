#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
const int limit=1e5+5;


int a[limit];
int st[limit << 2] , lazy[limit << 2];

void segment_tree(int node,int b,int e){

	if(b==e){
		st[node] = a[b];
		return;
	}

    int mid=(b+e)/2;

    segment_tree(node << 1, b, mid);
    segment_tree(node << 1 | 1 , mid+1, e);

    st[node] = st[node << 1] + st[node << 1 | 1];
}

void update(int node,int b,int e,int l,int r,int val){

	if(lazy[node] != 0){

		int Update=lazy[node];

		lazy[node]=0;

		st[node] += Update * (e-b+1);

		if(b!=e){
		    lazy[node << 1] += Update;
		    lazy[node << 1 | 1] += Update;
		}
	}

	if(e<l || b>r) return;

	if(b>=l && e<=r){

		int Update = (e-b+1)*val;

		st[node] += Update;

		if(b!=e) {
		    lazy[node << 1] += val;
		    lazy[node << 1 | 1] += val;
		}
		return;
	}

    int mid=(b+e)/2;

    update(node << 1, b, mid, l, r, val);
    update(node << 1 | 1, mid+1, e, l, r, val);

    st[node]=st[node << 1]+st[node << 1 | 1];
}

int query(int node,int b,int e,int l,int r){

	if(lazy[node]!=0){

		int Update = lazy[node];

		lazy[node]=0;

		st[node]+=Update * (e-b+1);

		if(b!=e){
		    lazy[node << 1] += Update;
		    lazy[node << 1 | 1] += Update;
		}
	}

	if(e<l || b>r) return 0;

    	if(b>=l && e<=r) return st[node];

	int mid=(b+e)/2;

	return query(node << 1, b, mid, l, r) + query(node << 1 | 1, mid+1, e, l, r);
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

