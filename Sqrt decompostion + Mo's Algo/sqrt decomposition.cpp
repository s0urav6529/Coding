
///sqrt decomposition e n k sqrt(n).
///kore sqrt(n) block e divide kore protiti block e sqrt(n) lenght e precalcuate kore nicche

///we can use it in min/max/summation etc.
///Time complexity O(n.sqrt(n))

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
    fast;
    //read;
    //out;
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++) cin>>a[i];

    int blocksize=sqrt(n)+1; ///block size & block lenght

    //cout<<blocksize<<endl;

    vector<int>block(blocksize); ///storing value for all block
    for(int i=0;i<n;i++)
    {
        block[i/blocksize]+=a[i];   ///summing problem
    }

    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        int lb=l/blocksize;  ///leftblock
        int rb=r/blocksize;  ///rightblock

        int sum=0;
        if(lb==rb){
            for(int i=l;i<=r;i++) sum+=a[i];
        }
        else{

            for(int i=l;i<((lb+1)*blocksize);i++){     ///for left block
                sum+=a[i];
            }

            for(int i=lb+1;i<rb;i++){  ///for middle block
                sum+=block[i];
            }

            for(int i=rb*blocksize;i<=r;i++){   ///for right block
                sum+=a[i];
            }

        }
        cout<<sum<<endl;

    }


}

