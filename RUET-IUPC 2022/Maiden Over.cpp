#include<bits/stdc++.h>
using namespace std;

using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void init_code(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

}

void run_case(int t){

    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int cnt=0;
        for(int j=1;j<=6;j++){
            int x; cin>>x;
            if(!x) cnt++;
        }
        if(cnt==6) ans++;
    }

    cout<<"Case "<<t<<": "<<ans<<endl;
    return;
}

int main(){
    fast;
    //init_code();
    int tc=1;
    cin>>tc;
    for(int l=1;l<=tc;l++) run_case(l);
    return 0;
}



