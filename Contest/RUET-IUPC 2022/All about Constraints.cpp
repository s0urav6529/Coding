#include<bits/stdc++.h>
using namespace std;

using ll=unsigned long long int;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int limit=1000006;


int main(){
    fast;
    ll tc=1;
    scanf("%d",&tc);
    for(int t=1;t<=tc;t++){

        ll n,q;
        scanf("%llu %llu",&n,&q);
        vector<pair<ll,ll>>qq(q);

        bool f=false;
        for(int i=0;i<q;i++) {

            scanf("%llu %llu",&qq[i].first,&qq[i].second);
            if((qq[i].second-qq[i].first+1)>64ll) f=true;
        }

        if(f){
            printf("Case %llu:\n",t);
            printf("Impossible\n");
            continue;
        }
        ll ans[n+5];
        for(int i=1;i<=n;i++) ans[i]=-1;

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

        printf("Case %llu:\n",t);
        for(int  i=1;i<=n;i++) {

            printf("%llu",(1ll<<ans[i]));
            if(i<n) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}



