#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,sum=0,ans=0;
    cin>>n;

    map<int,int>mp;
    mp[0]=1;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        sum+=x;
        ans+=mp[sum];
        mp[sum]++;
    }
    cout<<ans<<endl;

    return 0;
}


