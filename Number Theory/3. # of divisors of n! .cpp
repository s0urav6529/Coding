

/// Find the no of divisors of n! 

/// load seive()

void NoOfDiv(ll n){
    ll div = 1 ;

    for(int j=0;prime[j]<=n && j<prime.size();j++){

        ll P = prime[j] , alpha = 0;

        while(P<=n){
            alpha += (n/P);
            P = P*prime[j];
        }
        div = div*(alpha+1LL);

    }
}

/*
input : 4         
output : 8

Since 4! = 24 so 24 has 8 divisors (1 , 2 , 3 , 4 , 6 , 8 , 12 , 24)

*/




