Problem link : CSES - Planet Queries I :  https://cses.fi/problemset/task/1750

const int limit=2e5+5;
const int MaxN=30;

int LCA[MaxN+5][limit];

void an1nd1ta(int tc){
    
    int n , q;
    cin >> n >> q;

    memset(LCA,-1,sizeof LCA);

    for(int i=1;i<=n;i++){
        cin >> LCA[0][i];  ///2^0 th child
    }

    for(int j=1;j<MaxN;j++){

        for(int i=1;i<=n;i++){
            
            if(LCA[j-1][i] == -1) continue;

            int par = LCA[j-1][i];

            LCA[j][i] = LCA[j-1][par];

        }

    }

    while(q--){
        int x, k;
        cin >> x >> k;   /// k'th successor of node x

        for(int i=0;i<MaxN;i++){
            if(k & (1<<i)) x = LCA[i][x];
        }

        cout << x <<endl;
    }


    return;
}

int main(){
    fast;
    int testcase=1;
    cin >> testcase;
    for(int T=1;T<=testcase;T++) an1nd1ta(T);
    return 0;
}   
