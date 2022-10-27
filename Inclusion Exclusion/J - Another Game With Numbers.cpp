
Find the number of integers from [1 - N] are divisible by a set of number[prime or not prime].

#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;


void run_case(){

    ll n ;
    int k;
    cin >> n >> k;

    ll a[k+5];

    for(int i=0;i<k;i++) cin >> a[i];

    ll ans = 0;

    for(int mask=1;mask<(1<<k);mask++){

        ll N=n,nod=0,lcm=1;
        
        for(int bit=0;bit<k;bit++){

            if((mask & ( 1 << bit ))){

                nod++;

                if(nod>1){

                    lcm = (lcm * a[bit]) / __gcd(lcm , a[bit]);
                }
                else lcm = a[bit];
            }
        }
       // cout << nod<<" " <<num <<" "<<N/lcm<<endl;
        if(nod&1) ans += N/lcm;
        else ans -= N/lcm;
    }

    cout<<ans<<endl;


    return;
}


