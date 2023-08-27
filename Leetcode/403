https://leetcode.com/problems/frog-jump/description/

int dp[2001][2010];
map<int,int>pos;
set<int>s;

int solve(int i, int k,int n, vector<int>& stones){

    if(i == n-1) {
      return 1;
    }

    if(dp[i][k] != -1) return dp[i][k];

    int j1 = k-1 , j2 = k , j3 = k+1;

    bool notpossible = true;

    int id1 = 0,id2 = 0,id3 = 0; 
    if(s.count(stones[i] + j1) > 0 && i > 0){
        id1 = pos[stones[i] + j1];
    }
    if(s.count(stones[i] + j2) > 0){
        id2 = pos[stones[i] + j2];
    }
    if(s.count(stones[i] + j3) > 0 && i > 0){
        id3 = pos[stones[i] + j3];
    }

    int ans = 0;

    if(id1 > i){
        notpossible = false;
        ans = max(ans , solve(id1,j1 , n, stones));
        
    }

    if(id2 > i){
        notpossible = false; 
        ans = max(ans , solve(id2,j2 , n, stones));
    }

    if(id3 > i){
        notpossible = false;
        ans = max(ans , solve(id3,j3 , n, stones));
    }

    if(notpossible) {
        return dp[i][k] = 0;
    }

    return dp[i][k] = ans;
}

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        for(int i=0;i<=n;i++){
            for(int j=0;j<=n+5;j++){
                dp[i][j] = -1;
            }
        }
        s.clear();
        pos.clear();
        for(int i=0;i<n;i++) {
            pos[stones[i]] = i;
            s.insert(stones[i]);
        }
        int ans = solve(0,1,n,stones) ;
        if(ans == 1) return true;
        return false;

    }
};

