#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define read freopen ("in.txt","r",stdin);
#define out freopen ("out.txt","w",stdout);
#define sz(x) int((x).size())
#define rep0(i,k) for (int i=0 ; i<k ; i++)
#define rep(i,k)  for (int i=1 ; i<=k ; i++)
#define reset(a,b)   memset(a, (b), sizeof(a))
#define sortv(k)     sort(k.begin(),k.end())
#define sortg(k)     sort(k.begin(),k.end(),greater<int>())
#define rev(k)       reverse(k.begin(),k.end())
#define umin(a,b)    a=min(a,b)
#define umax(a,b)    a=max(a,b)
#define min3(a,b,c)  min(a, min(b,c))
#define pyes         cout<<"Yes"<<endl
#define pno          cout<<"No"<<endl
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define mpr make_pair
#define pi acos(-1.0)
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
constexpr ll imax=1e9;
constexpr ll imin=-1e9;
constexpr ll MOD=1e9+7;
const int limit=100002;

vector<int>parent(limit,-1);
vector<int>Rank(limit,0); ///rank means size of this cc

string s="0";
int ans=0;

int find(int a){

    if(parent[a]<0) return a;

    return parent[a]=find(parent[a]);

}

void Union(int root,int l,int r){

    if(s[l]=='1'){
        root=find(root);
        l=find(l);
        if(root!=l){

            if(Rank[l]>Rank[root]) swap(root,l);
            parent[l]=root;
            Rank[root]+=Rank[l];
            ans=max(ans,Rank[root]);
        }
    }
    if(s[r]=='1'){

        root=find(root);
        r=find(r);
        if(root!=r){

            if(Rank[r]>Rank[root]) swap(r,root);
            parent[r]=root;
            Rank[root]+=Rank[r];
            ans=max(ans,Rank[root]);
        }
    }
}

void solution(){

    int n,q;
    string p;
    cin>>n>>q>>p;
    p+="0";
    s+=p;

    for(int i=1;i<=n;i++){
        if(s[i]=='1') Rank[i]=1;
        ans=max(ans,Rank[i]);
    }

    for(int i=1;i<=n;i++){

        if(s[i]=='1'){
            Union(i,i-1,i+1);
        }

    }
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            cout<<ans<<endl;
        }
        else{
            int x;
            cin>>x;
            if(s[x]=='0'){
                s[x]='1';
                Rank[x]=1;
                ans=max(ans,Rank[x]);
                Union(x,x-1,x+1);
            }
        }
    }
    return;
}
int main()
{
    fast;
    //read;
    //out;
    int tc=1;
    //cin>>tc;
    while(tc--) solution();
    return 0;
}



