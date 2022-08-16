

///Given some 2D points of a simple polygone . Find the area of the polygone.

    int n,ans=0,j=1;
    cin>>n;
    ll x[n+2],y[n+2];
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];

    for(int i=1;i<=n;i++){
        j++;
        if(i==n) j=1;
 
        ans+=((x[i]-x[j])*(y[i]+y[j]));
 
    }
    cout<<abs(ans)<<endl;


