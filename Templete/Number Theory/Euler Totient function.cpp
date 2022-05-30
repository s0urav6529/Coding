///Euler Totient function using prime factorization O(sqrt(n))

int n;
cin>>n;
int res=n;

for(int i=2;i*i<=n;i++)   ///sqrt(n)
{
    if(n%i==0)
    {
        while(n%i==0) n/=i;

        res=res/i;
        res=res*(i-1);
    }
}
if(n>1) res=res/n , res=res*(n-1);

cout<<res<<endl;



///Euler Totient Function using seive O(nlogn(logn))

int etf[1000001];
void ETF(int N)
{
    for(int i=1;i<=N;i++) etf[i]=i;

    for(int i=2;i<=N;i++)
    {
        if(etf[i]==i)
        {
            for(int j=i;j<=N;j+=i)
            {
                etf[j]/=i;
                etf[j]*=(i-1);
            }
        }
    }
}
int query;
cin>>query;
ETF(1000000);
while(query--)
{
    cin>>n;
    cout<<etf[n]<<endl;
}


/// Find the sum of GCD from 1 to N using Euler totient function in  O(nlog(logn)+sqrt(n))

int n,maxN=100001;
int etf[maxN];

for(int i=1;i<=maxN;i++) etf[i]=i;   ///pre-load all the index with its value

for(int i=2;i<=maxN;i++)
{
    if(etf[i]==i)   ///it a prime number so update its multiples
    {
        for(int j=i;j<=maxN;j+=i)
        {
            etf[j]/=i;    ///using fomula of phi(n) = n*(p-1)/p;
            etf[j]*=(i-1);
        }
    }
}
int query=1;
cin>>query;
while(query--)
{
    int ans=0;
    cin>>n;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            int d1=i;  ///divisor 1
            int d2=n/i; ///divisor 2

            ans+=d1*(etf[n/d1]);   ///using ETF we count how many times this divisor occure

            if(d1==d2) continue;   ///if they are perfect sqrt

            ans+=d2*(etf[n/d2]);  ///using ETF we count how many times this divisor occure
        }
    }
    cout<<ans<<endl;
}


