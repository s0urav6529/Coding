#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
#define BLOCK 555

struct query{
	int l;
	int r;
	int i;
};
query Q[300001];
int ar[300001],ans[300001];
int fre[300001];

int freOfFre[300001];   ///frequency of frequency array.
int currMax=0;

bool comp(query a,query b)
{
	if(a.l/BLOCK!=b.l/BLOCK)
	return a.l/BLOCK<b.l/BLOCK;

	return a.r<b.r;
}

void add(int pos)
{
	int preF=fre[ar[pos]];
	fre[ar[pos]]++;
	int currF=fre[ar[pos]];

	freOfFre[preF]--;
	freOfFre[currF]++;

	if(currF>currMax){

		currMax=currF;
	}
}

void remove(int pos)
{
	int preF=fre[ar[pos]];
	fre[ar[pos]]--;
	int currF=fre[ar[pos]];

	freOfFre[preF]--;
	freOfFre[currF]++;

	if(currF<currMax){

		while(freOfFre[currMax]==0)
		currMax--;
	}
}

int main()
{
    fast;
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
	cin>>ar[i];

	for(int i=0;i<q;i++){
		cin>>Q[i].l>>Q[i].r;
		Q[i].i=i;
		Q[i].l--;
        Q[i].r--;
	}

	sort(Q,Q+q,comp);

	int ML=0,MR=-1;
	for(int i=0;i<q;i++)
	{
		int L=Q[i].l;
		int R=Q[i].r;

		while(ML>L){
            ML--;
            add(ML);
		}
		while(MR<R){
            MR++;
            add(MR);
		}
		while(ML < L){
            remove(ML);
            ML++;
		}
		while(MR>R){
            remove(MR);
            MR--;
		}

		ans[Q[i].i]=currMax;
	}

	for(int i=0;i<q;i++)
	cout<<ans[i]<<endl;
}


