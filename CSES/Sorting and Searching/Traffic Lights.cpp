#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long int ll;
typedef unsigned long long int llu;

constexpr ll mod=1e9+7;
const int limit=2e5+5;


int main(){
    fast;
    int x,n;
    cin>>x>>n;
    set<int>position;
    multiset<int>len;

    position.insert(0);
    position.insert(x);
    len.insert(x);

    while(n--){

        int p;
        cin>>p;
        position.insert(p);

        auto pos=position.find(p);

        int prevval=*prev(pos);
        int nextval=*next(pos);

        int lenght=nextval-prevval;

        len.erase(len.find(lenght));

        len.insert(p-prevval);
        len.insert(nextval-p);

        cout<<*len.rbegin()<<endl;


    }


    return 0;
}





