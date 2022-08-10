#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
typedef unsigned long long int llu;

constexpr ll mod=1e9+7;
const int limit=2e5+5;


int main(){
    fast;
    int tc=1;
    //cin>>tc;
    while(tc--){
        ll n,x,max_here=0,max_so_far=INT_MIN,srt=1,ed=1,s=1;
        cin>>n;
        int a[n+5];
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }

        for(int i=1;i<=n;i++){
            max_here+=a[i];
            if(max_so_far<max_here)
            {
                max_so_far=max_here;srt=s;ed=i;
            }
            if(max_here<a[i])
            {
                max_here=a[i];
                s=i;
                if(max_so_far<a[i]) max_so_far=a[i],srt=i,ed=i;  ///Maybe signle element contains maximum values
            }
        }
        cout<<max_so_far<<endl;
    }
    return 0;
}





