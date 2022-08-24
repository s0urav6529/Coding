#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
namespace __gnu_pbds{ typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; }
using namespace __gnu_pbds;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e2+5;


void Insert(ordered_set &s,int x){
     s.insert(x);
}

void Erase(ordered_set &s,int x){
    s.erase(s.upper_bound(x));
}

int Value(ordered_set &s,int idx){
   return (*s.find_by_order(idx));
}

int main(){
    fast;
    ordered_set s;
    int n,k;
    cin>>n>>k;
    vector<int>a(n+1);

    for(int i=1;i<=n;i++) {
        cin>>a[i];

        Insert(s,a[i]);
        if(i>=k){
            if(i>k) Erase(s,a[i-k]);
            cout<<Value(s,(k+1)/2-1)<<endl;

        }

    }
    return 0;
}


