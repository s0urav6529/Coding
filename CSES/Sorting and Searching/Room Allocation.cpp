#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define sortv(k)     sort(k.begin(),k.end())
#define ff first
#define ss second



void run_case(){

    int n;
    cin>>n;
    multiset<pair<int,int>>ms;

    int tr=0,rn=1;
    vector<pair<pair<int,int>,int>>c(n);
    for(int  i=0;i<n;i++) {
        cin>>c[i].ff.ff>>c[i].ff.ss;
        c[i].ss=i;
    }
    sortv(c);
    vector<int>ans(n);
    for(int i=0;i<n;i++){

        int a=c[i].ff.ff,d=c[i].ff.ss,id=c[i].ss;

        if(ms.size()==0){
            ms.insert({d,rn});
            ans[id]=rn;
            rn++;
        }
        else{
            pair<int,int>p=*ms.begin();

            if(p.ff<a){
                int put=p.ss;
                ms.erase(ms.begin());
                ms.insert({d,put});
                ans[id]=put;
            }
            else {
                ms.insert({d,rn});
                ans[id]=rn;
                rn++;
            }
        }
        tr=max(tr,(int)ms.size());
    }
    cout<<tr<<endl;
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    cout<<endl;
    return;
}

int main(){
    fast;
    run_case();
    return 0;
}



