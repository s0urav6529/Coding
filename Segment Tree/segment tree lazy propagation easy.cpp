#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define mod 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
#define maxx 100005
int a[maxx];
int st[4*maxx];
int lazy[4*maxx]; ///pending the update

void segment_tree(int i,int b,int e)
{
	if(b==e)
	{
		st[i]=a[b];
		return;
	}
	int l_i=i*2;
    int r_i=i*2+1;
    int mid=(b+e)/2;

    segment_tree(l_i,b,mid);
    segment_tree(r_i,mid+1,e);

    st[i]=st[l_i]+st[r_i];
}

void update(int i,int b,int e,int x,int y,int val)
{
    int l_i=i*2;
    int r_i=i*2+1;

	if(lazy[i]!=0)
	{
		int up=lazy[i];
		lazy[i]=0;
		st[i]+=up*(e-b+1);

		if(b!=e)
		lazy[l_i]+=up,lazy[r_i]+=up;
	}
	if(e<x || b>y) return;

	if(b>=x && e<=y)
	{
		int up=(e-b+1)*val;
		st[i]+=up;

		if(b!=e)
		lazy[l_i]+=val,lazy[r_i]+=val;
		return;
	}
    int mid=(b+e)/2;
    update(l_i,b,mid,x,y,val);
    update(r_i,mid+1,e,x,y,val);

    st[i]=st[l_i]+st[r_i];
}

int query(int i,int b,int e,int x,int y)
{
    int l_i=i*2;
    int r_i=i*2+1;

	if(lazy[i]!=0)
	{
		int up=lazy[i];
		lazy[i]=0;
		st[i]+=up*(e-b+1);

		if(b!=e)
		lazy[l_i]+=up,lazy[r_i]+=up;
	}

	if(e<x || b>y) return 0;
    if(b>=x && e<=y) return st[i];

	int mid=(b+e)/2;
	return query(l_i,b,mid,x,y)+query(r_i,mid+1,e,x,y);
}

int main()
{
	int n,q;
	cin>>n>>q;
	segment_tree(1,1,n);
	while(q--)
	{
	    int c,l,r,val;
		cin>>c;
		if(c==1)
		{
			cin>>l>>r;
			cout<<query(1,1,n,l,r)<<endl;
		}
		else
		{
			cin>>l>>r>>val;
			update(1,1,n,l,r,val);
		}
	}
}
