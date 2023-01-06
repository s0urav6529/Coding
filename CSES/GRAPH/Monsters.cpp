#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
#define reset(a,b)   memset(a, (b), sizeof(a))
#define sortv(k)     sort(k.begin(),k.end())
#define sortg(k)     sort(k.begin(),k.end(),greater<int>())
#define uniq(vec)    vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())))
#define rev(k)       reverse(k.begin(),k.end())
#define umin(a,b)    a=min(a,b)
#define umax(a,b)    a=max(a,b)
#define min3(a,b,c)  min(a, min(b,c))
#define pyes         cout<<"Yes"<<endl
#define pno          cout<<"No"<<endl
#define pf(a)        cout<<a<<endl
#define p2f(a,b)     cout<<a<<" "<<b<<endl
#define p3f(a,b,c)  cout<<a<<" "<<b<<" "<<c<<endl
#define p4f(a,b,c)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define ff first
#define ss second
#define pb push_back
#define pi acos(-1.0)
//cin.get();
typedef long long int ll;
//typedef unsigned long long int llu;
//constexpr llu Mx=18446744073709551615;
constexpr ll MOD=1e9+7;
const int limit=1e3+1;

char grid[limit][limit];
int monstar_dist[limit][limit];
int A_dist[limit][limit];

int n , m , ax , ay;
             
        ////  L , R , U , D
int dx[4] = { 0, 0, -1, 1 }; 
int dy[4] = { -1, 1, 0, 0 };

struct node{
	int x,y,step,par;
};


void an1nd1ta(int tc){
    
    
    cin >> n >> m;

    queue<node>q;

    for(int i=1;i<=n;i++){
    	string s;
    	cin >> s;
    	for(int j=1;j<=m;j++){

    		grid[i][j] = s[j-1];

    		if(s[j-1] == 'M'){

    			q.push({i,j,0,-1});  /// in par we push -1 because we didnot need this info for monstar
    			
    		}
    		if(s[j-1] == 'A'){

    			ax = i;
    			ay = j;
    		}
    	}
    }

    for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++) monstar_dist[i][j] = -1;

    }


    while(q.size() > 0){

    	node mon = q.front();
    	q.pop();

        int cx = mon.x , cy = mon.y , st = mon.step;

        if(cx<1 || cx>n || cy<1 || cy>m || grid[cx][cy] == '#'
         || monstar_dist[cx][cy] != -1) continue;

    	
        monstar_dist[cx][cy] = st;

    	for(int i=0;i<4;i++){

            q.push({cx+dx[i],cy+dy[i],st+1,-1});
    	}
    }

    while(q.size() > 0) q.pop();

     for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++) A_dist[i][j] = -1;

    }

    q.push({ax, ay , 0 , 0});

    bool parbo = false;

    int parent[n+1][m+1];

     for(int i=1;i<=n;i++){

        for(int j=1;j<=m;j++) parent[i][j] = 0;

    }

    string path="";

    while(q.size() > 0 ){

        node A = q.front();

        q.pop();

        int curx = A.x, cury = A.y;

        A_dist[curx][cury] = A.step;

        parent[curx][cury] = A.par;

        if(curx == n || curx == 1 || cury == 1 || cury == m ){

            while(curx != ax or cury != ay){

                if(parent[curx][cury] == 0) path += "L" ,cury++;
                else if(parent[curx][cury] == 1) path += "R" , cury--;
                else if(parent[curx][cury] == 2) path += "U" , curx++;
                else if(parent[curx][cury] == 3) path += "D" , curx--;

            }

            rev(path);
            parbo = true;
            break;

        }

        for(int i=0;i<4 ;i++){

            curx = A.x + dx[i] , cury = A.y + dy[i] ;
            
            if(curx<1 || curx>n || cury<1 || cury>m || grid[curx][cury] == '#' ||
                A_dist[curx][cury] != -1 || (monstar_dist[curx][cury] >= 0 && 
                    monstar_dist[curx][cury] <= A.step+1)){
                continue;
            }

            A_dist[curx][cury] = A.step+1;
            q.push({curx,cury,A.step+1,i});

        }

    }


    if(parbo){

        cout<<"YES"<<endl<<path.size()<<endl<<path<<endl;

    }
    else cout<<"NO"<<endl;

    

    return;
}

int main(){
    fast;
    int testcase=1;
    //cin >> testcase;
    for(int T=1;T<=testcase;T++) an1nd1ta(T);
    return 0;
}