#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=1e2+5;

int main(){
    fast;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string>ans;
    do {
        ans.push_back(s);
    } while(next_permutation(s.begin(), s.end()));

    cout<<ans.size()<<endl;
    for(auto i:ans) cout<<i<<endl;

    return 0;
}



