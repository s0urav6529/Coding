#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int limit=1000006;

ll ans=0;
vector<int>Parent(limit,-1);
vector<int>Rank(limit,1);

int Find(int a){

    if(Parent[a]<0) return a;

    return Parent[a]=Find(Parent[a]);

}

void Union(int a,int b){
    int x=a,y=b;
    a=Find(a);
    b=Find(b);

    if(a!=b){
        //cout<<x<<" "<<y<<endl;
        ans+=__gcd(x,y);
        if(Rank[b]>Rank[a]) swap(a,b);
        Parent[b]=a;
        Rank[a]+=Rank[b];
    }
}

int main(){
    fast;
    int tc=1;
    cin>>tc;
    for(int t=1;t<=tc;t++){
        ans=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) Parent[i]=-1,Rank[i]=-1;
        for(int i=n;i>=2;i--){

            for(int j=2;;j++){

                if((i*j)>n) break;
                Union(i,(i*j));
            }

        }
        for(int i=2;i<=n;i++) if(Parent[i]==-1) ans++;

        cout<<"Case "<<t<<": "<<ans<<endl;
    }
    return 0;
}


