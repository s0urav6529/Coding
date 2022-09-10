
///MO's Algoritm
/// for sorting query qlog(q)
///for answing q query q.sqrt(n);
///Time complexity O((n+q)sqrt(n)+ qlog(q))



#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);


#define block 700
int a[30005];
int fre[1000002];
int ans[200002];
int cnt=0,n;


struct query{
    int l;
    int r;
    int in;
}q[200002];

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
    //read;
    //out;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    int qq;
    cin>>qq;
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
        //cout<<L<<" "<<R<<endl;

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


