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
    vector<int>a;

    for(int i=0;i<n;i++){

        int x;
        cin>>x;

        int pos=upper_bound(a.begin(),a.end(),x)-a.begin();

        if(pos==a.size()){
            a.push_back(x);
            continue;
        }
        a[pos]=x;

    }
    cout<<a.size()<<endl;

    return 0;
}





