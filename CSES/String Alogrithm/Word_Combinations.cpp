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
const int limit=5e3+5;

ll  dp[limit];
struct Trienode{
	
	struct Trienode *child[26];
	bool isEnd;

	Trienode(){
		isEnd = false;
		for(int i=0;i<26;i++) {
			child[i] = NULL;
		}
	}
};
Trienode *root;

void Insert(string p){

	Trienode *node = root;
	int n = p.size();

	for(int i=0;i<n;i++){

		int idx = p[i]-'a';

		if(node->child[idx] == NULL){

			node->child[idx] = new Trienode();  /// create a new child
		}

		node = node->child[idx];

	}

	node->isEnd = true;

}


void an1nd1ta(int tc){
    
    root = new Trienode();

    int n , k;
    string s;
    cin >> s >> k;

    for(int i=0;i<k;i++){

    	string p;
    	cin >> p;

    	Insert(p);
    }
 	n = s.size();
 	
 	///base condition
    dp[n] = 1;

    for(int i=n-1;i>=0;i--){

    	Trienode *node = root;

    	for(int j=i;j<n;j++){

    		int idx = s[j]-'a';

    		if(node->child[idx] == NULL){
    			break;
    		}

    		node = node->child[idx];

    		if(node->isEnd == true){

    			dp[i] = (dp[i] + dp[j+1]) % MOD;

    		}

    	}

    }
    cout << dp[0] <<endl;

    return;
}

int main(){
    fast;
    int testcase=1;
    //cin >> testcase;
    for(int T=1;T<=testcase;T++) an1nd1ta(T);
    return 0;
}