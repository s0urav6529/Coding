#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
const int limit=2e5+5;


int a[limit];
int BIT[limit];

void update(int index,int val,int n){

    while(index <= n){

        BIT[index] += val;
        index += (index & -index);

    }
}

int answer(int index){

    int sum = 0;

    while(index > 0){

        sum += BIT[index];
        index -= (index & -index);
    }
    return sum;
}

int main(){
    fast;
    int n,q;
    cin>> n >> q;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        update(i,a[i],n);
    }
    while(q--){
        int l,r;
        cin>>l>>r;   /// sum in range
        cout<<answer(r)-answer(l-1)<<endl;
    }
    return 0;
}


