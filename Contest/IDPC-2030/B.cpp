#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie.(0);cout.tie(0);
#define ff first
#define ss second
#define pb push_back
#define pi acos(-1.0)
#define sort(k) sort(k.begin(0),k.end())
#define sortg(k) sort(k.begin(0),k.end(),greater<int>())
#define uniq(k) k.resize(distance(k.begin(),unique(k.begin(),k.end())))
typedef long long int ll;
constexpr ll MOD = 1e9+7;
const int limit = 1e6+5;
ll dp[limit];
void pre_load(){
    int a[3]={1,3,3};
    dp[0] = 1;
    for(int i=1;i<limit;i++) dp[i] = 0;
    for(int i=1;i<limit;i++){

        for(int j=0;j<3;j++){
            if(i>=a[j])
                dp[i] = (dp[i] + dp[i-a[j]])%MOD;
        }


    }
}
void solution(){
    int n;
    cin >> n;
    cout <<dp[n] <<endl;
    return;
}
int main(){

    pre_load();
    int tc = 1;
    cin >> tc;
    while(tc--){
        solution();
    }
    return 0;
}
