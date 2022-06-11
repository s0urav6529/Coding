#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define mod 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);


void solution()
{
    int n,q;
    cin>>n>>q;
    vector<ll>a(n+1);
    for(int i=0;i<n;i++) cin>>a[i];
    int block=sqrt(n)+1;
    vector<ll>block_min(block,1e13);
    for(int i=0;i<n;i++){
        block_min[i/block]=min(block_min[i/block],a[i]);
    }

    while(q--){
        int type,l,r,p;
        ll val;
        cin>>type;
        if(type==1){
            cin>>p>>val;
            p--;
            a[p]=val;
            int pblock=p/block;
            block_min[pblock]=1e13;
            for(int i=pblock*block;i<(pblock+1)*block;i++)
                block_min[pblock]=min(block_min[pblock],a[i]);
        }
        else{
            cin>>l>>r;
            l--,r--;
            int lb=l/block;
            int rb=r/block;
            ll MIN=1e13;
            if(lb==rb){

                for(int i=l;i<=r;i++)
                    MIN=min(MIN,a[i]);
            }
            else{

                for(int i=l;i<(lb+1)*block;i++)
                    MIN=min(MIN,a[i]);

                for(int i=lb+1;i<rb;i++)
                    MIN=min(MIN,block_min[i]);

                for(int i=rb*block;i<=r;i++)
                    MIN=min(MIN,a[i]);
            }
            cout<<MIN<<endl;

        }
    }


    return;
}
int main()
{
    fast;
    //read;
    //out;
    int tc=1;
    //cin>>tc;
//    for(int z=1;z<=tc;z++)
//    {
//        cout<<"Case #"<<z<<": ";
//
//    }
    while(tc--) solution();
    return 0;
}
