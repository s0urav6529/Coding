#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
typedef unsigned long long int llu;

constexpr ll mod=1e9+7;
const int limit=2e5+5;


int main(){
    fast;
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    map<int,int>p;
    int ans=1,mn=1;

    for(int i=1;i<=n;i++){

        if(p[a[i]]==0){
            ans=max(ans,abs(i-mn+1));
        }
        else{
            int pos=p[a[i]];
            if(pos>=mn)
                mn=max(mn+1,pos+1);
            ans=max(ans,abs(i-mn+1));

            }
            p[a[i]]=i;
    }
    cout<<ans<<endl;
    return 0;
}





