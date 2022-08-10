
///Problem Link : https://cses.fi/problemset/task/2168


#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
namespace __gnu_pbds{
          typedef tree<int,
                       null_type,
                       less_equal<int>,
                       rb_tree_tag,
                       tree_order_statistics_node_update> ordered_set;
}
using namespace __gnu_pbds;


#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long int ll;

const int limit=2e5+5;


int Value(ordered_set &s,int idx){
   return (*s.find_by_order(idx));
}

int FirstIdx(ordered_set &s,int x){
    return (s.order_of_key(x));
}

int LastIdx(ordered_set &s,int x){

    if(Value(s,(int)s.size()-1)==x){
        return (int)(s.size())-1;
    }
    return FirstIdx(s,*s.lower_bound(x))-1;
}

int Size(ordered_set &s){
     return (int)(s.size());
}

void Clear(ordered_set &s){
     s.clear();
}
void Insert(ordered_set &s,int x){
     s.insert(x);
}


bool compair(pair<pair<int,int>,int>a,pair<pair<int,int>,int>b){

    if(a.first.first==b.first.first) return a.first.second>b.first.second;
    return a.first.first<b.first.first;
}


int main(){
    fast;
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>>v(n);

    for(int i=0;i<n;i++){
        cin>>v[i].first.first>>v[i].first.second;

        v[i].second=i;
    }

    sort(v.begin(),v.end(),compair);

    ordered_set s;
    vector<int>a(n,0),b(n,0);

    for(int i=n-1;i>=0;i--){

        int right=v[i].first.second;
        int idx=v[i].second;

        Insert(s,right);

        int pos=LastIdx(s,right);

        a[idx]=pos;
    }
    Clear(s);

    for(int i=0;i<n;i++){

        int right=v[i].first.second;
        int idx=v[i].second;

        Insert(s,right);

        int pos=FirstIdx(s,right);

        b[idx]=Size(s)-(pos+1);

    }

    for(int i=0;i<n;i++){
        if(a[i]) a[i]=1;
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        if(b[i]) b[i]=1;
        cout<<b[i]<<" ";
    }
    cout<<endl;
    return 0;
}




