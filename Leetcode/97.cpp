https://leetcode.com/problems/interleaving-string/description/

int dp[101][101][201];

int solve(int i, int j, int k, string& s1, string& s2, string& s3 ){

    if(i == s1.size() && j == s2.size() && k == s3.size()) {
        return 1;
        
    }


    if(dp[i][j][k] != -1) return dp[i][j][k];

    if((i < s1.size() && s1[i] == s3[k]) && (j < s2.size() && s2[j] == s3[k])){
     
        return dp[i][j][k] = solve(i+1,j,k+1,s1,s2,s3) || solve(i,j+1,k+1,s1,s2,s3) ;
    }
    else if(i < s1.size() && s1[i] == s3[k]){
      
        return dp[i][j][k] = solve(i+1,j,k+1,s1,s2,s3);
    }
    else if(j < s2.size() && s2[j] == s3[k]){

        return dp[i][j][k] = solve(i,j+1,k+1,s1,s2,s3);
    }
    else {
  
        return dp[i][j][k] = 0;
        
    }

}

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int n1 = s1.size() , n2 = s2.size(), n3 = s3.size();

        if(n1 + n2 != n3) return false;

        if(s1 == "" && s2 == "" && s3 == "") return true;

        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                for(int k=0;k<=n3;k++) dp[i][j][k] = -1;
            }
        }

        int ans = solve(0,0,0,s1,s2,s3);

        if(ans == 1) return true;
        return false;


    }
};
