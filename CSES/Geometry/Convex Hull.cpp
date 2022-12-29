#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;


/// Code from: https://github.com/tonymontaro/algorithm-video-solutions/blob/main/CSES/geometry/convext_hull.cpp

class ConvexHull {
public:

    int n;

    vector<pair<ll,ll>> getConvexHullPoints(int totalPoints, vector<pair<ll,ll>> &points) {
        n = totalPoints;
        sortPoints(points);
        auto lowerHullPoints = getPointsOnTheLowerHull(points);
        auto upperHullPoints = getPointsOnTheUpperHull(points);
        return getUniquePoints(lowerHullPoints, upperHullPoints);
    }

    void sortPoints(vector<pair<ll,ll>> &points) {

        sort(points.begin(), points.end(), [](pair<ll,ll> &a, pair<ll,ll> &b){  /// sort according to x axis, otherwise y axis
            if (b.first < a.first) return false;
            if (b.first == a.first) return a.second > b.second;
            return true;
        });
    }
    vector<pair<ll,ll>> getPointsOnTheLowerHull(vector<pair<ll,ll>> &points) {
        vector<pair<ll,ll>> stk;
        for (int i = 0; i < n; i++) {
            while (stk.size() > 1 && isClockWiseMovement(stk[stk.size()-2], stk.back(), points[i]))
                stk.pop_back();
            stk.push_back(points[i]);
        }
        return stk;
    }
    vector<pair<ll,ll>> getPointsOnTheUpperHull(vector<pair<ll,ll>> &points) {
        vector<pair<ll,ll>> stk;
        for (int i = n - 1; i >= 0; i--) {
            while (stk.size() > 1 && isClockWiseMovement(stk[stk.size()-2], stk.back(), points[i]))
                stk.pop_back();
            stk.push_back(points[i]);
        }
        return stk;
    }
    bool isClockWiseMovement(pair<ll,ll> &a, pair<ll,ll> &b, pair<ll,ll> &c) {
        return crossProduct(a, b, c) > 0;
    }
    ll crossProduct(pair<ll,ll> &a, pair<ll,ll> &b, pair<ll,ll> &c) {
        return ((a.first - b.first) * (c.second - b.second)) - ((a.second - b.second) * (c.first - b.first));
    }
    vector<pair<ll,ll>> getUniquePoints(vector<pair<ll,ll>> &lowerHullPoints, vector<pair<ll,ll>> &upperHullPoints) {
        set<pair<ll,ll>> seen;
        vector<pair<ll,ll>> answer;
        for (auto &p: lowerHullPoints) {
            if (seen.find(p) != seen.end()) continue;
            answer.push_back(p);
            seen.insert(p);
        }
        for (auto &p: upperHullPoints) {
            if (seen.find(p) != seen.end()) continue;
            answer.push_back(p);
            seen.insert(p);
        }
        return answer;
    }
};

int main() {
    fast;

    int n;
    cin >> n;
    vector<pair<ll,ll>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    ConvexHull convexHull;
    vector<pair<ll,ll>> answer = convexHull.getConvexHullPoints(n, arr);
    cout << answer.size() << endl;
    for (auto &p: answer)
        cout << p.first << " " << p.second << endl;

    return 0;
}
