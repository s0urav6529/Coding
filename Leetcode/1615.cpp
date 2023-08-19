https://leetcode.com/problems/maximal-network-rank/

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {

        int k = roads.size();

        vector<int>adj[n];

        for(int i=0;i<k;i++){
            //cout << roads[i][0] <<" "<<roads[i][1]<<endl;
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);

        }

        int ans = 0;

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){
                
                int temp = 0;

                for(auto ch : adj[i]){

                    temp++;

                    //cout << i <<" "<<ch<<endl;

                }

                for(auto ch : adj[j]){

                    if(ch != i) temp++;

                    //cout << j <<" "<<ch<<endl;


                }

                ans = max (ans , temp);
                

            }

        }

        return ans;

    }
};
