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
        int n;
        cin>>n;
        vector<int>pos(n+1);
        pos[0]=n+1;

        for(int i=1;i<=n;i++){

            int x;
            cin>>x;
            pos[x]=i;

        }

        int round=0;
        for(int i=1;i<=n;i++){

            if(pos[i]<pos[i-1]) round++;
        }

        cout<<round<<endl;

    }
    return 0;
}





