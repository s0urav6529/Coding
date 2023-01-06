


vector<int>adj[limit];
bool vis[limit]={false} , cycle_vis[limit]={false};

bool dfs(int node,int par){
    
    vis[node] = true;
    cycle_vis[node] = true;


    for(int child:adj[node]){

        if(vis[child] == false)
        {	
            if(dfs(child,node) == true) {
            	return true;
            }
        }
        else if(cycle_vis[child] == true) {
        	return true;
        }
    }
    cycle_vis[node] = false;
  
    return false;
}

