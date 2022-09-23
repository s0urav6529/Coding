#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
typedef unsigned long long int llu;

constexpr ll MOD=1e9+7;
const int limit=2e5+5;

ll Mod(ll x){
    return ((x%MOD + MOD)%MOD);
}


ll mulmod(ll a,ll b){
    return Mod(Mod(a)*Mod(b));
}

ll Binary_expo(ll a,ll n){
	ll res=1;
	while(n){

		if(n&1)
		res=mulmod(res,a);

		n/=2;
		a=mulmod(a,a);
	}
	return res%MOD;
}


int main(){
    fast;
    int tc=1;
    //cin>>tc;
    while(tc--){

        int n;
        cin>>n;

        ll no_div=1, sum_of_div=1, pro_of_div=1;

        ll base[n+5] , expo[n+5];

        bool odd_ache=false;

        int odd_position;

        for(int i=0;i<n;i++){


            cin>> base[i] >> expo[i];

            no_div = mulmod(no_div,(expo[i]+1));  /// according to the formula of No of Divisors

            ll contibution = mulmod( Mod( Binary_expo(base[i],expo[i]+1) - 1) , Binary_expo(base[i]-1,MOD-2) );  /// according the formula of SOD

            sum_of_div = mulmod(sum_of_div , contibution);

            if(expo[i] & 1) {

                odd_ache = true;
                odd_position = i;
            }

        }

        if(odd_ache){

            ll number_of_divisor = 1;

            for(int i =0;i<n;i++){

                if(odd_position==i){

                    number_of_divisor = ( number_of_divisor * ( (expo[i] + 1) / 2 ) ) % (MOD-1) ;
                }
                else {
                    number_of_divisor = ( number_of_divisor * (expo[i] + 1) ) % (MOD-1);
                }
            }

            for(int i=0 ;i < n ;i++){

                ll contibution = ( expo[i] * number_of_divisor ) % (MOD-1);

                pro_of_div = mulmod( pro_of_div , Binary_expo(base[i] ,contibution));

            }

        }
        else{

            ll number_of_divisor = 1;

            for(int i =0;i<n;i++){

                number_of_divisor = ( number_of_divisor * ( expo[i] + 1 ) ) % (MOD-1) ;

            }

            for(int i=0 ;i < n ;i++){

                ll contibution = ( ( expo[i] / 2 ) * number_of_divisor ) % (MOD-1);

                pro_of_div = mulmod( pro_of_div , Binary_expo(base[i] ,contibution));

            }


        }

        cout<<no_div<<" "<<sum_of_div<< " " << pro_of_div <<endl;
    }
    return 0;
}





