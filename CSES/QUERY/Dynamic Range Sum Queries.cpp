
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
    ll a[n+1];
    for(int i=0;i<n;i++) cin>>a[i];
    int block=sqrt(n)+1;

    vector<ll>block_sum(block);

    for(int i=0;i<n;i++){
        block_sum[i/block]+=a[i];
    }

    while(q--){
        int type,l,r,p;
        ll val;
        cin>>type;
        if(type==1){
            cin>>p>>val;
            p--;
            block_sum[p/block]-=a[p]; ///removing old contribution from block
            a[p]=val;
            block_sum[p/block]+=a[p];  ///adding new contribution to the block
        }
        else{
            cin>>l>>r;
            l--,r--;
            int lb=l/block;
            int rb=r/block;
            ll sum=0;
            if(lb==rb){
                for(int i=l;i<=r;i++)
                    sum+=a[i];
            }
            else{

                for(int i=l;i<(lb+1)*block;i++)
                    sum+=a[i];
                for(int i=lb+1;i<rb;i++)
                    sum+=block_sum[i];
                for(int i=rb*block;i<=r;i++)
                    sum+=a[i];
            }
            cout<<sum<<endl;

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
