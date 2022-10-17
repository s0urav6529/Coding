
///Primality test with farmet little theorem O(logn)

///comment the defined mod;

    ll mulmod(ll a,ll b,ll c){

        ll x=0,y=a%c;

        while(b>0){
            if(b%2==1){
                x=(x+y)%c;
            }
            y=(y*2ll)%c;
            b/=2;
        }
        return x%c;
    }

    ll Binary_expo(ll a,ll n)
    {
        ll res=1;
        while(n)
        {
            if(n&1)
            res=mulmod(res,a);

            n/=2;
            a=mulmod(a,a);
        }
        return res%MOD;
    }

    bool farmet_prime_test(ll n,int iterations=5)
    {
        if(n<=4)
        return n==2 || n==3;

        for(int i=1;i<=iterations;i++)
        {
            ll a=2+rand()%(n-3);
            ll res=Binary_expo(a,n-1,n);

            if(res!=1) return false;
        }
        return true;
    }




