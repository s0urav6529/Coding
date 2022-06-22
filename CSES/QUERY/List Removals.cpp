#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;

namespace __gnu_pbds{
          typedef tree<int,
                       null_type,
                       less_equal<int>,
                       rb_tree_tag,
                       tree_order_statistics_node_update> ordered_set;
}
using namespace __gnu_pbds;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


void Insert(ordered_set &s,int x){

     s.insert(x);

}
bool Exist(ordered_set &s,int x){

     if((s.upper_bound(x))==s.end()){
        return 0;
     }
     return ((*s.upper_bound(x))==x);

}


void Erase(ordered_set &s,int x){

     if(Exist(s,x)){
        s.erase(s.upper_bound(x));
     }

}


int FirstIdx(ordered_set &s,int x){

    if(!Exist(s,x)){
        return -1;
    }
    return (s.order_of_key(x));

}


int Value(ordered_set &s,int idx){

   return (*s.find_by_order(idx));

}


int LastIdx(ordered_set &s,int x){

    if(!Exist(s,x)){
        return -1;
    }
    if(Value(s,(int)s.size()-1)==x){
        return (int)(s.size())-1;
    }
    return FirstIdx(s,*s.lower_bound(x))-1;

}


int Count(ordered_set &s,int x){

     if(!Exist(s,x)){
        return 0;
     }
     return LastIdx(s,x)-FirstIdx(s,x)+1;

}


void Clear(ordered_set &s){

     s.clear();

}


int Size(ordered_set &s){

     return (int)(s.size());
}



int main(){
    fast;
    int n;
    cin>>n;
    map<int,int>mp;
    ordered_set s;
    int x=1;
    for(int i=1;i<=n;i++) {
        int y;cin>>y;
        mp[x]=y;
        Insert(s,x);
        x++;
    }
    for(int i=1;i<=n;i++){

        int y;cin>>y;
        int val=Value(s,y-1);
        cout<<mp[val]<<" ";
        Erase(s,val);
    }
    cout<<endl;
    return 0;
}


