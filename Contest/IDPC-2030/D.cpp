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
const int limit = 1e5+5;



void solution(){
    int n;
    cin >> n;

    int ans=1;

    for(int i=100;i<=n;i++){
        if(n%i==0){
            ans =max(ans,n/i);
        }
    }

    cout << ans <<endl;
    return;
}
int main(){
    int tc = 1;
    //cin >> tc;
    while(tc--){
        solution();
    }
    return 0;
}
