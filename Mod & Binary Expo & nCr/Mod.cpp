
/// **** Factorial code **** Time complexity O(n)
ll fact[limit];

fact[0] = 1;
for(ll i=1;i<limit;i++){
     fact[i]=mulmod(fact[i-1],i);
}

/// ************ Bigmod or Binary Exponentaition *********   Time complexity O(log(n))

ll Mod(ll x){
    return ((x%MOD + MOD)%MOD);
}

ll mulmod(ll a,ll b){
    return Mod(Mod(a)*Mod(b));
}

ll Binary_expo(ll a,ll p){

	ll res=1;
	while(p){

		if(p & 1)
		res=mulmod(res,a);
		p/=2;
		a=mulmod(a,a);
	}
	return res%MOD;
}


//// ************** Modular Inverse *********** Time complexity O(log(n))
	
ll modular_inverse(ll base){
     return Binary_expo(base,MOD-2);	/// base is the denominator
}

/// ************** Modular inverse in range ********* Time complexity O(n)

///  blog : https://cp-algorithms.com/algebra/module-inverse.html#mod-inv-all-num

ll mod_inv[limit];

void range_mod_inverse(){

    mod_inv[1] = 1;

    for(int i=2;i<limit;i++){

        mod_inv[i] = MOD - 1ll * (MOD/i) * mod_inv[MOD % i] % MOD;

    }

}


//// ************  nCr **********************    Time complexity O(log(n))

ll nCr(ll n,ll r){

    ll numerator= fact[n];
    ll denominator = mulmod(fact[r],fact[n-r]);
    return mulmod(numerator, Binary_expo(denominator,MOD-2));
	
}




