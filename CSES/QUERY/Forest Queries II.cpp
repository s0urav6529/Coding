
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e3+5;


int a[limit][limit];
int BIT[limit][limit];
int n,m,q;

void update(int xx,int yy,int val){

    for(int x=xx;x<=n;x+=(x&-x)){

        for(int y=yy;y<=n;y+=(y&-y)){

            BIT[x][y]+=val;
        }
    }

}

int query(int xx,int yy){

    int sum=0;

    for(int x=xx;x>0;x-=(x&-x)){

        for(int y=yy;y>0;y-=(y&-y)){

            sum+=BIT[x][y];
        }
    }
    return sum;
}


int main(){
    fast;

    cin >> n >> q;

    for(int i=1;i<=n;i++){

        for(int j=1;j<=n;j++){

            char c;
            cin >> c;

            if(c == '*') a[i][j]=1;
            else a[i][j]=0;

            update(i,j,a[i][j]);
        }

    }

    while(q--){

        int type;
        cin >> type;

        if(type == 2){

            int x1,y1,x2,y2;

            cin>>x1>>y1>>x2>>y2;

            int in1=query(x2,y2);

            int ex1=query(x2,y1-1);

            int ex2=query(x1-1,y2);

            int in2=query(x1-1,y1-1);

            cout<<in1+in2-ex1-ex2<<endl;

        }
        else{

            int x,y,val=1;

            cin>>x>>y;


            if(a[x][y] == 1) val=-1;

            a[x][y]+=val;

            update(x,y,val);

        }

    }

    return 0;
}
