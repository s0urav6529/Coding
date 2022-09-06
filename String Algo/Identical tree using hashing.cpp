
///CHECKING TWO TREE IDENTICAL OR NOT USING HASING

/// FORMULA FOR EVERY NODE HASING VALUE = ( SIZE_OF_SUBTREE * BASE^LEVEL_OF_NODE + HASH VALUE OF CHILDS OF THIS NODE )

/// THEN CHECK HASH VALUE OF EACH NODE

#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=1e2+5;

vector<ll> adj1[limit] , adj2[limit];
vector<ll> hash_value1(limit) , hash_value2(limit);
vector<ll> sub_size1(limit) , sub_size2(limit);

ll base = 31;

ll Mod(ll x){
    return ((x%MOD + MOD)%MOD);
}


ll mulmod(ll a,ll b){
    return Mod(Mod(a)*Mod(b));
}

ll Binary_expo(ll a,ll p){
	ll res=1;
	while(p){

		if(p&1)
		res=mulmod(res,a);

		p/=2;
		a=mulmod(a,a);
	}
	return res%MOD;
}

void dfs1(int node, int par, ll lev){

    sub_size1[node]=1;

    ll child_hash=0;

    for(int ch: adj1[node]){

        if(ch != par){

            dfs1(ch , node , lev+1);
            sub_size1[node] += sub_size1[ch];

            child_hash = (child_hash + hash_value1[ch]) % MOD;
        }
    }

    hash_value1[node] = ((sub_size1[node] * Binary_expo(base, lev)) % MOD + child_hash) % MOD;

}

void dfs2(int node, int par, ll lev){

    sub_size2[node]=1;

    ll child_hash=0;

    for(int ch: adj2[node]){

        if(ch != par){

            dfs2(ch , node , lev+1);
            sub_size2[node] += sub_size2[ch];

            child_hash = (child_hash + hash_value2[ch]) % MOD;
        }
    }

    hash_value2[node] = ((sub_size2[node] * Binary_expo(base, lev)) % MOD + child_hash) % MOD;

}

int main(){
    fast;

    ll tc=1;
    cin >> tc;

    while(tc --){

        ll n , m;
        cin >> n >> m;

        for(int i = 0 ;i <= max(n,m) ; i++) {

            adj1[i].clear();
            adj2[i].clear();

            hash_value1[i] = hash_value2[i] = 0;
            sub_size1[i] = sub_size2[i] = 0;
        }

        for(int i = 1; i < n ;i++){
            int u,v;
            cin >> u >> v;
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }

        for(int i = 1; i < m ;i++){
            int u,v;
            cin >> u >> v;
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }

        if(n!=m){
            cout<< "Not Identical" <<endl;
            continue;
        }

        dfs1(1,0,1);
        dfs2(1,0,1);

        if(hash_value1[1] == hash_value2[1]){
            cout<< "Identical" <<endl;
        }
        else cout<< "Not Identical" <<endl;
    }

    return 0;

}


