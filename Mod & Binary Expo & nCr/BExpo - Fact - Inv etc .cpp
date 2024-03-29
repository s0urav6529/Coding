
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

ll bigmod(ll a,ll p){
	ll res=1;
	while(p){

	    if(p & 1){
		res=mulmod(res,a);
	    }
	    a=mulmod(a,a);
	    p = (p >> 1);
	}
	return res%MOD;
}


//// ************** Modular Inverse *********** Time complexity O(log(n))
	
ll modular_inverse(ll base){
     return bigmod(base,MOD-2);	/// base is the denominator
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
    
    if(r>n) return 0;
    
    ll numerator= fact[n];
    ll denominator = mulmod(fact[r],fact[n-r]);
    return mulmod(numerator, bigmod(denominator,MOD-2));
	
}

   ****** for Handling without mod ******

ll nCr(ll n,ll r) {
    ll res=1;

    if(r>n) return 0;

    if(r > (n-r)) r=n-r;

    for(ll i=1;i<=r;i++){
        res*=(n-i+1);
        res/=i;
    }
    return res;
}



/// ************* factorial  & Inverse factorial of a certain range ********** Time complexity O(n)

ll fact[limit], inv_f[limit];

void precompute() {

  /// first calucalte i^(-1)
  inv_f[0] = inv_f[1] = 1;
  for(int i = 2; i < limit; i++){
       inv_f[i] = MOD - 1LL * (MOD / i) * inv_f[MOD % i] % MOD;
  }

  /// Calculate factorial & Inverse factorial (i^(-1))!
  fact[0] = fact[1] = 1;
  for(int i = 2; i < limit; i++){
       fact[i] = (1LL * fact[i-1] * i) % MOD;
       inv_f[i] = (1LL * inv_f[i] * inv_f[i-1]) % MOD;
  }

}

ll nCr(ll n, ll r) {
    if(r > n) return 0;
    return (((1LL * fact[n] * inv_f[n-r]) % MOD) * inv_f[r]) % MOD;
}


//// *************** ***********************




