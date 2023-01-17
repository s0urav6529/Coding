
/// Ekta node theke start kore protekta edge ekbar kore ghure abar starting node e aste parle euler circuit pabo
/// Time complexity O(n+m)

vector<pair<int,int>>adj[limit] ;
bool vis[2*limit]={false};  /// 2*limit = number of edges(m)
int current_address[limit];
vector<int>ans;
 
void dfs(int node) {
 
    /// Using current address of a node because we didn't want to recheck again what we already check previous
    for (int &i = current_address[node] ; i < adj[node].size() ; i++ ) {
        
        auto[vertex , edges] = adj[node][i];
 
        if (vis[edges] == false) { 
            
            vis[edges] = true;
            
            dfs(vertex);
        }
 
    }
    ans.push_back(node);
}
 
void main(int tc){
    
    int n , m;
    scanf("%d %d",&n , &m);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        
        scanf("%d %d",&u , &v);
 
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
 
    for (int i = 1; i <= n; i++) {  /// if any node has odd edges then no eulerian circuit
        if (adj[i].size() & 1) {
            printf("IMPOSSIBLE\n");
            return;
        }
    }
    dfs(1);
    if (ans.size() != m + 1) printf("IMPOSSIBLE\n");
    else {  /// Printing the eulerian circuit
        for (auto&x : ans) printf("%d ",x);
        printf("\n");
    }
    return;
}
