
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e3+5;


ll a[limit][limit];
ll BIT[limit][limit];
ll n,m,q;

void update(ll xx,ll yy,ll val){

    for(ll x=xx;x<=n;x+=(x&-x)){

        for(ll y=yy;y<=m;y+=(y&-y)){

            BIT[x][y]+=val;
        }
    }

}

ll query(ll xx,ll yy){

    ll sum=0;

    for(ll x=xx;x>0;x-=(x&-x)){

        for(ll y=yy;y>0;y-=(y&-y)){

            sum+=BIT[x][y];
        }
    }
    return sum;
}


int main(){
    fast;

    cin>>n>>m>>q;

    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++){

            cin>>a[i][j];

            update(i,j,a[i][j]);
        }

    }

    while(q--){

        string s;
        cin>>s;

        if(s=="sum"){  ///summation of a range

            ll x1,y1,x2,y2;

            cin>>x1>>y1>>x2>>y2;

            ll in1=query(x2,y2);

            ll ex1=query(x2,y1-1);

            ll ex2=query(x1-1,y2);

            ll in2=query(x1-1,y1-1);

            cout<<in1+in2-ex1-ex2<<endl;

        }
        else{

            ll x,y,val;
            cin>>x>>y>>val;

            a[x][y]+=val;   ///Adding value
            
            ///Replace value
            /// ll del = a[x][y];
            /// update(x,y,-del); ///remove previous value

            update(x,y,val);

        }


    }

    return 0;
}

