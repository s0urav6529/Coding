#include<bits/stdc++.h>
using namespace std;

using ll=unsigned long long int;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int limit=1000006;


int main(){
    fast;
    int tc=1;
    cin>>tc;
    for(int t=1;t<=tc;t++){

        int n,q;
        cin>>n>>q;
        vector<pair<int,int>>qq(q);

        bool f=false;
        for(int i=0;i<q;i++) {
            cin>>qq[i].first>>qq[i].second;
            if((qq[i].second-qq[i].first+1)>64) f=true;
        }

        if(f){
            cout<<"Case "<<t<<": "<<"Impossible"<<endl;
            continue;
        }
        ll ans[n+5];
        for(int  i=1;i<=n;i++) ans[i]=-1;

        sort(qq.begin(),qq.end());
        for(int i=0;i<q;i++){

            int l=qq[i].first;
            int r=qq[i].second;

            bool vis[66];
            for(int m=0;m<65;m++) vis[m]=0;

            for(int j=l,k=0;j<=r;j++){

                while(vis[k]) k++;

                if(ans[j]==-1){
                    ans[j]=k;
                    vis[k]=1;
                }
                else{
                    vis[ans[j]]=1;
                }
            }
        }

        for(int i=1;i<=n;i++) {
            if(ans[i]==-1) ans[i]=0;
        }

        cout<<"Case "<<t<<": "<<endl;

        for(int  i=1;i<=n;i++) {

            printf("%llu",(1ll<<ans[i]));
            if(i<n) printf(" ");
            else printf("\n");

        }
    }
    return 0;
}



