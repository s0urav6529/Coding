#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

using namespace __gnu_pbds;
template<typename T>
using ordered_set=tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;

using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
#define sz(x) int((x).size())
#define rep(j,i,k) for (int i=j ; i<k ; i++)
#define reset(a,b)   memset(a, (b), sizeof(a))
#define sortv(k)     sort(k.begin(),k.end())
#define sortg(k)     sort(k.begin(),k.end(),greater<int>())
#define rev(k)       reverse(k.begin(),k.end())
#define umin(a,b)    a=min(a,b)
#define umax(a,b)    a=max(a,b)
#define min3(a,b,c)  min(a, min(b,c))
#define pyes         cout<<"Yes"<<endl
#define pno          cout<<"No"<<endl
#define pfp(x,y)     cout<<fixed<<setprecision(y)<<x<<endl;
#define pf(a)         cout<<a<<endl;
#define ppf(a,b)      cout<<a<<" "<<b<<endl;
#define pppf(a,b,c)   cout<<a<<" "<<b<<" "<<c<<endl;
#define nl           endl;
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define mpr make_pair
#define pi acos(-1.0)
//cin.get();
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
constexpr ll imax=1e9;
constexpr ll imin=-1e9;
constexpr ll MOD=998244353;
const int limit=100005;

void init_code(){

    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    #endif

}

struct Trie{

    int val;
    Trie* child[2];

};

Trie* create(){

    Trie* temp=new Trie;
    temp->val=0;
    temp->child[0]=temp->child[1]=NULL;
    return temp;
}

void Insert(Trie* root,int num){

    Trie* cur=root;

    for(int i=29;i>=0;i--){

        bool b=(num&(1<<i));

        if(cur->child[b]==NULL)
            cur->child[b]=create();

        cur=cur->child[b];
    }
    cur->val=num;
}


int MaxSubarray(Trie* root,int num){


    Trie* cur=root;

    for(int i=29;i>=0;i--){

        bool b=(num&(1<<i));

        if(cur->child[!b]!=NULL)
            cur=cur->child[!b];
        else cur=cur->child[b];
    }
    return num^(cur->val);
}



void run_case(){
    Trie* root; root=create();  Insert(root,0);
    int n,ans=0;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int Xor=0;
    for(int i=0;i<n;i++){
        Xor^=a[i];
        Insert(root,Xor);
    }
    Xor=0;
    for(int i=0;i<n;i++){
        Xor^=a[i];
        ans=max(ans,MaxSubarray(root,Xor));
    }
    cout<<ans<<endl;

    return;
}

int main(){
    fast;
    int tc=1;
    cin>>tc;
    while(tc--) run_case();
    return 0;
}


