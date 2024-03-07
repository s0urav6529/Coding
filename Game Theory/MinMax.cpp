https://leetcode.com/problems/stone-game/

int dp[501][501][3];

int rec(int l ,int r, int t,vector<int>&piles){

    if(l>r){
        return 0;
    }

    if(dp[l][r][t] != -1){
        return dp[l][r][t];
    }

    if(t == 1){
        return dp[l][r][t] = max(piles[l] + rec(l+1,r,2,piles) , piles[r] + rec(l,r-1,2,piles));
    }
    else{
        return dp[l][r][t] = min(rec(l+1,r,1,piles) , rec(l,r-1,1,piles));
    }

}

class Solution {
public:
    bool stoneGame(vector<int>& piles) {

        int n = piles.size();

        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                for(int k=0;k<=2;k++){
                    dp[i][j][k] = -1;
                }
            }
        }

        int sum = 0;

        for(int i=0;i<n;i++){
            sum += piles[i];
        }

        int score = rec(0,n-1,1,piles);

        sum -= score;
        
        return (score > sum) ? 1 : 0;
    }
};
