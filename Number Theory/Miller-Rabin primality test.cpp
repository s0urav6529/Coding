

/// Miller-Rabin Primality test tells us that a number upto 1e18 is prime or no using farmet little thorem

/// https://cp-algorithms.com/algebra/primality_tests.html#miller-rabin-primality-test

/// https://cp-algorithms.com/algebra/primality_tests.html#deterministic-version

/// Time complexity = O(12*log(n))



#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
const int limit=1e6+5;

/////// algo start

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {

    u64 result = 1;
    base %= mod;

    while (e) {
        if (e & 1){
            result = (u128)result * base % mod;
        }
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {

    u64 x = binpower(a, d, n);

    if (x == 1 || x == n - 1){
        return false;
    }
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;

        if (x == n - 1){
            return false;
        }
    }
    return true;
};

bool MillerRabin(u64 n) {
    if (n < 2){
        return false;
    }

    int r = 0;
    u64 d = n - 1;

    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a){
            return true;
        }
        if (check_composite(n, a, d, r)){
            return false;
        }
    }
    return true;
}

//// algo end

int main(){
    fast;
    ll n;
    cin >> n;
    if(MillerRabin(n)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}


