///prime factorizaion O(nlogn(logn))

    ///seive
    vector<int>spf(limit+1,-1);
    for(int i=2;i<=limit;i++){

        if(spf[i]==-1){

            for(int j=i;j<=limit;j+=i){
                if(spf[j]==-1) spf[j]=i;
            }
        }
    }

    ///prime factorization
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        while(x>1){
            x/=spf[x];
        }
    }


///prime factorization with O(sqrt(n))

int n;
cin>>n;

for(int i=2;i*i<=n;i++)
{
    if(n%i==0)
    {
        int cnt=0;

        while(n%i==0)
        {
            cnt++;
            n/=i;
        }
    }
}

if(n>1) cout<<n<<"^"<<1<<endl;
