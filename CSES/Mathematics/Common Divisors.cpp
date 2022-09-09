#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int tc=1;
    //cin>>tc;
    while(tc--){
        int x;
        cin>>x;
        int ans=1,mx=1;
        vector<int>a(1e6+5,0);
        for(int i=1;i<=x;i++){
            int n;
            cin>>n;
            a[n]++;
            mx=max(mx,n);
        }

        for(int i=mx;i>1;i--){
            int cnt=0;
            for(int j=i;j<=mx;j+=i){
                if(a[j]) cnt+=a[j];
            }
            if(cnt>1) {
                ans=i;
                break;
            }
        }

        cout<<ans<<endl;
    }


    return 0;
}



