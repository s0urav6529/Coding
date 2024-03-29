
///  Number of distinct integer in between L - R

#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
const int limit=2e5+5;
const int block=700;

int a[limit];
int fre[limit];
int ans[limit];
int cnt=0;


struct query{
    int l;
    int r;
    int in;
}q[limit];

bool comp(query a,query b){

    if(a.l/block!=b.l/block)
        return a.l/block<b.l/block;

    return a.r<b.r;
}

void add(int pos){
    fre[a[pos]]++;
    if(fre[a[pos]]==1) cnt++;
}

void remove(int pos){
    fre[a[pos]]--;
    if(fre[a[pos]]==0) cnt--;
}


int main()
{
    fast;
    int n,qq;
    cin>>n>>qq;
    for(int i=0;i<n;i++) cin>>a[i];
    
    for(int i=0;i<qq;i++){
        
        cin>>q[i].l>>q[i].r;
        q[i].l--;
        q[i].r--;
        q[i].in=i;
    }

    sort(q,q+qq,comp);

    int ML=0,MR=-1;
    for(int i=0;i<qq;i++){

        int L=q[i].l;
        int R=q[i].r;

        while(ML>L){
            ML--,add(ML);
        }
        while(MR<R){
            MR++,add(MR);
        }

        while(ML<L){
            remove(ML),ML++;
        }
        while(MR>R){
            remove(MR),MR--;
        }
        ans[q[i].in]=cnt;
    }
    for(int i=0;i<qq;i++){
        cout<<ans[i]<<endl;
    }

    return 0;
}


