#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//#define pb push_back ;
#define mpr make_pair ;
#define mod 1000000007;
#define pi acos(-1.0);
#define mx INT_MIN
#define mn INT_MAX
#define ff first;
#define ss second;
#define inf 1e9
#define linf 1e18
#define eps 1e-9
#define el endl;
using namespace std;
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main(){

    fast;
    int n;
    cin>>n;
    vector<int>a(n+1);

    for(int i=1;i<=n;i++)
        cin>>a[i];

    stack<pair<int,int>>st; ///value & position
    vector<int>left;

    for(int i=1;i<=n;i++){

        if(st.size()==0){
            left.push_back(0);
        }
        else if(st.size()!=0  &&  st.top().first < a[i]) {
            left.push_back(st.top().second);
        }
        else if(st.size()!=0  &&  st.top().first >= a[i]) {

            while(st.size()>0  &&  st.top().first >= a[i]) {
                st.pop();
            }
            if(st.size()==0){
                left.push_back(0);
            }
            else if(st.top().first < a[i]){
                left.push_back(st.top().second);
            }
        }
        st.push({a[i],i});
    }
    for(auto i:left) cout<<i<<" ";
    cout<<endl;
    return 0;
}


