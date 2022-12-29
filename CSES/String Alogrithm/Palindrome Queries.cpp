#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll MOD=1e9+7;
const int limit=2e5+5;

string s;
ll forword_hash[limit << 2];
ll reverse_hash[limit << 2];
ll base_power[limit] , inv_p[limit];
ll base = 31;
int n , q;

int get_char(char c){
    return c-'a'+1;
}

void forword_hash_tree(int node,int b,int e){

    if(b==e){
        forword_hash[node]=((ll)get_char(s[b])*base_power[b-1])%MOD;
        return;
    }

    int mid=(b+e)/2;

    forword_hash_tree( node << 1, b, mid );
    forword_hash_tree( node << 1 | 1, mid+1, e );

    forword_hash[node]= ( forword_hash[node << 1] + forword_hash[node << 1 | 1] ) % MOD;

}

void reverse_hash_tree(int node,int b,int e){

    if(b==e){
        reverse_hash[node]=((ll)get_char(s[b])*base_power[n-b]) % MOD;
        return;
    }

    int mid=(b+e)/2;

    reverse_hash_tree( node << 1, b, mid );
    reverse_hash_tree( node << 1 | 1, mid+1, e );

    reverse_hash[node]= ( reverse_hash[node << 1] + reverse_hash[node << 1 | 1] ) % MOD;

}

void forword_hash_update(int node,int b,int e,int k){

    if(b==e){
        forword_hash[node]=((ll)get_char(s[b])*base_power[b-1]) % MOD;
        return;
    }

    int mid=(b+e)/2;

    if(k<=mid) forword_hash_update(node << 1, b, mid, k);
    else forword_hash_update(node << 1 | 1 ,mid+1, e, k);

    forword_hash[node]= ( forword_hash[node << 1] + forword_hash[node << 1 | 1] ) % MOD;
}

void reverse_hash_update(int node,int b,int e,int k){

    if(b==e){
        reverse_hash[node]=((ll)get_char(s[b])*base_power[n-b]) % MOD;
        return;
    }

    int mid=(b+e)/2;

    if(k<=mid) reverse_hash_update(node << 1, b, mid, k);
    else reverse_hash_update(node << 1 | 1 ,mid+1, e, k);

    reverse_hash[node]= ( reverse_hash[node << 1] + reverse_hash[node << 1 | 1] ) % MOD;
}

ll forword_hash_answer(int node,int b,int e,int l,int r){

    if(l>e || r<b)
        return 0;

    if(b>=l && e<=r)
        return forword_hash[node] % MOD;


    int mid=(b+e)/2;

    return (forword_hash_answer(node << 1 , b, mid, l, r) + forword_hash_answer(node << 1 | 1, mid+1, e, l ,r)) % MOD;
}

ll reverse_hash_answer(int node,int b,int e,int l,int r){

    if(l>e || r<b)
        return 0;

    if(b>=l && e<=r)
        return reverse_hash[node] % MOD;


    int mid=(b+e)/2;

    return (reverse_hash_answer(node << 1 , b, mid, l, r) + reverse_hash_answer(node << 1 | 1, mid+1, e, l ,r)) % MOD;
}

ll bigmod(ll a,ll p){

	ll res=1;
	while(p){

	    if(p & 1){
            res=(res*a)%MOD;
	    }
	    a=(a*a)%MOD;
	    p = (p >> 1);
	}
	return res%MOD;
}



int main(){
    fast;

    cin >> n >> q >> s;

    s = "?" + s;

    base_power[0] = 1 , inv_p[0] = 1;

    for(int i=1;i<=n;i++){
        base_power[i] = (1LL * base_power[i-1] * base) % MOD;
    }
    for(int i=1;i<=n;i++){
        inv_p[i] = bigmod(base_power[i],MOD-2LL);
    }

    forword_hash_tree(1,1,n);
    reverse_hash_tree(1,1,n);

    while(q--){

        int type;
        cin >> type;
        if(type == 1){
            int k ;
            char x;
            cin >> k >> x;
            s[k] = x;
            forword_hash_update(1,1,n,k);
            reverse_hash_update(1,1,n,k);
        }
        else{

            int a,b;
            cin >> a  >> b;

            //cout << s.substr(a,b-a+1) <<endl;

            ll for_answer = ((forword_hash_answer(1,1,n,a,b)*inv_p[a-1])%MOD+MOD)%MOD;
            ll rev_answer = ((reverse_hash_answer(1,1,n,a,b)*inv_p[n-b])%MOD+MOD)%MOD;

            if(for_answer == rev_answer){
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;

        }

    }
    return 0;
}


