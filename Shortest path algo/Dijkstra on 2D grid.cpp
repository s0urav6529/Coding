
///Finding the shortest cost path to reach from (1,1) to (n,m);

intput:
/*
10   
5 5
1 5  8  7  4
0 10 0  0  0
0 15 0  5  0
0 3  0  20 0
0 0  0  10 0
*/
output
/*

cost = 1

*/



#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const int limit=25;

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

int dp[limit][limit];    // for storing distance
int a[limit][limit];   /// any index given value
bool vis[limit][limit];
int n , m;

bool isvalid(int x,int y){
  
    if(x<1 || x>n || y<1 || y>m || vis[x][y] == true) return false;
    return true;
}


void run_case(int t){


    cin >> n >>m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) {
            cin >> a[i][j];
            dp[i][j] =  1e9;
            vis[i][j] =false;
        }
    }
  
    dp[1][1] = a[1][1];

    /// cost , x , y
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

    pq.push({a[1][1],{1,1}});

    while(pq.size()>0){

        int val = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;

        pq.pop();

        if(vis[x][y] == true) continue;

        vis[x][y] =true;

        for(int i=0;i<4;i++){

            int nx = x+dx[i];
            int ny = y+dy[i];

            if(isvalid(nx,ny) && (dp[nx][ny]>dp[x][y]+a[nx][ny])){

                dp[nx][ny] = dp[x][y]+a[nx][ny];
                pq.push({dp[nx][ny],{nx,ny}});
            }
        }

    }

    cout<<"Case "<<t<<": Penalty = "<<dp[n][m]<<endl;

    return;
}

int main(){
    fast;
    int tc=1;
    cin>>tc;
    for(int t=1;t<=tc;t++) run_case(t);
    return 0;
}
