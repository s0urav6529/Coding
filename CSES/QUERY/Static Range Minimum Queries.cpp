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
    int a[n+2];
    for(int i=1;i<=n;i++) cin>>a[i];
    int spares_table[n+2][20];

    for(int i=1;i<=n;i++){
        spares_table[i][0]=a[i];
    }
    for(int j=1;j<=20;j++){

        int len=pow(2,j);
        if(len>n) break;
        for(int i=1;i<=n;i++){
            if(i+len-1>n) break;
            spares_table[i][j]=min(spares_table[i][j-1],spares_table[i+(len/2)][j-1]);

        }

    }

    while(q--){

        int l,r;
        cin>>l>>r;
        int range=r-l+1;
        int power=log2(range);
        int len=pow(2,power);
        cout<<min(spares_table[l][power],spares_table[r-len+1][power])<<endl;
    }
}
int main()
{
    fast;
    int tc=1;
    while(tc--) solution();
    return 0;
}
