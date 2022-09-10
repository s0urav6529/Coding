#include<bits/stdc++.h>
using namespace std;
int main(){
    int n , k, sum=0, ans=0;
    cin>>n >> k;   ///k-> user demand sum otherwise k->0 id  zero sum

    map<int,int>mp;
    mp[0]=1;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        sum+=x;
        ans+=mp[sum-k];    //// if zero sum the k=0 otherwise k->user demand
        mp[sum]++;
    }
    cout<<ans<<endl;

    return 0;
}


