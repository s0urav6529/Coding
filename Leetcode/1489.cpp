https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/


vector<int>Parent(105), Rank(105), mst_edges;
int cost , edge;

void init(int n){

    for(int i=0;i<n;i++) 
        Parent[i] = -1;

}
int Find(int node){

    if(Parent[node] < 0) return node;

    return Parent[node] = Find(Parent[node]);

}

void Union(int u, int v, int w, int ith){

    u = Find(u);

    v = Find(v);

    if(u != v){

        if(Rank[v] > Rank[u]) swap(u,v);

        Parent[v] = u;
        
        Rank[u] += Rank[v];

        cost += w;
        edge++;
        mst_edges.push_back(ith);
    }

}

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        int e = edges.size();

        vector<vector<int>>ans(2,vector<int>());
                  //cost           u , v   ith
        vector<pair<int,pair<pair<int,int>,int>>>tree(e);

        

        for(int i=0;i<e;i++){

            tree[i].first = edges[i][2];
            tree[i].second.first.first = edges[i][0];
            tree[i].second.first.second = edges[i][1];
            tree[i].second.second = i;
        }

        sort(tree.begin(),tree.end());

        cost = 0;

        init(n);
        mst_edges.clear();

        for(int i=0;i<e;i++){

            Union(tree[i].second.first.first, tree[i].second.first.second, tree[i].first, tree[i].second.second);

        }

        int mst_cost = cost;

        map<int,int>mp;

        for(int j=0;j<e;j++){

            init(n); cost = 0 , edge = 0 , mst_edges.clear();

            Union(tree[j].second.first.first, tree[j].second.first.second, tree[j].first, tree[j].second.second);
            for(int i=0;i<e;i++){

                if(i != j){
                    Union(tree[i].second.first.first, tree[i].second.first.second, tree[i].first, tree[i].second.second);
                }

            }

            if(edge == n-1 && cost == mst_cost){

                for(int i=0;i<mst_edges.size();i++){
                    mp[mst_edges[i]] = 1;
                }
            }

        }

        for(int j=0;j<e;j++){

            if(mp[tree[j].second.second] != 1) continue;

            init(n); cost = 0 , edge = 0 , mst_edges.clear();

            for(int i=0;i<e;i++){

                if(mp[tree[i].second.second] != 1) continue;

                if(i != j){
                    Union(tree[i].second.first.first, tree[i].second.first.second, tree[i].first, 0);
                }

            }

            if(edge == n-1 && cost == mst_cost){

                ans[1].push_back(tree[j].second.second);
            }
            else  ans[0].push_back(tree[j].second.second);

        }

        return ans;



    }
};
