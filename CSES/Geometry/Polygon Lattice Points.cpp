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
    return area/2LL;

}

ll boundary_latticpoint(vector<pair<ll,ll>>&poly,int n){

    ll points = 0;
    for(int i=0;i<n;i++){

        ll delx = abs(poly[i].first - poly[(i+1)%n].first);
        ll dely = abs(poly[i].second - poly[(i+1)%n].second);

        points += __gcd(delx , dely) - 1;  ///Excluding endpoints because they count twice

    }

    return points+n;  ///Adding all the endpoints once
}

void an1nd1ta(int tc){

    int n;
    cin >> n;
    vector<pair<ll,ll>>poly(n);

    for(int i=0;i<n;i++){
        cin >> poly[i].first >> poly[i].second;
    }
    ll A = poly_area(poly,n);

    ll b = boundary_latticpoint(poly,n);

    ll i = A+1-(b/2LL);

    cout <<i<<" "<<b <<endl;

    return;
}

int main(){
    fast;
    int testcase=1;
    for(int T=1;T<=testcase;T++) an1nd1ta(T);
    return 0;
}
