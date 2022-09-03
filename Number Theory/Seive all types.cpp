///seive with bool

#define limit 1000008
bool vis[limit];
vector<int>prime;
void seive()
{
    vis[0]=vis[1]=1;
    for(int i=4; i<limit; i+=2) vis[i] = 1;
    for(int i=3; i*i<limit; i+=2)
    {
        if(vis[i]) continue;
        for(int j=i*i; j<limit; j+=2*i)
        {
            vis[j] = 1;
        }
    }
    prime.pb(2);
    for(int j=3; j<limit; j+=2)
    if(vis[j]==0)
        prime.pb(j);
}


///seive upto 10e7

const int N=1e7+2;
vector<bool>prime(N,true);

void sieve()
{
	prime[0]=prime[1]=false;
	for(int i=2;i*i<=N;i++)
	{
		if(prime[i])
		{
			for(int j=i*i;j<=N;j+=i)
				prime[j]=false;
		}
	}
}


///seive with bitset

void seive(int N)
{
    vector<int>prime;

    bitset<1000001>isprime;  ///it can take upto 10r7

    isprime.set();  ///set all the number

    for(int i=2;i*i<=N;i++)
    {
        if(isprime[i])
        {
            for(int j=i*i;j<=N;j+=i) isprime[j]=0; ///reset the number

            prime.push_back(i); ///push prime in vector
        }
    }

    for(auto i:prime) cout<<i<<" ";
}


///segmented seive

vector<int>primes;  ///collecting all the primes uptill sqrt(right) segment

void sqrtprime(int n) ///generating all primes number sqrt(Right) segment
{
    vector<int> isprime(n+1,0);

    isprime[1]=1;

    for(int i=2;i*i<=n;i++)

        if(isprime[i]==0)
        {
            for(int j=i*i;j<=n;j+=i)
                isprime[j]=1;
        }

    for(int i=1;i<=n;i++)
        if(isprime[i]==0) primes.push_back(i);
}
void primegenerator(int L,int R) ///taking the left and the right segment
{
    if(L==1) L++;

    int index=R-L+1;  ///creating an array of index right-left+1 size

    vector<int>ans(index,0);

    for(auto p:primes)
    {
        if(p*p<=R)
        {
            int i=(L/p)*p;  ///finding the first divisor of p primes

            if(i<L) i+=p;  ///if it is below left segment.

            for(;i<=R;i+=p)
            {
                if(i!=p) ans[i-L]=1;  ///updating all the primes by [number-left] as a index
            }
        }
    }

    for(int i=0;i<index;i++)
    {
        if(ans[i]==0) cout<<L+i<<endl;
    }
}
