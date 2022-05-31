

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int limit=100005;

int a[limit+5];
void preprocess(){

    int two_power=1,index=1;

    while(index<limit){

        int k=index;
        a[index++]=two_power;

        for(int i=1;i<k && index<limit;i++){
            a[index++]=a[i];
        }

        two_power*=2;
    }
    return;
}

void run_case(){


    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
    return;
}

int main()
{
    fast;
    preprocess();
    int tc=1;
    cin>>tc;
    while(tc--) run_case();
    return 0;
}


