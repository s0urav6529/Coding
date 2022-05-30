

///Count the number of divisors of a number using seive  O(logn)

int countdivisor(int n)   ///first pre-load the prime array using seive
{
    int divisor=1;
    for(int i=0;prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {
            int cnt=1;
            while(n%prime[i]==0)
            {
                cnt++;
                n/=prime[i];
            }
            divisor*=cnt;
        }
    }
    return divisor;
}




///Number of common divisor of two number O(log(n)^2)

map<ll,ll>PF;

void primefactor(ll n) ///here n is one of the number between two
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int divisor=0;
            while(n%i==0)
            {
                divisor++;
                n/=i;
            }
            PF[i]=divisor;
        }
    }

    if(n>1) PF[n]=1;
}

void solution()
{
    ll totaldivisor=1;

    for(pair<ll,ll>p : PF)
    {
        ll divisor=0;

        while(k%p.first==0)  /// here k is another number
        {
            divisor++;
            k/=p.first;
        }
        totaldivisor*=min(divisor,p.second)+1;  ///taking the common factors
    }
    cout<<totaldivisor<<endl;
    return;
}




///summation of Divisor of a number including this number as a divisor and excluding 1 as a divisor

bool isprime[1000005];
int prime[1000005];
void seive(int n)
{
    isprime[1]=true;
    int k=0;
    for(int i=2;i*i<=n;i++)
    {
        if(isprime[i]==0)
        {
            for(int j=i*i;j<=n;j+=i)isprime[j]=true;

            prime[k++]=i;
        }
    }
}
int summation(int n)
{
    int total=1;

    for(int i=0;prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {
            int cnt=1;
            while(n%prime[i]==0)cnt++,n/=prime[i];

            total*=((pow(prime[i],cnt)-1)/(prime[i]-1));
        }
    }
    if(n>1)  total*=(pow(n,2)-1)/(n-1);

    return total;
}



