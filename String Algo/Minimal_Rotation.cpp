#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen  ("out.txt","w",stdout);
#define reset(a,b)   memset(a, (b), sizeof(a))
#define sortv(k)     sort(k.begin(),k.end())
#define sortg(k)     sort(k.begin(),k.end(),greater<int>())
#define uniq(vec)    vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())))
#define rev(k)       reverse(k.begin(),k.end())
#define umin(a,b)    a=min(a,b)
#define umax(a,b)    a=max(a,b)
#define min3(a,b,c)  min(a, min(b,c))
#define pyes         cout<<"Yes"<<endl
#define pno          cout<<"No"<<endl
#define pf(a)        cout<<a<<endl
#define p2f(a,b)     cout<<a<<" "<<b<<endl
#define p3f(a,b,c)   cout<<a<<" "<<b<<" "<<c<<endl
#define p4f(a,b,c)   cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl
#define ff first
#define ss second
#define pb push_back
#define pi acos(-1.0)
//cin.get();
typedef long long int ll;
//typedef unsigned long long int llu;
//constexpr llu Mx=18446744073709551615;
constexpr ll MOD=1e9+7;
const int limit=1e5+5;

/// sending the string only.
// returns the index from where lexographically smallest string starts
int minlex(string s){

    int len = s.size();

    int n = 2 * len , i = 0 , j = 1 , k = 0;

    int a , b;

    while(i + k < n &&  j + k < n){

        a = (i + k >= len) ? s[i + k - len] : s[i + k];
        b = (j + k >= len) ? s[j + k - len] : s[j + k];

        if(a == b) k++;

        else if(a > b){
            i = i + k + 1;
            if(i <= j) i = j + 1;
            k = 0;
        }
        else{
            j = j + k + 1;
            if(j <= i) j = i + 1;
            k = 0;
        }

    }

    return min(i , j);


}

void an1nd1ta(int tc){
    
    string s;
    cin >> s;

    int h = minlex(s);
    
    int n = s.size();

    s += s;
    
    cout << s.substr(h,n) <<endl;

    return;
}

int main(){
    fast;
    int testcase=1;
    //cin >> testcase;
    for(int T=1;T<=testcase;T++) an1nd1ta(T);
    return 0;
}