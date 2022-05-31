
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);

constexpr ll lmax = 1e18;


ll solution()
{
    int n;
    cin>>n;
    ll a[n+2];
    ll pre_dif[n+2];
    ll suf_dif[n+2];
    int pre_max[n+2];
    int suf_max[n+2];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){    ///getting prefix differnence
        if(i==1) pre_dif[i]=lmax;
        pre_dif[i]=a[i]-a[i-1];
    }
    for(int i=n;i>=1;i--){   ///getting suffix differnence
        if(i==n) suf_dif[i]=lmax;
        suf_dif[i]=a[i+1]-a[i];
    }


    for(int i=1;i<=n;i++){   ///getting prefix max AP without chainging one element
        if(i==1) pre_max[i]=1;
        else if(i==2) pre_max[i]=2;
        else{
            if(pre_dif[i]==pre_dif[i-1])
                pre_max[i]=pre_max[i-1]+1;
            else pre_max[i]=2;
        }
    }
    for(int i=n;i>=1;i--){   ///getting suffix max AP without chainging one element
        if(i==n) suf_max[i]=1;
        else if(i==n-1) suf_max[i]=2;
        else{
            if(suf_dif[i]==suf_dif[i+1])
                suf_max[i]=suf_max[i+1]+1;
            else suf_max[i]=2;
        }
    }

    int ans=max(1+suf_max[2],1+pre_max[n-1]);   ///1st and last answer
    for(int i=2;i<n;i++){
        ans=max(ans,suf_max[i+1]+1);
        ans=max(ans,pre_max[i-1]+1);

        ll e1=a[i-1];
        ll e2=a[i+1];

        if((e2-e1)%2) continue;  /// if odd we cannot replace an elements

        ll dif=(e2-e1)/2;

        if(i<3 || pre_dif[i-1]==dif)
            ans=max(ans,2+pre_max[i-1]);

        if(i>n-2 || suf_dif[i+1]==dif)
            ans=max(ans,2+suf_max[i+1]);

        if((i>2 && pre_dif[i-1]!=dif) || (i<n-1 && suf_dif[i+1]!=dif)) continue;

        ans=max(ans,1+suf_max[i+1]+pre_max[i-1]);
    }
    return ans;
}
int main()
{
    fast;
    //read;
    //out;
    int tc=1;
    cin>>tc;
    for(int t=1;t<=tc;t++){
        cout<<"Case #"<<t<<": "<<solution()<<endl;
    }
    return 0;
}

