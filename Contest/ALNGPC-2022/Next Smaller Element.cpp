#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e2+5;

int main(){
    fast;

    ll n,q;
    cin>>n>>q;
    vector<ll>a(n*2);

    for(int i=0;i<n;i++) cin>>a[i];

    for(int i=n,j=0;i<2*n;i++,j++) a[i]=a[j]+1;

    stack<ll>st;
    vector<ll>right(2*n);

    for(int i=2*n-1;i>=0;i--){

        if(st.size()==0){
            right[i]=-1;
        }

        else if(st.size()!=0  &&  st.top() < a[i]){
            right[i]=st.top();
        }

        else if(st.size()!=0  &&  st.top() >= a[i]){

            while(st.size()>0  &&  st.top() >= a[i]){
                st.pop();
            }

            if(st.size()==0) {
                right[i]=-1;
            }

            else if(st.top() < a[i]){
                right[i]=st.top();
            }
        }
        st.push(a[i]);
    }

    while(q--){

        ll x;
        cin>>x;
        x--;

        ll main_x=x%n;

        ll add=x/n;

        if(right[main_x]==-1) cout<<-1<<endl;
        else{
            cout<<right[main_x]+add<<endl;
        }

    }

    return 0;
}



