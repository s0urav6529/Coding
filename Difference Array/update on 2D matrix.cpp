
///2D binary matrix er submartix range (r1 , c1 & r2 , c2) deoya thekbe ja update hobe protiti query te
///finally output dite hbe final matrix ki hbe sob query ses hole.


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
    int n,m;
    cin>>n>>m;
    int a[n+2][m+2];
    int prefix[n+1][m+1];
    memset(prefix,0,sizeof(prefix));

    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=1;j<=m;j++){
            a[i][j]=s[j-1]-'0';
        }
    }
    int q;
    cin>>q;
    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;   ///leftup to bolltom right

        prefix[x1][y1]++;

        if(x2+1<=n && y2+1<=m) prefix[x2+1][y2+1]++;

        if(y2+1<=m) prefix[x1][y2+1]--;

        if(x2+1<=n) prefix[x2+1][y1]--;
    }

    ///rowupdate

    for(int c=1;c<=m;c++){
        for(int r=2;r<=n;r++)
            prefix[r][c]+=prefix[r-1][c];
    }

    ///columnupdate

    for(int r=1;r<=n;r++){
        for(int c=2;c<=m;c++)
            prefix[r][c]+=prefix[r][c-1];
    }

    ///output

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(prefix[i][j]&1)
                cout<<1-a[i][j];
            else cout<<a[i][j];
        }
        cout<<endl;
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
    while(tc--) solution();
    return 0;
}


