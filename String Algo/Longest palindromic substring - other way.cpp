int main(){
  
      string s;
      int n = s.size();
    
      int dp[n+1][n+1];
      
      int mx=1,st=0;

      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++) {
              if(i == j) dp[i][j] = 1;
              else if(j-i == 1 && s[i]==s[j]) dp[i][j] = 1 , mx = 2 , st = i;
              else dp[i][j] = 0;
          }
      }
      
      for(int len = 3; len <= n ; len++ ){
              
          for(int i=0;i<n;i++){
              
              int j = min(i + len - 1,n-1);

              if(j-i+1 < 3) continue;

              if(s[i] == s[j] && dp[i+1][j-1] == 1){
                  dp[i][j] = 1;
              }
              
              if(dp[i][j] && (j-i+1) > mx){
                  st = i ;
                  mx = j-i+1;
              }
              
          }
          
      }
      string ans = "";

      for(int i=st;i<st+mx;i++) ans += s[i];

      cout << ans << endl;
}
