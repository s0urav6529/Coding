https://leetcode.com/problems/maximum-length-of-pair-chain/

int dp[1005][1005];

int solve(int i ,int j,vector<vector<int>>&pairs){

    if(i == -1) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(j == pairs.size()){
        return dp[i][j] = max(1 + solve(i-1,i,pairs), solve(i-1,j,pairs));
    }
    else{
        
        if(pairs[j][0] > pairs[i][1]){
            return dp[i][j] = max(1 + solve(i-1,i,pairs), solve(i-1,j,pairs));
        }
        else{
            return dp[i][j] = solve(i-1,j,pairs);
        } 
    }


}

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int n = pairs.size();

        sort(pairs.begin(),pairs.end());

        //for(int i=0;i<n;i++) cout << pairs[i][0] <<" "<<pairs[i][1] <<endl;

        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++) dp[i][j] = -1;
        }

        return solve(n-1,n,pairs);


    }
};
