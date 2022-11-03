#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=2e5+5;

ll a[limit];
ll downst[limit << 2] , upst[limit << 2];

void downward_st(int node,int b,int e){

    if(b==e){
        downst[node] = a[b] - b;
        return;
    }

    int mid=(b+e)/2;

    downward_st(node << 1, b, mid);
    downward_st(node << 1 | 1 , mid+1, e);

    downst[node] = min( downst[node << 1] , downst[node << 1 | 1]);

}

void upward_st(int node,int b,int e){

    if(b==e){
        upst[node] = a[b] + b;
        return;
    }

    int mid=(b+e)/2;

    upward_st(node << 1, b, mid);
    upward_st(node << 1 | 1 , mid+1, e);

    upst[node] = min( upst[node << 1] , upst[node << 1 | 1]);

}

void update_downst(int node,int b,int e,int id){

    if(b==e){
        downst[node] = a[b] - b;
        return;
    }

    int mid=(b+e)/2;

    if(id<=mid) update_downst(node << 1, b, mid, id);
    else update_downst(node << 1 | 1 ,mid+1, e, id);

    downst[node]= min( downst[node << 1] ,  downst[node << 1 | 1] ) ;

}

void update_upst(int node,int b,int e,int id){

    if(b==e){
        upst[node] = a[b] + b;
        return;
    }

    int mid=(b+e)/2;

    if(id<=mid) update_upst(node << 1, b, mid, id);
    else update_upst(node << 1 | 1 ,mid+1, e, id);

    upst[node]= min( upst[node << 1] , upst[node << 1 | 1] );

}

ll Min_downst(int node,int b,int e,int l,int r){

    if(e<l || b>r)
        return 1e17;

    if(b>=l && e<=r)
        return downst[node];

    int mid=(b+e)/2;

    return min(Min_downst(node << 1 , b, mid, l, r) , Min_downst(node << 1 | 1, mid+1, e, l ,r));
}

ll Min_upst(int node,int b,int e,int l,int r){

    if(e<l || b>r)
        return 1e17;

    if(b>=l && e<=r)
        return upst[node];

    int mid=(b+e)/2;

    return min(Min_upst(node << 1 , b, mid, l, r) , Min_upst(node << 1 | 1, mid+1, e, l ,r));
}


int main(){
    fast;

    int q , n;
    cin>>n >> q;

    for(int i=1;i<=n;i++)  cin>>a[i];

    downward_st(1,1,n);
    upward_st(1,1,n);

    while(q--){

        int type;
        cin >> type;

        if(type==1){
            ll x , k;
            cin >> k >>  x ;

            a[k] = x;
            update_downst(1,1,n,k);
            update_upst(1,1,n,k);


        }
        else {
            ll k;
            cin >> k;

            ll downmin = Min_downst(1,1,n,1,k) + k;

            ll upmin = Min_upst(1,1,n,k,n) - k;

            cout << min(downmin , upmin) <<endl;


        }

    }


    return 0;
}



