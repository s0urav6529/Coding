

///CHECKING CURRENT STRING PALINDROM OR NOT AFTER EACH CHARECTER ADD


#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=1e2+5;


vector<ll>for_hash(limit),rev_hash(limit);
ll base = 31;

ll Mod(ll x){
    return ((x%MOD + MOD)%MOD);
}


ll mulmod(ll a,ll b){
    return Mod(Mod(a)*Mod(b));
}

ll Binary_expo(ll a,ll p){
	ll res=1;
	while(p){

		if(p&1)
		res=mulmod(res,a);

		p/=2;
		a=mulmod(a,a);
	}
	return res%MOD;
}


int main(){
    fast;

    int tc=1;
    cin >> tc;

    string s="";

    while(tc --){

        cin.ignore();
        char c;
        cin >> c;

        s+=c;

        ll cur=s.size();

        for_hash[cur] = ( for_hash[cur-1] + Binary_expo(base,cur-1) * (s[cur-1]-'A') ) % MOD;

        rev_hash[cur] = ( (rev_hash[cur-1] * base ) % MOD + (s[cur-1]-'A') ) % MOD;

        cout <<s<<" "<< for_hash[cur] <<" "<<rev_hash[cur] <<endl;


        if(for_hash[cur] == rev_hash[cur]) {
            cout<<"Palindrom"<<endl;
        }
        else cout<<"Not Palindrom"<<endl;

    }

    return 0;
}


