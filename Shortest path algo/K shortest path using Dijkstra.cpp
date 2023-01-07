

/// Using dijkstra algorithm we can find the k shortest path from node 1 to node n.


vector<pair<int,ll>>adj[limit];
ll dis[limit][100]; /// dis[n][k]
int n , m ,k;

void dijkstra(){

	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>> >p;

	p.push({0,1});

	while(p.size() > 0){

		int node = p.top().second;
		ll node_cost = p.top().first;

		p.pop();

		if(dis[node][k] < node_cost) continue;

		for(pair<int,ll> v : adj[node]){

			int child = v.first;
			ll child_cost = v.second;

			if(dis[child][k] > node_cost + child_cost){

				dis[child][k] = node_cost + child_cost;

				p.push({dis[child][k],child});

				sort(dis[child]+1 , dis[child]+k+1);

			}

		}

	}

}

void an1nd1ta(int tc){

	cin >> n >>  m >>  k;

	for(int i=1;i<=m;i++){

		int a , b ;
		ll c;

		cin >> a >> b >> c;

		adj[a].pb({b,c});

	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			dis[i][j] = 1e18;
		}
	}

	dijkstra();
  
  ///The first k shortest path from source(1) to destination(n)
	for(int i=1;i<=k;i++) cout<<dis[n][i]<<" ";
	cout<<endl;

    
    return;
}
