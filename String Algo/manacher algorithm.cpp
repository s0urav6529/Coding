#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=2e6+5;

///lps = longest palindromic substring
vector<int>lps(limit);

void manacher(string s , string p){

    int n=s.size() , maxlen = 0 ,maxindex = 0;

    for(int i=1 , center=0 , radius=0 ; i<n-1 ; i++){

        int mirror = center - (i -center);

        if( i < radius ){  /// Give an initial lps value
            lps[i] = min(lps[mirror] , radius-i);
        }

        while( s[i - lps[i] - 1] == s[i + lps[i] + 1]){  ///iterative check
            lps[i]++;
        }

        if(i+lps[i] > radius){  ///update center & radius
            center = i;
            radius = i+lps[i];
        }

        if(maxlen < lps[i]) {  /// updating the max lps
            maxlen = lps[i];
            maxindex = i;
        }
    }

    /// start index of substring in converted string s
    int id1 = maxindex - maxlen + 1;

    /// start index of substring in actual string p
    int id2 = (id1 - 2)/2;

    cout << p.substr(id2 , maxlen) <<endl;


    return;

}

int main(){
    fast;

    string s , p;
    cin >> p;

    s.push_back('@');

    for(char c:p){
        s.push_back('#');
        s.push_back(c);
    }
    s.push_back('#');
    s.push_back('$');

    manacher(s, p);


    return 0;
}



