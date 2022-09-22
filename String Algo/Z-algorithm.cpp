
/// Finding the longest prefix stated from any index s[i] which is also a proper prefix from index s[0]

/// Time complexity is O(n)

#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=1e2+5;

string s;
vector<int>Z(limit);
int n;

void Z_function(){


    for (int i=1, l=0, r=0; i<n ; i++) {

        if (i <= r){
            Z[i] = min (r-i+1, Z[i-l]);  /// already calculated
        }

        while ( (i + Z[i]) < n && ( s[Z[i]] == s[i+Z[i]]) ){   /// iteratively matching
            Z[i]++ ;
        }

        if ( ( i+Z[i]-1 ) > r){   ///updating the l & r value if find a larger one
            l = i;
            r = i + Z[i]-1;
        }
    }
    return;

}

int main(){
    fast;

    cin >> n >> s;

    Z_function();

//    for(int i=0 ;i <=n;i++) cout<<Z[i] <<" ";
//    cout<<endl;

    return 0;
}




