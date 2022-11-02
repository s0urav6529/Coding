

Variations of catalan numbers

Blog :
https://en.wikipedia.org/wiki/Catalan_number
https://brilliant.org/wiki/catalan-numbers/
https://mathcircle.berkeley.edu/sites/default/files/BMC6/pdf0607/catalan.pdf
https://cp-algorithms.com/combinatorics/catalan-numbers.html




/// Algorithm starts

ll fact[limit],mod_inv[limit],inv_f[limit]  ;

void precompute() {

  mod_inv[0] = mod_inv[1] = 1;
  for(int i = 2; i < limit; i++){
       mod_inv[i] = MOD - 1LL * (MOD / i) * mod_inv[MOD % i] % MOD;
  }

  fact[0] = fact[1] = 1;
  inv_f[0] = inv_f[1] = 1;

  for(int i = 2; i < limit; i++){
       fact[i] = (1LL * fact[i-1] * i) % MOD;
       inv_f[i] = (1LL * mod_inv[i] * inv_f[i-1]) % MOD;
  }

}

ll nCr(ll n, ll r) {
    if(r > n) return 0;
    return (((1LL * fact[n] * inv_f[n-r]) % MOD) * inv_f[r]) % MOD;
}

ll catalan_number(ll n){

    return (mod_inv[n+1] * nCr(2*n , n)) % MOD;

}

int main(){
    int n;
    cin >> n;
    catalan_number(n);
}

/*
input : 4
output : 14
*/





