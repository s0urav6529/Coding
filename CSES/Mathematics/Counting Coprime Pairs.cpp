
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=1e6+5;

vector<ll>prime[limit];

void seive(){

    for(int i=2;i<limit;i++){

        if(prime[i].size() == 0){

            prime[i].push_back(i);

            for(int j=2*i;j<limit;j+=i){
                prime[j].push_back(i);
            }
        }
    }
}

int main(){
    fast;

    seive();

    ll n; cin >> n;

    vector<ll>val(n);
    vector<ll>contribution(limit,0) , prime_ache(limit,0);

    for(int i=0;i<n;i++) cin >> val[i];


    for(int i=0; i<n ;i++)  {

        int len = prime[val[i]].size();

        for(int mask=1; mask<(1<<len) ;mask++){

            ll number = 1 , prime_divisor = 0;

            for(int bit=0;bit<len;bit++){

                if((mask & (1<<bit))){

                   number*=prime[val[i]][bit];

                   prime_divisor++;

                }
            }
            contribution[number]++;
            prime_ache[number]=prime_divisor;
            //cout << number << " " <<contribution[number] <<" " << prime_ache[number] <<endl;

        }
    }

    ll Total_pair = (n*(n-1)) / 2;

    ll non_coprime = 0;

    for(int i=0;i<limit;i++){

        ll help = (contribution[i] * (contribution[i]-1)) / 2;

        if(prime_ache[i]&1) non_coprime += help;

        else non_coprime -= help;

        //cout << i<<" " <<contribution[i] <<" "<<prime_ache[i] <<" " << help<<endl;

    }

    cout << Total_pair - non_coprime <<endl;

    return 0;
}


