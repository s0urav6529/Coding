#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;
const int limit=2e5+5;


int main(){
    fast;

    ll n,x;
    cin>>n>>x;
    vector<pair<ll,int>>a(n);

    for(int i=0;i<n;i++) {
        cin>>a[i].first;
        a[i].second=i+1;
    }

    sort(a.begin(),a.end());


    for(int i=0;i<n;i++){

        ll x2=x-a[i].first;

        for(int j=i+1,k=n-1;j<k;j++){

            while(a[j].first+a[k].first>x2){
                k--;
            }

            if(j<k && (a[j].first+a[k].first)==x2){

                cout<<a[i].second<<" "<<a[j].second<<" "<<a[k].second<<endl;
                return 0;
            }


        }

    }

    cout<<"IMPOSSIBLE"<<endl;

    return 0;
}




