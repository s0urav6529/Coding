

bool dp[n+1][m+1];
reset(dp,0);

for(int i=1;i<=n;i++){   ///initialization
    dp[i][a[i]]=1;
}

for(int i=2;i<=n;i++){

    for(int j=0;j<m;j++){

        if(dp[i][j]) continue;  ///when j == a[i](mod m)

        if(dp[i-1][j]){  ///case 1;

            dp[i][j]=dp[i-1][j];
            continue;
        }

        ///case 2
        dp[i][j]=dp[i-1][(j-a[i]+m)%m];   ///do (j - a[i] + m) (mod m) to make sure the value is +ve
    }
}

cout<<(dp[n][0]?"YES":"NO");
