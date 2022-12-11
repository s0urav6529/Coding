


/// In this problem we need to find minimum Index where query wanted sum larger than prefix sum of this minimum index. 


#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

typedef long long int ll;
typedef unsigned long long int llu;
constexpr ll mod=1e9+7;
const int limit=1e5+5;


int a[limit];
int BIT[limit];

void update(int index,int val,int n){

    while(index <= n){

        BIT[index] += val;
        index += (index & -index);

    }
}

int answer(int index){

    int sum = 0;

    while(index > 0){

        sum += BIT[index];
        index -= (index & -index);
    }
    return sum;
}

int main(){
    fast;
    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        update(i,a[i],n);
    }

    while(q--){

        string s;
        cin>>s;

        if(s=="add"){     /// Adding something to this position
            ll pos,add;

            cin>> pos >> add;

            a[pos] += add;

            update(pos , add , n);
        }
        else if(s=="assign"){   /// Assign value to this position
            ll pos,val;

            cin>>pos >> val;

            update( pos, -a[pos] , n); ///clear first

            update(pos , val , n ); /// assign now

            a[pos]=val;
        }
        else {
            ll qsum;

            cin>>qsum;

            ll cur_jump=0 , cursum=0;

            for(int jump=20; jump >= 0 ;jump--){

                ll next_jump = cur_jump + (1 << jump);

                if(next_jump <= n && (cursum + BIT[next_jump]) < qsum){

                    cur_jump = next_jump;

                    cursum += BIT[next_jump];
                }

            }
            cout<<cur_jump<<endl;
        }

    }


    return 0;
}


