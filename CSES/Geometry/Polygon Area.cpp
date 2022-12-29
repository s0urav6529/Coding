#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

ll poly_area(vector<pair<ll,ll>>&poly,int n){

    ll area = 0;
    for(int i=0;i<n;i++){

        area += (poly[i].first*poly[(i+1)%n].second) - (poly[(i+1)%n].first*poly[i].second);

    }
    area = abs(area);

    return area;

}

void run_case(){


    int n;
    cin>>n;
    vector<pair<ll,ll>>poly(n);

    for(int i=0;i<n;i++) {
        cin>>poly[i].first>>poly[i].second;
    }

    ll area = poly_area(poly,n);

    cout<<area<<endl;
    return;
}

int main(){
    fast;
    int tc=1;
    //cin>>tc;
    while(tc--) run_case();
    return 0;
}




