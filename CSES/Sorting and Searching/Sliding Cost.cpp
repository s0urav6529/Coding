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
int Value(ordered_set &s,int idx){
   return (*s.find_by_order(idx));
}
int FirstIdx(ordered_set &s,int x){
    return (s.order_of_key(x));
}
int LastIdx(ordered_set &s,int x){

    if(Value(s,(int)s.size()-1)==x){
        return (int)(s.size())-1;
    }
    return FirstIdx(s,*s.lower_bound(x))-1;
}

void Erase(ordered_set &s,int x){
    s.erase(s.upper_bound(x));
}


int main(){
    fast;
    ordered_set s;
    int n,k;
    cin>>n>>k;
    vector<int>a(n+1),median(n+1,0);

    for(int i=1;i<=n;i++) {
        cin>>a[i];

        Insert(s,a[i]);

        if(i>=k){
            if(i>k) Erase(s,a[i-k]);
            median[i]=Value(s,(k+1)/2-1);
        }
    }
    s.clear();

    for(int i=1;i<k;i++) median[i]=median[k];

    ll ans=0,prev_median;

    for(int i=1;i<=n;i++) {


        if(i>=k){

            if(i==k) {
                prev_median=median[k];

                ans+=abs(median[i]-a[i]);
                Insert(s,a[i]);
                cout<<ans<<" ";
                continue;
            }

            Erase(s,a[i-k]);

            ans-=abs(prev_median-a[i-k]);

            //cout<<i<<" "<<ans<<endl;

            ans+=abs(median[i]-a[i]);

            //cout<<i<<" "<<ans<<endl;

            ll dif=prev_median-median[i];

            ll sm=FirstIdx(s,median[i]);

            ll up=LastIdx(s,median[i]);

            ll len=(int)(s.size());

            ll bg=(len-up)-1;

            ll eq=up-sm+1;

            //cout<<i<<" "<<dif<<" "<<len<<" "<<sm<<" "<<eq<<" "<<bg<<endl;

            if(dif<0){  ///cur is big

                ans+=(dif*bg);
                ans-=(sm*dif);
                ans+=(eq*dif);

            }
            else if(dif>0){  ///cur is small

                ans+=(dif*bg);
                ans-=(sm*dif);
                ans-=(eq*dif);
            }

            Insert(s,a[i]);

            prev_median=median[i];

            cout<<ans<<" ";
        }
        else {
            Insert(s,a[i]);
            ans+=abs(median[i]-a[i]);
        }

    }
    cout<<endl;
    return 0;
}



