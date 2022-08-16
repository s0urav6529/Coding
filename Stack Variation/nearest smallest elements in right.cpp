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
    vector<int>right;

    for(int i=n;i>=1;i--){

        if(st.size()==0){
            right.push_back(n+1);
        }
        else if(st.size()!=0  &&  st.top().first < a[i]){
            right.push_back(st.top().second);
        }
        else if(st.size()!=0  &&  st.top().first >= a[i]){

            while(st.size()>0  &&  st.top().first >= a[i]){
                st.pop();
            }
            if(st.size()==0) {
                right.push_back(n+1);
            }
            else if(st.top().first < a[i]){
                right.push_back(st.top().second);
            }
        }
        st.push({a[i],i});
    }
    reverse(right.begin(),right.end());
    for(auto i:right) cout<<i<<" ";
    cout<<endl;
    return 0;
}

