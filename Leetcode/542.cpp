https://leetcode.com/problems/01-matrix/


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size(), m = mat[0].size();

        int dx[]={-1,0,1,0};
        int dy[]={0,-1,0,1};

        vector<vector<int>>ans(n,vector<int>(m));
        bool vis[n][m];
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int, int>>>>pq;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(mat[i][j] == 0) {
                    pq.push({0,{i,j}});
                    ans[i][j] = 0;
                }
                else ans[i][j] = 100000000;
                vis[i][j] = false;
            }
        }

        while(pq.size() > 0){

            int r = pq.top().second.first;
            int c = pq.top().second.second;
            int cost = pq.top().first;

            pq.pop();

            if(vis[r][c] == true) continue;

            vis[r][c] = true;


            for(int k = 0 ; k<4; k++){
                                
                int nr = r+dx[k], nc = c+dy[k];
                if(nr < 0 || nr >= n || nc <0 || nc >= m || vis[nr][nc] == true);
                else if(ans[nr][nc] < cost + 1);
                else {
                    pq.push({cost+1,{nr,nc}});
                    ans[nr][nc] = cost+1;
                }

            }

        }
        return ans;


    }
};
