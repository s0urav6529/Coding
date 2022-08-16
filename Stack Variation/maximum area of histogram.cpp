#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int limit=105;
vector<int>a(limit);
vector<int>l;
vector<int>r;
stack<pair<int,int>>sl;
stack<pair<int,int>>sr;
int n;

void solveleft(){

    for(int i=1;i<=n;i++){

        if(sl.size()==0) {
            l.push_back(0);
        }
        else if(sl.size()>0  &&  sl.top().first < a[i]){
            l.push_back(sl.top().second);
        }
        else if(sl.size()>0  &&  sl.top().first >= a[i]){

            while(sl.size()>0  &&  sl.top().first >= a[i]){
                sl.pop();
            }
            if(sl.size()==0){
                l.push_back(0);
            }
            else if(sl.size()>0  &&  sl.top().first < a[i]){
                l.push_back(sl.top().second);
            }
        }
        sl.push({a[i],i});
    }
}
void solveright(){

    for(int i=n-1;i>=0;i--){

        if(sr.size()==0){
            r.push_back(n+1);
        }
        else if(sr.size()>0  &&  sr.top().first < a[i]){
            r.push_back(sr.top().second);
        }
        else if(sr.size()>0  &&  sr.top().first >= a[i]){

            while(sr.size()>0  &&  sr.top().first >= a[i]){
                sr.pop();
            }
            if(sr.size()==0) {
                r.push_back(n);
            }
            else if(sr.size()>0  &&  sr.top().first < a[i]){
                r.push_back(sr.top().second);
            }
        }
        sr.push({a[i],i});
    }
    reverse(r.begin(),r.end());
}

int main(){

    fast;
    int mx=1e9;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    solveleft();
    solveright();

    for(int i=1;i<=n;i++){
        mx=max(mx,((r[i]-l[i]-1)*a[i]));
    }
    cout<<mx<<endl;
    return 0;
}


