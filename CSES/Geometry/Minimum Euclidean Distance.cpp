#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;

ll Euclidean_Distance(pair<ll,ll> a, pair<ll,ll> b) {
    return (b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second);
}

int main(){

    int n;
    cin>>n;
    vector<pair<ll,ll>> a(n);

    ll Min_dist = LLONG_MAX;

    for(int i=0; i<n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    set<pair<ll,ll>>s;
    s.insert({a[0].second, a[0].first});

    for(int i=1,j=0; i< n; i++) {

        auto it = s.begin();
        ll dd = ceil(sqrt(Min_dist));

        while(j<i && a[j].first < a[i].first - dd) {
            s.erase({a[j].second, a[j].first});
            j++;
        }

        auto l = s.lower_bound({a[i].second - dd, 0LL});
        auto r = s.upper_bound({a[i].second + dd, 0LL});

        for (auto it=l; it != r; it++) {
            Min_dist = min(Min_dist, Euclidean_Distance({it->second, it->first}, a[i]));
        }

        s.insert({a[i].second, a[i].first});
    }
    cout << Min_dist <<endl;
}
