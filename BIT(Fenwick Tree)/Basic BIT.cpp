#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
const int limit=2e5+5;


int a[limit];
int ftree[limit];

void update(int idx,int val,int n){

    while(idx<=n){

        ftree[idx]+=val;
        idx+=(idx & -idx);

    }
}

int answer(int idx){

    int sum=0;

    while(idx>0){

        sum+=ftree[idx];
        idx-=(idx & -idx);
    }
    return sum;
}

int main(){
    fast;
    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        update(i,a[i],n);
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<answer(r)-answer(l-1)<<endl;
    }
    return 0;
}



