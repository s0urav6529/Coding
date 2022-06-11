#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define mod 1000000007
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);

///partial block er gulake add korsi array te ,full block gula k block e add korsi.
///output er somoy array position + block increase.

void solution()
{
    int n,q;
    cin>>n>>q;
    vector<ll>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int block=sqrt(n)+1;
    vector<ll>block_a(block,0);
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int l,r;
            ll val;
            cin>>l>>r>>val;
            l--,r--;
            int lb=l/block;
            int rb=r/block;
            if(lb==rb){
                for(int i=l;i<=r;i++) a[i]+=val;
            }
            else{

                for(int i=l;i<((lb+1)*block);i++){
                    a[i]+=val;
                }

                for(int i=lb+1;i<rb;i++){
                    block_a[i]+=val;
                }

                for(int i=rb*block;i<=r;i++){
                    a[i]+=val;
                }
            }
        }
        else{
            int k;
            cin>>k;
            k--;
            cout<<a[k]+block_a[k/block]<<endl;
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
