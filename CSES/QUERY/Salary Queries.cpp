#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long int ll;
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);




int main(){
    fast;

    int n , q;

    cin >> n >> q;

    ordered_set s;

    ll a[n+4];

    for(int i=1;i<=n;i++) {

        cin >> a[i];

        s.insert(a[i]);

    }
    s.insert(1e9+2);


    while(q--){

        char c;
        cin >> c;

        if(c=='?'){

            ll a,b;

            cin >> a >> b;

            int l = s.order_of_key(a);

            int r = s.order_of_key(b+1);

            cout <<r-l<<endl;


        }
        else{
            int k;
            ll x;

            cin>> k >> x;

            int pos = s.order_of_key(a[k]);

            s.erase(s.find_by_order(pos));

            a[k]=x;

            s.insert(a[k]);


        }
        //cout<< s.size() <<endl;
    }
    return 0;
}



