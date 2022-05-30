
///Buliding prefix sum of 2D matrix
for(int i=1;i<=n;i++){

    for(int j=1;j<=m;j++){

        a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    }
}

///Finding sum of a rectangle/squre range form 2D prifix sum matrix with binary search

for(int i=1;i<=n;i++){

    for(int j=1;j<=m;j++){  ///travelling matrix

        int l=1;
        int r=min(n-i+1,m-j+1));

        while(l<=r){
            int mid=l+(r-l)/2;

            int bot_right=a[i+mid-1][j+mid-1];
            int bot_left=a[i+mid-1][j-1];
            int top_right=a[i-1][j+mid-1];
            int add=a[i-1][j-1];

            int sum=bot_right-bot_left-top_right+add; ///Here the sum for particular range

            if(sum<=k){
                ans=max(ans,mid);
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
    }
}

