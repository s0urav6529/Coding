
///Given an array and find minimum jump to rach the end of the array using array value. Time Complexity O(n*n)
///if we have a value 3 we can jump next three index.

/// 2 4 2 1 0 3 2 1 2 1 0 we need 4 jump to reach end and those index are

/// jump index 1 from 2 from 6 from 9 from 11. 1->2->6->9->11

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
int a[1005];
int jump[1005];
int path[1005];
int main()
{
    fast;
    //read;
    //out;
    int tc=1;
    //cin>>tc;
    for(int z=1;z<=tc;z++)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i],jump[i]=1e8,path[i]=i;
        jump[1]=0;
        path[1]=0;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(j+a[j]>=i && jump[i]>jump[j]+1)
                {
                    jump[i]=jump[j]+1;
                    path[i]=j;
                }
            }
        }
        cout<<jump[n]<<endl;
        cout<<n<<" ";
        for(int i=n;i>1;) ///printing the path
        {
            cout<<path[i]<<" ";
            i=path[i];
        }
        //cout<<"Case "<<z<<": "<<ans<<endl;
    }
    return 0;
}


