

#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e2+5;

int main(){
    fast;

    string s; cin>>s;

    ll n=s.size();

    ll sz=(1<<n);   /// left shifting because we have 2^n combination

    for(int mask=0 ; mask<sz ; mask++){

        for(int bit=0 ; bit<n ; bit++){   /// bit position charecter include korbo ki korbo na

            if((mask & (1 << bit))) cout<< s[bit] <<" ";

        }
        cout<<endl;
    }

    return 0;
}


